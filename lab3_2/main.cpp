#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

// 1. Разработайте программу, которая заполняет list<int> 15 случайными значениями от
// 1 до 20, список может содержать от 0 до 20 значений (обязательно проверить на
// длине списка 0, 1. 2, 3, 4, 5, 7, 14)

// 2. Выводит содержимое списка в следующем порядке: первый элемент, последний элемент,
// второй элемент, предпоследний элемент, тритий элемент и т.д.
// Например если список содержит:
// 1 2 3 4 5 6 7 8
// то вывод будет иметь вид
// 1 8 2 7 3 6 4 5
// Подсказка: можно использовать рекурсию и двунаправленные итераторы
// Калинин Глеб (23531/21-1)

// Вывод содержимого списка в указанном порядке:
void shuffleList(list<int> l) {
    list<int>::iterator iterBegin = l.begin();
    list<int>::iterator iterEnd = l.end();
    iterEnd--;

    cout << "Измененный список:\n";
    for (int i = 0; i < l.size() / 2; i++) {
        cout << *iterBegin << " ";
        iterBegin++;
        cout << *iterEnd << " ";
        iterEnd--;
    }

    // Если список содержит нечетное кол-во элементов(в конец добавляется последний - лишний элемент):
    if (l.size() % 2 != 0) {
        list<int>::iterator iterExtra = l.begin();
        for(int i = 0; i < l.size() / 2; i++)
            iterExtra++;
        cout << *iterExtra;
    }

}

// Заполнение списка:
void fillList(list<int> l, int size) {
    int arr[15];
    // Заполнение массива 15 случайными значениями в диапазоне:
    for(int i = 0; i < 15; i++)
        arr[i] = rand() % 20 + 1; // диапазон равен от 1 до 20 включительно

    // Заполнение списка случайными числами с указанным размером:
    for(int i = 0; i < size; i++)
        l.push_back(arr[i]);

    // Вывод списка:
    list<int>::iterator iter = l.begin();
    cout << "Список:\n";
    for (int i = 0; i < l.size(); i++) {
        cout << *iter << " ";
        iter++;
    }
    cout << "\n";

    // Вызов функции, меняющей порядок списка:
    shuffleList(l);
}

int main() {
    list<int> l1;
    int size = 6;
    srand(time(NULL));  // Для случайных значений при запуске

    if ((size >= 0) && (size <= 20))
        fillList(l1, size);
    else
        cout << "список может содержать от 0 до 20 значений";
    return 0;
}

