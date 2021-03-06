//
//  main.cpp
//  lab2
//
//  Created by Глеб Калинин(23531/21-1) on 10.09.17.
//  Copyright © 2017 Глеб Калинин. All rights reserved.
//
// Задание:
// Разработать программу, которая должна сделать следующее:
// 1. Прочитать содержимое текстового файла. Файл может содержать:
// - Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
// - Знаки препинания – «.», «,» «!» «?» «:» «;»
// - Пробельные символы – пробел, табуляция, символ новой строки.

// 2. Отформатировать текст следующим образом:
// - Не должно быть  пробельных символов отличных от пробела
// - Не должно идти подряд более одного пробела
// - Между словом и знаком препинания не должно быть пробела
// - После знака препинания всегда должен идти пробел
// - Слова длиной более 10 символов заменяются на слово «Vau!!!»

// 3. Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно целиком находиться в строке) и ее длинна не превышает 40 символов.

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Ф-я для замены в string
void myReplace(std::string& str,
               const std::string& oldStr,
               const std::string& newStr)
{
    std::string::size_type pos = 0u;
    while((pos = str.find(oldStr, pos)) != std::string::npos){
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
}

int main(int argc, const char * argv[]) {
    
    //ifstream fs ("/Users/kaliningleb/Desktop/PP/lab2/lab2/text.txt");
    ifstream fs ("/Users/kaliningleb/Desktop/PP/lab2/lab2/main.cpp");
    if(!fs) return 1; //Если ошибка открытия файла, то завершаем программу
    
    string text;
    string lin;
    
    //getline(fs, text);
    while (std::getline(fs, lin))
    {
        text += lin;
    }
    
    
    cout << "Исходный текст:\n" << text << "\n\n\n";
    
    // Не должно быть  пробельных символов отличных от пробела
    // --------------------------------------------------------
    string symbols[7] = {"\a","\b","\f","\n","\r","\t","\v"};
    
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < 7; j++) {
            if (text.find(symbols[j]) > 0) {
                myReplace(text, symbols[j], " ");
            }
        }
    }
    // --------------------------------------------------------
    
    // Не должно идти подряд более одного пробела
    // --------------------------------------------------------
    text = text.substr(0,distance(text.begin(),remove_if(text.begin(), text.end(),
                                                [](const char& a) { return (a == ' ') && (*(&a+1) == ' '); })));
    // --------------------------------------------------------
    
    // Между словом и знаком препинания не должно быть пробела
    // --------------------------------------------------------
    text = text.substr(0,distance(text.begin(),remove_if(text.begin(), text.end(),
                                                         [](const char& a) { return (a == ' ') && (*(&a+1) == ','); })));
    // --------------------------------------------------------
    
    // После знака препинания всегда должен идти пробел
    // --------------------------------------------------------
    for (string::size_type i = 0; i < text.size(); i++)
    {
        if (::ispunct(text[i]) && (i+1) < text.size() &&  !std::isspace(text[i+1]))
            text.insert(++i," ");
    }
    // --------------------------------------------------------
    
    // Слова длиной более 10 символов заменяются на слово «Vau!!!»
    // --------------------------------------------------------
    string word;
    
    istringstream iss(text, istringstream::in);
    vector<string> wordsVector;
    while(iss >> word)
    {
        wordsVector.push_back(word);
    }
    
    for (int i = 0; i < wordsVector.size(); i++) {
        if (wordsVector[i].length() > 10) {
            myReplace(text, wordsVector[i], "Vau!!!");
        }
    }
    string word2;
    
    istringstream iss2(text, istringstream::in);
    vector<string> wordsVector2;
    
    
    while(iss2 >> word2)
    {
        wordsVector2.push_back(word2);
    }
    // --------------------------------------------------------
    
    // Преобразовать полученный текст в набор строк, каждая из которых
    // содержит целое количество слов (слово должно целиком находиться в строке)
    // и ее длина не превышает 40 символов (для просмотра подробной инф. убрать комментарии)
    // --------------------------------------------------------
    vector<string> line;

    int len = 0;
    int lenMain = 0;
    int counter = 1;
    string str;
    
    int siz = wordsVector2.size();  // Узнаем количество слов
    
    for (int i = 0; i < siz; i++) {
        len = wordsVector2[i].length() + 1.0;
     //   cout << "Длина слова: " << len << "\n";
        lenMain += len;
     //   cout << "Общая длина: " << lenMain << "\n";
        counter++;
        
        // Если это последняя строка, но кол-во символов в ней меньше 40
        if (i >= (siz-counter)) {
            str += (wordsVector2[i] + " ");
         
            if ((i+1) == siz)
                line.push_back(str);
            
            continue;
        }
        
        // Записываем в str слова (до 40 символов)
        if (lenMain < 40) {
            str += (wordsVector2[i] + " ");
        }
        
        // Если символов больше 40, записываем строку в
        // вектор строк(с переносом последнего слова на следующую строку)
        else {
            line.push_back(str);
            counter = 0;
            lenMain = 0;
            str = "";
            str += (wordsVector2[i] + " ");
            len = wordsVector2[i].length();
            lenMain += len;
          //  cout << "-----------------------\n";
        }
        
    //    cout << "Количество слов " << counter << "\n";
    }
    
    // Вывод вектора строк
    cout << "\n\n\n";
    for (int i = 0; i < line.size(); i++) {
        cout << "line " << i << ": " << line[i] << "(" << line[i].size() << ")\n";
        
    }
    cout << "\n\n\n";
    
    // Вывод отформатированного текста
    cout <<"Отформатированный текст:\n"<< text;
    
    return 0;
}


