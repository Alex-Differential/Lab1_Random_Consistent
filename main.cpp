#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
int main(int argc, char* argv[]);
int LCRG_EVALUATE(int a, int b, int c, int x);

int main(int argc, char* argv[]) {
    // ���� �������� ������, �� P-������� ��������� ���� �����������
    // ���� ���� ����������� �� � ���� ��������
    int a, b, c, k, k_hi, u, v;
    time_t Start, Finish;
    
    double duration = 0;
    //������� ������������ �����
    k_hi = 40000000;
    
    cout << "    U = ( A * V + B ) mod C\n";//�������, �� ���� �������� ����������� ���������������� �����
    cout << "\n";

    //��������� �������-�������   
    a = 16807;
    b = 0;
    c = 2147483637;
        cout << "  LCRG parameters:\n";
        cout << "\n";
        cout << "  A  = " << a << "\n";
        cout << "  B  = " << b << "\n";
        cout << "  C  = " << c << "\n";
    
    //��������� ������ ����������� ���������������� ����� ����� ���������� 0  

    v = 12345;
    Start = clock();
    int* result = new int[k_hi];
    for (k = 1; k < k_hi; k++)
    {
        u = v;
        v = LCRG_EVALUATE(a, b, c, u);
        result[k - 1] = v;
        //cout << v << "\n";
    }
    Finish = clock();
    duration = double(Finish - Start)/ CLOCKS_PER_SEC;
    cout << "Time of consistent execution: " << duration;

    return 0;
}
//�������� ���� ������� ���������� y = ( A * x + B ) mod C �� ���� ���������� 
int LCRG_EVALUATE(int a, int b, int c, int x) {
    long long int aLong;
    long long int bLong;
    long long int cLong;
    long long int xLong;
    int y;
    long long int yLong;

    aLong = (long long int) a;
    bLong = (long long int) b;
    cLong = (long long int) c;
    xLong = (long long int) x;

    yLong = (aLong * xLong + bLong) % cLong;
    y = (int)yLong;

    if (y < 0) {
        y += c;
    }

    return y;
}
