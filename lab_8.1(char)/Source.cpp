#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int CountCommas(char* s) {
    int k = 0,
        pos = 0; // pos = позиція початку пошуку
    char* t;
    while ((t = strchr(s + pos, ',')) != nullptr) // t = вказівник на ','
    {
        pos = t - s + 1; // pos = наступний символ після ','
        k++;
        if (k == 3)
            return pos; // Повертаємо позицію третьої коми
    }
    return -1; // Якщо не знайдено третю кому
}

char* Change(char* s) {
    char* t = new char[2 * strlen(s)]; // Враховуємо можливість кожної коми замінити на дві зірочки
    char* p;
    int pos1 = 0, // pos1 = позиція початку пошуку
        pos2 = 0;
    *t = 0;
    while ((p = strchr(s + pos1, ',')) != nullptr) // p = вказівник на ','
    {
        pos2 = p - s + 1; // pos2 = позиція наступного символа після ','
        strncat(t, s + pos1, pos2 - pos1 - 1); // Додаємо все, що перед комою
        strcat(t, "**");
        pos1 = pos2;
    }
    strcat(t, s + pos1); // Додаємо залишок рядка після останньої коми
    strcpy(s, t);
    return t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int thirdCommaPos = CountCommas(str);
    if (thirdCommaPos != -1) {
        cout << "Position of the third comma: " << thirdCommaPos << endl;

        char* dest = new char[2 * strlen(str)]; // Враховуємо можливість кожної коми замінити на дві зірочки
        dest = Change(str);
        cout << "Modified string (param) : " << str << endl;
        cout << "Modified string (result): " << dest << endl;
        delete[] dest;
    }
    else {
        cout << "String does not contain at least three commas." << endl;
    }

    return 0;
}
