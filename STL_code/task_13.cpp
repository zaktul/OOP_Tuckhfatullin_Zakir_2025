#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <sstream>
#include <Windows.h>
using namespace std;

string cleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (!ispunct(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    map<string, int> wordFrequency;
    string word;

    while (file >> word) {
        word = cleanWord(word);
        if (!word.empty()) {
            wordFrequency[word]++;
        }
    }

    file.close();
    cout << "\nЧастотная таблица слов:\n";
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}