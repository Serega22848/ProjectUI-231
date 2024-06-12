#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <windows.h>
#include <locale>

using namespace std;

bool compareByLengthAndAlphabetical(const string& a, const string& b) {
    return make_tuple(a.size(), a) < make_tuple(b.size(), b);
}

bool isNumber(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), [](unsigned char c) { return isdigit(c); });
}

void bubbleSortAscending(vector<int>& numbers) {
    bool swapped;
    for (size_t i = 0; i < numbers.size(); ++i) {
        swapped = false;
        for (size_t j = 0; j < numbers.size() - 1 - i; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void readDataFromFile(const string& filename, vector<string>& rivers, vector<int>& numbers) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Файл не знайдено" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        if (isNumber(line)) {
            numbers.push_back(stoi(line));
        }
        else if (!line.empty()) {
            rivers.push_back(line);
        }
    }
}

void executeTask2() {
    // Встановлення кодування для консолі
    system("chcp 1251");

    vector<string> rivers;
    vector<int> numbers;

    readDataFromFile("data.txt", rivers, numbers);

    if (rivers.empty() && numbers.empty()) {
        return;
    }

    sort(rivers.begin(), rivers.end());
    cout << "Сортування річок за зростанням (std::sort):" << endl;
    for (const auto& river : rivers) {
        if (!river.empty()) {
            cout << river << " ";
        }
    }
    cout << endl;

    sort(rivers.begin(), rivers.end(), compareByLengthAndAlphabetical);
    cout << "Сортування річок за зростанням (спочатку за довжиною, потім за алфавітом):" << endl;
    for (const auto& river : rivers) {
        if (!river.empty()) {
            cout << river << " ";
        }
    }
    cout << endl;

    sort(numbers.begin(), numbers.end());
    cout << "Сортування чисел за зростанням (std::sort):" << endl;
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    bubbleSortAscending(numbers);
    cout << "Сортування чисел за спаданням (бульбашкове сортування):" << endl;
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    string searchRiver;
    int searchNumber;

    cout << "Введіть назву річки для пошуку: ";
    cin >> searchRiver;

    cout << "Введіть число для пошуку: ";
    cin >> searchNumber;

    auto itRiver = find(rivers.begin(), rivers.end(), searchRiver);
    auto itNumber = find(numbers.begin(), numbers.end(), searchNumber);

    if (itRiver != rivers.end()) {
        cout << "Знайдено річку " << searchRiver << " у списку річок." << endl;
    }
    else {
        cout << "Річку " << searchRiver << " не знайдено у списку річок." << endl;
    }

    if (itNumber != numbers.end()) {
        cout << "Знайдено число " << searchNumber << " у списку чисел." << endl;
    }
    else {
        cout << "Число " << searchNumber << " не знайдено у списку чисел." << endl;
    }
}
