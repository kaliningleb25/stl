//
// Created by Глеб Калинин on 17.09.17.
//

#include <iostream>
#include "Factorial.h"
using namespace std;

Factorial :: Factorial() {
    iter it;
    for(int i = 0; i < 10; i++) {
        v.push_back(i+1);
    }
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
}

iter Factorial ::begin() {
    return v.begin();
}

iter Factorial ::end() {
    return v.end();
}

int Factorial ::get_f(int n) {
    if (n == 1)
    {
        return 1;
    } else {
        return get_f(n - 1) * n;
    }
}

// Факториал числа
void Factorial::operator()(iter it)
{
    cout << "\nФакториал числа " << *it <<" : " << get_f(*it);
}



