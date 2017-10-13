//
//  main.cpp
//  lab1_2
//
//  Created by Глеб Калинин(23531/21-1) on 03.09.17.
//  Copyright © 2017 Глеб Калинин. All rights reserved.
//
//  Лабораторная 1_2
//  Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя метод at().



#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {

    // Инициализация вектора и доп. переменные для сортировки
    vector<int> v {1, 5, 2, 3, 4};
    int max = v[0];
    int temp = 0;
    
    cout << "До сортировки:\n";
    for(int i = 0; i < v.size(); i ++) {
        cout << v.at(i) << " ";
    }
    
    int start_s=clock();
    
    // Сортировка
    for(int i = 0; i < v.size(); i ++) {
        if (v.at(i) >= max) {
            max = v.at(i);
        }
        else {
            temp = v.at(i);
            v.at(i) = v.at(i-1);
            v.at(i-1) = temp;
        }
    }
    
    int stop_s=clock();
    
    cout << "\nПосле сортировки:\n";
    for(int i = 0; i < v.size(); i ++) {
        cout << v.at(i) << " ";
    }
    
    cout << "\nВремя сортировки: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*100 << endl;
    
    return 0;
}
