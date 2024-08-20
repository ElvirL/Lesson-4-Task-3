/*
������� 3. ���������
��� ����� �������
�������� �������, ������� ��������� ��� ������ � ���������� true, ���� ������ ������ �������� ���������� ������ 
(�� ���� ����� �������� ������ ������ �� ������ ���� ������������ ���� �������), � false �����. 
��� ���������� ������� ����������� ������� ������������� ������������ std::map.
������ ���������: ��������� � ���������

���-���� ��� �������� ������
� ������� ��������� ���������� ���� ������, ��� ������������� �������� � bool.
� ������� �� ���������� ���������, ����� <iostream>, <map>, <string>.
� ������� ��������� ����������, �������� �� ������ �����������.
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
    cout << "������� ��� ������: ";
    string s1,s2;
    cin >> s1 >> s2;

    if (is_anagram(s1,s2)){
        cout << "��" << endl;
    }
    else {
        cout << "���" << endl;
    }
}