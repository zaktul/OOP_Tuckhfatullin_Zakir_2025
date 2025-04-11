#include <iostream>
using namespace std;

int compstr(const char*, const char*); 

int main() {
    const int SIZE = 100;
    char str1[SIZE], str2[SIZE];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int result = compstr(str1, str2);

    if (result == -1)
        cout << "First string comes first alphabetically." << endl;
    else if (result == 1)
        cout << "Second string comes first alphabetically." << endl;
    else
        cout << "Strings are equal." << endl;

    return 0;
}

int compstr(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2)
            return -1;
        else if (*s1 > *s2)
            return 1;
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0')
        return 0;
    else if (*s1 == '\0')
        return -1;
    else
        return 1;
}
