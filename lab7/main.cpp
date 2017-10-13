#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Калинин Глеб (23531/21-1)
 *
 *
Разработать функтор, позволяющий собирать статистику о последовательности целых чисел (послед может содержать числа от -500 до 500).
Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику:
- Максимальное число в последовательности
- Минимальное число в последовательности
- Среднее число в последовательности
- Количество положительных чисел
- Количество отрицательных чисел
- Сумму нечетных элементов последовательности
- Сумму четных элементов последовательности
- Совпадают ли первый и последний элементы последовательности.

Проверить работу программы на случайно сгенерированных последовательностях.
 */


class statistic
{
public:
    statistic():n(0), max(0), min(getMax()), sum(0), count(0), nPos(0), nNeg(0), sumOdd(0), sumEven(0), first(0), last(0) {}

    void operator() (int n) {
        // Макс:
        if (n >= max)
            max = n;
        // Мин:
        if (n <= min)
            min = n;
        // Ср-ее число:
        sum += n;
        count++;
        // Кол-во пол. чисел:
        if (n >= 0)
            nPos++;
        // Кол-во отриц. чисел:
        if (n < 0)
            nNeg++;
        // Сумма нечетных элементов:
        if (n % 2 != 0)
            sumOdd += n;
        // Сумма четных элементов:
        if (n % 2 == 0)
            sumEven += n;
        // Первый элемент:
        first = n;
        // Последний элемент:
        last = n;
    }


    int getMax() {
        return max;
    }
    int getMin() {
        return min;
    }
    double getAverage() {
        return static_cast<double>(sum)/static_cast<double>(count);
    }
    int getNPos() {
        return nPos;
    }
    int getNNeg() {
        return nNeg;
    }
    int getSumOdd() {
        return sumOdd;
    }
    int getSumEven() {
        return sumEven;
    }
    int getFirst() {
        return first;
    }
    int getLast() {
        return last;
    }

private:
    int n, max, min, sum, count, nPos, nNeg, sumOdd, sumEven, first, last;
};

int main() {
    vector<int> vec;
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        vec.push_back(rand() % 1000 + (-500));
    }

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << "\n";

    // Максимальное число в последовательности:
    int max = (for_each(vec.begin(), vec.end(), statistic())).getMax();
    cout << "Максимальное число в последовательности: " << max << "\n";

    // Минимальное число в последовательности:
    int min = (for_each(vec.begin(), vec.end(), statistic())).getMin();
    cout << "Минимальное число в последовательности: " << min << "\n";

    // Среднее значение в последовательности:
    double avg = (for_each(vec.begin(), vec.end(), statistic())).getAverage();
    cout << "Среднее значение в последовательности: " << avg << "\n";

    // Количество положительных чисел:
    int nPos = (for_each(vec.begin(), vec.end(), statistic())).getNPos();
    cout << "Количество положительных чисел: " << nPos << "\n";

    // Количество отрицательных чисел:
    int nNeg = (for_each(vec.begin(), vec.end(), statistic())).getNNeg();
    cout << "Количество отрицательных чисел: " << nNeg << "\n";

    // Сумма нечетных чисел:
    int nSumOdd = (for_each(vec.begin(), vec.end(), statistic())).getSumOdd();
    cout << "Сумма нечетных чисел: " << nSumOdd << "\n";

    // Сумма четных чисел:
    int nSumEven = (for_each(vec.begin(), vec.end(), statistic())).getSumEven();
    cout << "Сумма четных чисел: " << nSumEven << "\n";

    // Первый элемент:
    int first = (for_each(vec.begin(), vec.begin()+1, statistic())).getFirst();
    cout  << "Первый элемент: " << first << "\n";

    // Последний элемент:
    int last = (for_each(vec.end()-1, vec.end(), statistic())).getLast();
    cout  << "Последний элемент: "<< last << "\n";

    // Совпадают ли первый и последний элементы:
    bool isEq = false;
    if (first == last)
        isEq = true;
    cout << "Первый и последний элемент совпадают? " << isEq << "\n";

    return 0;
}

