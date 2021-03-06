#include <iostream>
#include "Factorial.h"

/* Калинин Глеб (23531/21-1)
 * 
 *
Контейнер, который содержит значения факториала от 1! до 10!.

Интерфейс класса должен включать в себя как минимум:
Конструктор по умолчанию
Функцию получения итератора указывающего на первый элемент контейнера - begin()
Функцию получения итератора указывающего на элемент, следующий за последним - end()

Доступ к элементам этого контейнера возможен только с помощью итераторов возвращаемых функциями begin() и end().

Контейнер не должен содержать в памяти свои элементы, они должны вычисляться при обращении к ним через итератор

Класс итератора для перечисления элементов этого контейнера, объекты этого класса возвращаются функциями begin() и end().
Итератор должен быть двунаправленным. Итератор должен быть совместимым с STL (проверить это можно используя алгоритм copy
для копирования содержимого разработанного контейнера в vector<int>)

*/

int main() {

    Factorial factorial;
    int n;

    cout << "\nВведите число(от 1 до 10), факториал которого вы хотите узнать:\n";
    cin >> n;

    // Вывод факториала введенного числа:
    if (n > 0 && n < 11)
        factorial(factorial.begin() + (n - 1));
    else
        cout << "Число должно быть от 1 до 10!";

    // Вывод факториала введенного числа с конца списка:
    //factorial(factorial.end() - n);

    return 0;
}