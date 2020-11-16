#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

int sum_i(int a[], const int SIZE);
int kilkist_i(int a[], const int SIZE);
void zamina_i(int a[], const int SIZE);
int sum_r(int a[], const int i);
void zamina_r(int zam[], const int SIZE);
int kilkist_r(int a[], const int SIZE, int k);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int r;
    const int SIZE = 21;
    int a[SIZE];

    cout << "a[] = ";
    for (r = 0; r < 21; r++)
    {
        a[r] = 10 + rand() % 90;
        cout << a[r] << " ";
    }
    cout << endl;


    cout << "\nРекурсивний спосіб:" << endl;
    cout << "\nКількість вибраних елементів:" << kilkist_r(a, 0, 0) << endl;
    cout << "Сума вибраних елементів: " << sum_r(a, 0) << endl;
    cout << "Модифікований масив:";
    zamina_r(a, 0);

    return 0;
}

//рекурсивний спосіб
int sum_r(int* arr, int i)
{
    if (i == 20)
        return arr[i];
    else if (((arr[i] % 2) == 0) || ((arr[i] % 3) != 0))
        return arr[i] + sum_r(arr, i + 1);
    else
        sum_r(arr, i + 1);
}
int kilkist_r(int a[], const int SIZE, int k)
{
    if (((a[SIZE] % 2) == 0) || ((a[SIZE] % 3) != 0))
        k++;
    if (!(SIZE < 20))
        return k;
    else
        return kilkist_r(a, SIZE + 1, k);
}
void zamina_r(int zam[], const int SIZE)
{
    if (((zam[SIZE] % 2) == 0) || ((zam[SIZE] % 3) != 0))
        cout << 0 << "  ";
    else
        cout << zam[SIZE] << "  ";
    if (SIZE < 20)
        zamina_r(zam, SIZE + 1);
}