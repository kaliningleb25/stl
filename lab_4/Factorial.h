//
// Created by Глеб Калинин on 17.09.17.
//

#include <vector>
using namespace std;
#ifndef LAB_4_FACTORIAL_H
#define LAB_4_FACTORIAL_H

typedef std::vector<int> vec;
typedef vec::iterator iter;

class Factorial {
public:
    // Конструктор
    Factorial(void);
    // Получение итератора, указывающего на первый элемент контейнера
    iter begin(void);
    // Получение итератора, указывающего на элемент, следующий за последним
    iter end(void);
    // Вычисление факториала числа
    int get_f(int n);
    // moving through #__container
    void operator()(iter it);

private:
    vec v;
};

#endif //LAB_4_FACTORIAL_H
