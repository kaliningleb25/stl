//
//  main.cpp
//  lab1_1
//
//  Created by Глеб Калинин (23531/21-1) on 03.09.17.
//  Copyright © 2017 Глеб Калинин. All rights reserved.
//
//  Лабораторная 1_1
//  Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя оператор operator[].
//
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Инициализация вектора
    vector<int> v {1,3,2,5,4};
    
    cout << "До сортировки:\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    // Доп. переменные для сортировки
    int max = v[0];
    int temp = 0;
    
    int start_s=clock();
    
    // Сортировка
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= max) {
            max = v[i];
        }
        else {
            temp = v[i];
            v[i] = v[i-1];
            v[i-1] = temp;
        }
    }
    
    int stop_s=clock();
    
    
    cout << "\nПосле сортировки:\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    cout << "\nВремя сортировки: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*100 << endl;
    
    return 0;
    
    

    
}
