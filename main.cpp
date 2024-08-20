/*
Задание 3. Анаграммы
Что нужно сделать
Напишите функцию, которая принимает две строки и возвращает true, если первая строка является анаграммой второй 
(то есть можно получить первую строку из второй путём перестановки букв местами), и false иначе. 
Для достижения хорошей асимптотики решения рекомендуется использовать std::map.
Пример анаграммы: лекарство — стекловар

Чек-лист для проверки задачи
• Функция принимает корректные типы данных, тип возвращаемого значения — bool.
• Функция не использует библиотек, кроме <iostream>, <map>, <string>.
• Функция корректно определяет, являются ли строки анаграммами.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool is_anagram(string s1, string s2){
    if (s1.length() != s2.length()){
        return false;
    }

    map<char,int> map_letters;

    for (char c: s2){
        if (map_letters.count(c)){
            ++map_letters[c];
        }
        else {
            map_letters[c] = 1;
        }
    }

    for (char c: s1){
        if (map_letters.count(c)){
            if (map_letters[c] == 1){
                map_letters.erase(c);
            }
            else {
                --map_letters[c];
            }
        }
        else {
            return false;
        }
    }
    return true;
}

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Введите две строки: ";
    string s1,s2;
    cin >> s1 >> s2;

    if (is_anagram(s1,s2)){
        cout << "Да" << endl;
    }
    else {
        cout << "Нет" << endl;
    }
}