#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/* Калинин Глеб (23531/21-1)
 *
 *
 * Разработать программу, которая, используя только стандартные алгоритмы и функторы,
 * умножает каждый элемент списка чисел с плавающей  точкой на число PI
 */

class Mult {
public:
    Mult():n(0),res(0) {};

    void operator() (float n) {
        res = n * M_PI;
        cout << res << " ";
    }

    float getRes() {
        return res;
    }


private:
    float n,res;
};


int main() {
    vector<float> vec;

    // Заполнение вектора:
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 0.1);
    }

    cout << "Исходный список:\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

    // Умножение каждого элемента списка на число Пи
    cout << "Новый список\n";
    (for_each(vec.begin(), vec.end(), Mult())).getRes();

    return 0;
}