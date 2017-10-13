//
//  main.cpp
//  lab1_6
//
//  Created by Глеб Калинин(23531/21) on 08.09.17.
//  Copyright © 2017 Глеб Калинин. All rights reserved.
//
//  Лабораторная 1_6
//  Напишите функцию void fillRandom(double* array, int size) заполняющую массив случайными значениями в интервале от -1.0 до 1.0.
//  Заполните с помощью заданной функции вектора размером 5,10,25,50,100 и отсортируйте его содержимое (с помощью любого
//  разработанного ранее алгоритма модифицированного для сортировки действительных чисел)


#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>

using namespace std;

// Заполнение массивов указанного размера случайными числами от -1.0 до 1.0
void fillRandom(double* array, int size) {
    vector<double> v;
    
    
    
    for(int i = 0; i < size; i++) {
        array[i] = 1 - 2.0 * rand() / RAND_MAX;
        v.push_back(array[i]);
    }
    
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    
    // Инициализация итератора (указание на первый элемент вектора)
    vector<double>::iterator iter;
    iter = v.begin();
    
    cout << "\n";
    
    bool fl = true;
    double tmp;
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
    
    // Вывод вектора после сортировки
    cout << "\nПосле сортировки:\n";
    for(int i = 0; i < v.size(); i ++) {
        cout << v[i] << " ";
    }
    
    
    cout << "--------------------------------------------------------------------" << "\n";
}


int main(int argc, const char * argv[]) {
    vector<double> v;
    srand(time(NULL));
    
    int arrSIZE[5] = {5, 10, 25, 50, 100};
    
    for(int i = 0; i < 5; i++) {
        double arr[arrSIZE[i]];
        cout << "Изначальный массив " << i+1 << " (" << arrSIZE[i] << " значений):" <<  "\n";
        fillRandom(arr, arrSIZE[i]);
    }
    
    
    
    
    return 0;
}


