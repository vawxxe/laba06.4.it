
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 1. Введення масиву
void Create(double* x, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
}

// 2. Виведення масиву
void Print(const double* x, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << x[i];
    }
    cout << endl;
}

// 3. Пошук індексу елемента з найбільшим модулем
int MaxAbsIndex(const double* x, int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (fabs(x[i]) > fabs(x[index]))
        {
            index = i;
        }
    }

    return index;
}

// 4. Обчислення суми після першого додатного елемента
double SumAfterFirstPositive(const double* x, int n)
{
    int firstPositive = -1;

    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0)
        {
            firstPositive = i;
            break;
        }
    }

    double sum = 0;

    if (firstPositive != -1)
    {
        for (int i = firstPositive + 1; i < n; i++)
        {
            sum += x[i];
        }
    }

    return sum;
}

// 5. Перестановка елементів зі збереженням порядку
void Rearrange(double* x, int n, int a, int b)
{
    double* temp = new double[n];
    int k = 0;

    // Спочатку елементи, ціла частина яких у [a, b]
    for (int i = 0; i < n; i++)
    {
        int wholePart = static_cast<int>(floor(x[i]));

        if (wholePart >= a && wholePart <= b)
        {
            temp[k] = x[i];
            k++;
        }
    }

    // Потім усі інші елементи
    for (int i = 0; i < n; i++)
    {
        int wholePart = static_cast<int>(floor(x[i]));

        if (wholePart < a || wholePart > b)
        {
            temp[k] = x[i];
            k++;
        }
    }

    // Копіювання результату назад у масив
    for (int i = 0; i < n; i++)
    {
        x[i] = temp[i];
    }

    delete[] temp;
}

int main()
{
    int n, a, b;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Incorrect n!" << endl;
        return 1;
    }

    double* x = new double[n];

    cout << "Enter array elements:" << endl;
    Create(x, n);

    cout << "\nOriginal array:" << endl;
    cout << fixed << setprecision(2);
    Print(x, n);

    int maxIndex = MaxAbsIndex(x, n);
    cout << "\nIndex of maximum absolute value (0-based): "
        << maxIndex << endl;
    cout << "Position in array (1-based): " << maxIndex + 1 << endl;

    double sum = SumAfterFirstPositive(x, n);
    cout << "Sum after first positive element = " << sum << endl;

    cout << "\nEnter a: ";
    cin >> a;
    cout << "\nEnter b: ";
    cin >> b;

    if (a > b)
    {
        cout << "Incorrect interval!" << endl;
        delete[] x;
        return 1;
    }

    Rearrange(x, n, a, b);

    cout << "\nModified array:" << endl;
    Print(x, n);

    delete[] x;

    return 0;
}
