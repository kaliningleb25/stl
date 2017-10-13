//
//  main.cpp
//  lab1_3
//
//  Created by Глеб Калинин(23531/21-1) on 03.09.17.
//  Copyright © 2017 Глеб Калинин. All rights reserved.
//
//  Лабораторная 1_3
//  Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя для доступа к содержимому
//  вектора только итераторы. Для работы с итераторами допустимо использовать только операторы получения текущего элемента и
//  перехода в следующему (подсказка, можно сохранять копию итератора указывающего на некоторый элемент).

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Инициализация вектора целыми числами
    vector<int> v {3,1,4,5,2};
    
    // Вывод вектора до сортировки
    cout << "До сортировки:\n";
    for(int i = 0; i < v.size(); i ++) {
        cout << v.at(i) << " ";
    }
    
    // Инициализация итератора (указание на первый элемент вектора)
    vector<int>::iterator iter;
    iter = v.begin();
    
    cout << "\n";
    
    bool fl = true;
    int tmp;
    
    int start_s=clock();
    
    // Сортировка
    while(fl)
    {
        fl = false;
        for (iter = v.begin(); iter < --v.end(); iter++)
        {
            if (*iter > *(iter+1))
            {
                tmp = *iter;
                *iter = *(iter+1);
                *(iter+1) = tmp;
                fl = true;
            }
        }
    }
    
    int stop_s=clock();
    
    // ------------------------------------------------------
    int start_s2=clock();
    
    sort(v.begin(), v.end());
    
    int stop_s2 = clock();
    // ------------------------------------------------------
    
    // Вывод вектора после сортировки
    cout << "\nПосле сортировки:\n";
    for(int i = 0; i < v.size(); i ++) {
        cout << v.at(i) << " ";
    }
    
    cout << "\nВремя сортировки: " << stop_s-start_s <<"(мс)";
    cout << "\n";
    cout << "\nВремя стандартной сортировки: " << stop_s2-start_s2 << "(мс)\n";

    
    
    return 0;
}
