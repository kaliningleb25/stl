#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

/* Калинин Глеб (23531/21-1)
 *
 * Написать программу, которая выполняет следующие действия:
Читает содержимое текстового файла
Выделяет слова, словом считаются последовательность символов разделенных пробелами и/или знаками табуляции и/или символами новой строки
Вывести список слов присутствующий в тексте без повторений (имеется в виду, что одно и то же слово может присутствовать в списке
только один раз)
 */

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

int main() {

    string text;
    string lin;

    ifstream fs ("..//main.cpp");
    if(!fs) return 1; //Если ошибка открытия файла, то завершаем программу

    while (getline(fs, lin))
        text += lin;
    cout << "Исходный текст:\n" << text << "\n";

    string text2 = text;


    // Убираем все лишние символы
    string symbols[11] = {"\a","\b","\f","\n","\r","\t","\v", ",", ".", "—", ";"};

    for (int i = 0; i < text2.size(); i++) {
        for (int j = 0; j < 11; j++) {
            if (text2.find(symbols[j]) > 0) {
                myReplace(text2, symbols[j], "");
            }
        }
    }

    // Считываем слова из текста в новый вектор
    string word;

    istringstream iss(text2, istringstream::in);
    vector<string> wordsVector;
    while(iss >> word)
    {
        wordsVector.push_back(word);
    }

    /*
    cout << "Слова в тексте:\n";
    for (int i = 0; i < wordsVector.size(); i++) {
        cout << wordsVector[i] << "\n";
    }
     */

    // Вывод списка слов, присутствующих в тексте без повторений:
    vector<string> wordsVectorFinal;

    vector<string>::iterator iter = wordsVector.begin();


    for(int i = 0; i < wordsVector.size(); i++) {
        int cnt = count(wordsVector.begin(), wordsVector.end(), wordsVector[i]);
        if (cnt < 2 && cnt > 0) {
            wordsVectorFinal.push_back(wordsVector[i]);
        }
    }

    cout << "--------------------------------------------------------";
    cout << "\nСлова, которые не повторяются: (" << wordsVectorFinal.size() << ")\n";
    for (int i = 0; i < wordsVectorFinal.size(); i++) {
        cout << wordsVectorFinal[i] << "\n";
    }



    return 0;
}