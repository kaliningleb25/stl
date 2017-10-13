//
//  main.cpp
//  lab1_4
//
//  Created by Глеб Калинин(23531/21-1) on 04.09.17.
//  Copyright © 2017 Глеб Калинин. All rights reserved.
//
//  Лабораторная 1_4
//  Прочитайте во встроенный массив С содержимое текстового файлы, скопируйте данные в вектор одной строкой кода (без циклов
//  и алгоритмов STL)

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<char> v;
    const int len = 30;
    char mass[len];

    ifstream fs("/Users/kaliningleb/Desktop/PP/lab1_4/lab1_4/text4.txt");
    
    if(!fs) return 1; //Если ошибка открытия файла, то завершаем программу
    
    // Чтение текстового файла в массив:
    cout << "Массив из текстового файла:\n";
    for(int i = 0; i < len-1; i++) {
        fs >> mass[i];
        cout << mass[i] << " ";
    }
    

    // Копирование данных из массива в вектор одной строкой кода:
    v.assign(mass, &mass[sizeof(mass)-1]);
    
    fs.close(); //Закрываем файл
    
    // Вывод результата из вектора:
    cout<<"\nКопия массива в векторе:\n";
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    
    
    return 0;
}
