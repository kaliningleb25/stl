//
//  main.cpp
//  lab1_5
//
//  Created by Глеб Калинин on 04.09.17.
//  Copyright © 2017 Глеб Калинин. All rights reserved.
//
//  Лабораторная 1_5
//  Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода (окончанием ввода является число 0).
//  Удалите все элементы, которые делятся на 2 (не используете стандартные алгоритмы STL), если последнее число 1. Если
//  последнее число 2, добавьте после каждого числа которое делится на 3 три единицы.

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> v;
    bool fl = true;
    int i;
    vector<int>::iterator iter;
    
    cout << "Please, enter the numbers:\n(0-exit)\n";
    
    // Заполнение вектора числами с клавиатуры:
    // 0 - окончание ввода
    // если последнее 1 - удаление всех элементов, которые делятся на 2
    while (fl) {
        cin >> i;
        if (i == 0) {
            fl = false;
            continue;
        }
        v.push_back(i);
    }
    
    // Если последнее число - 1,то удаляются все элементы, делящиеся на 2
    if (v[v.size()-1] == 1) {
        for (iter = v.begin(); iter < v.end(); iter++) {
            if (*iter % 2 == 0) {
                iter = v.erase(iter);
                iter--;
            }
        }
    }
    
    // Если последнее число - 2, то после каждого числа, которое делится на 3 добавляются три единицы
    else if (v[v.size()-1] == 2) {
        for (iter = v.begin(); iter < v.end(); iter++) {
            if(*iter %3 == 0) {
                for (int j = 0; j < 3; ++j)
                    iter = v.insert(iter+1, 1);
            }
            }
        }
    
    for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
    
    return 0;
}
