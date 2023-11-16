#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int CountCommas(char* s) {
    int k = 0,
        pos = 0; // pos = ������� ������� ������
    char* t;
    while ((t = strchr(s + pos, ',')) != nullptr) // t = �������� �� ','
    {
        pos = t - s + 1; // pos = ��������� ������ ���� ','
        k++;
        if (k == 3)
            return pos; // ��������� ������� ������ ����
    }
    return -1; // ���� �� �������� ����� ����
}

char* Change(char* s) {
    char* t = new char[2 * strlen(s)]; // ��������� ��������� ����� ���� ������� �� �� ������
    char* p;
    int pos1 = 0, // pos1 = ������� ������� ������
        pos2 = 0;
    *t = 0;
    while ((p = strchr(s + pos1, ',')) != nullptr) // p = �������� �� ','
    {
        pos2 = p - s + 1; // pos2 = ������� ���������� ������� ���� ','
        strncat(t, s + pos1, pos2 - pos1 - 1); // ������ ���, �� ����� �����
        strcat(t, "**");
        pos1 = pos2;
    }
    strcat(t, s + pos1); // ������ ������� ����� ���� �������� ����
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

        char* dest = new char[2 * strlen(str)]; // ��������� ��������� ����� ���� ������� �� �� ������
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
