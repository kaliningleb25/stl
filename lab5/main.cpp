#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Калинин Глеб (23531/21-1)
 * Написать программу, которая выполняет следующие действия:

Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2,
генерируются случайным образом в диапазоне от -5 до 5, str заполняется из таблицы
(таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
Выводит полученный вектор на печать
Сортирует вектор следующим образом:
По возрастанию key1
Если key1 одинаковые, то по возрастанию key2
Если key1 и key2 одинаковые, то по возрастанию длинны строки str
Выводит полученный вектор на печать

DataStruct определена следующим образом:
typedef struct
{
    int       key1;
    int       key2;
    string  str;
} DataStruct;
 */

typedef struct
{
    int key1;
    int key2;
    string  str;
} DataStruct;

vector<DataStruct> fillVec() {
    vector<DataStruct> v;
    DataStruct ds;

    // Таблица из строк:
    string table[10] = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    for(int i = 0; i < 10; i++)
        v.push_back(ds);
    for(int i = 0; i < v.size(); i++) {
        v.at(i).key1 = rand() % 10 + (-5);
        v.at(i).key2 = rand() % 10 + (-5);
        v.at(i).str = table[rand() % 10];
    }

    return v;
}

void printVec(vector<DataStruct> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << "v" << i << ":\n";
        cout << "key1: " << v[i].key1;
        cout << "\nkey2: " << v[i].key2;
        cout << "\nstr: " << v[i].str;
        cout << "\n\n";
    }
    cout << "-----------------------------\n";
}

void sortVec(vector<DataStruct> v) {
    sort(v.begin(), v.end(), [](const DataStruct& a, const DataStruct& b) {
        if (a.key1 == b.key1)
            if (a.key2 == b.key2)
                return a.str < b.str;
            else
                return a.key2 < b.key2;
        return a.key1 < b.key1;
    });

    printVec(v);
}

int main() {
    vector<DataStruct> vec;
    srand(time(NULL));

    vec = fillVec();
    printVec(vec);

    sortVec(vec);

    return 0;
}