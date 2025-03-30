/*���� ������ ���� ���� 36 ������ ��������� ����� ������� 6x6. ��������. */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>

using namespace std;

const n = 6;        //����� ��������� �����

int x[n * n + 1];       //����� ����������� �� k-� ����, 1<=k<=n*n, 1<=x[k]<=n 
int y[n * n + 1];       //����� ����������� �� k-� ����, 1<=k<=n*n, 1<=y[k]<=n 
bool r[n * n + 2];      //r[p[k]]==true = ������ ������ � ������� p[k]=n*(x[k]-1)+y[k] �� k-� ����, 1<=k<=n*n
FILE* f;            //���� ��� �������� ����������
float time1;        //����� ������ ������
float time2;        //����� ���������� ���������� ������� 
int u;              //����� �������
double c;           //���������� �����
char fileout[15];   //��� ����� ��� �������� ����������

void chessknight(int k);  //������� ������ ���� ������� ��� ������ ��������
void print();             //����� ������� � ����
void input();             //���� ������
void output();            //���������� ������   

int main()
{
    input();
    float time1 = clock();
    u = 0;
    c = 0;
    r[n * (x[1] - 1) + y[1]] = true;
    chessknight(1);
    output();
    getch();
    return 0;
}

void chessknight(int k)
{
    c++;
    if (k == n * n)    print();
    if ((r[n * x[k] + y[k] + 2] == false) && (x[k] <= n - 1) && (y[k] <= n - 2))
    {
        r[n * x[k] + y[k] + 2] = true;
        x[k + 1] = x[k] + 1;
        y[k + 1] = y[k] + 2;
        chessknight(k + 1);
    }
    if ((r[n * (x[k] + 1) + y[k] + 1] == false) && (x[k] <= n - 2) && (y[k] <= n - 1))
    {
        r[n * (x[k] + 1) + y[k] + 1] = true;
        x[k + 1] = x[k] + 2;
        y[k + 1] = y[k] + 1;
        chessknight(k + 1);
    }
    if ((r[n * (x[k] + 1) + y[k] - 1] == false) && (x[k] <= n - 2) && (y[k] >= 2))
    {
        r[n * (x[k] + 1) + y[k] - 1] = true;
        x[k + 1] = x[k] + 2;
        y[k + 1] = y[k] - 1;
        chessknight(k + 1);
    }
    if ((r[n * x[k] + y[k] - 2] == false) && (x[k] <= n - 1) && (y[k] >= 3))
    {
        r[n * x[k] + y[k] - 2] = true;
        x[k + 1] = x[k] + 1;
        y[k + 1] = y[k] - 2;
        chessknight(k + 1);
    }
    if ((r[n * (x[k] - 2) + y[k] - 2] == false) && (x[k] >= 2) && (y[k] >= 3))
    {
        r[n * (x[k] - 2) + y[k] - 2] = true;
        x[k + 1] = x[k] - 1;
        y[k + 1] = y[k] - 2;
        chessknight(k + 1);
    }
    if ((r[n * (x[k] - 3) + y[k] - 1] == false) && (x[k] >= 3) && (y[k] >= 2))
    {
        r[n * (x[k] - 3) + y[k] - 1] = true;
        x[k + 1] = x[k] - 2;
        y[k + 1] = y[k] - 1;
        chessknight(k + 1);
    }
    if ((r[n * (x[k] - 3) + y[k] + 1] == false) && (x[k] >= 3) && (y[k] <= n - 1))
    {
        r[n * (x[k] - 3) + y[k] + 1] = true;
        x[k + 1] = x[k] - 2;
        y[k + 1] = y[k] + 1;
        chessknight(k + 1);
    }
    if ((r[n * (x[k] - 2) + y[k] + 2] == false) && (x[k] >= 2) && (y[k] <= n - 2))
    {
        r[n * (x[k] - 2) + y[k] + 2] = true;
        x[k + 1] = x[k] - 1;
        y[k + 1] = y[k] + 2;
        chessknight(k + 1);
    }
    r[n * (x[k] - 1) + y[k]] = false;
    x[k] = 1;
    y[k] = 0;
    c++;
}

void print()
{
    u++;
    float time2 = clock();
    printf("�������  %6d �������. ����� ������ = %3.3f  �\n", u, (time2 - time1) / 1000);
    f = fopen(fileout, "a");
    fprintf(f, "The solution %6d,  step = %e,  time = %3.3f s:\n", u, c, (time2 - time1) / 1000);
    for (int k = 1; k <= n * n; k++)  fprintf(f, "%2d  %c%d  %2d\n", k, x[k] + 96, y[k], n * (x[k] - 1) + y[k]);
    fprintf(f, "\n");
    fclose(f);
}

void input()
{
    cout << "���� ������ ���� ���� " << n * n << " ������ ��������� ����� ������� " << n << "x" << n << ". ��������\n";
    char x0;
    char y0;
    do
    {
        printf("������� ���� �� %d ����: a..%c:   ", n, 96 + n);
        cin >> x0;
    } while ((x0 < 'a') || (x0 > 96 + n));
    do
    {
        printf("������� ���� �� %d ����: 1..%c:   ", n, 48 + n);
        cin >> y0;
    } while ((y0 < '1') || (y0 > 48 + n));
    strcpy(fileout, "knight ");
    fileout[strlen(fileout) - 1] = n + 48;
    char v0[] = "  ";
    v0[0] = x0;
    v0[1] = y0;
    strcpy(fileout + strlen(fileout), v0);
    strcpy(fileout + strlen(fileout), "r.txt");
    time1 = clock();
    f = fopen(fileout, "w");
    fprintf(f, "This program use recursion.\n");
    fprintf(f, "The course of knight on chess board. \n");
    fprintf(f, "The chess board have size %dx%d, %d fields. \n", n, n, n * n);
    fprintf(f, "The knight occupy every fields only one times. \n\n");
    fclose(f);
    for (int k = 0; k <= n * n; k++) x[k] = 1;
    for (int k = 0; k <= n * n; k++) y[k] = 0;
    x[1] = x0 - 96;
    y[1] = y0 - 48;
    for (int k = 0; k <= n * n; k++) r[k] = false;
}

void output()
{
    float time2 = clock();
    printf("����� ������  =  %6.3f    �\n", (time2 - time1) / 1000);
    f = fopen(fileout, "a");
    fprintf(f, "The total time  =  %6.3f    seconds\n", (time2 - time1) / 1000);
    if (u == 0) fprintf(f, "There is no  solutions\n");
    else fprintf(f, "Numbers of solutions =  %d\n", u);
    fprintf(f, "The total numbers of steps =  %e\n", c);
    fclose(f);
    cout << "������� ����� ������� ����� ����: " << c << '\n';
    if (u == 0) cout << "������� ���\n";
    else cout << "������� ��������� � ����� " << fileout << '\n';
}
