#include <iostream>
#include <limits>
#include <cmath>
#include <functional>
#include <vector>
using namespace std;

int inputInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Недопустимий ввід. Будь ласка, введіть ціле число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

double inputDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Недопустимий ввід. Будь ласка, введіть число з плаваючою комою.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void executeTask1() {
    system("chcp 1251");
    double x = inputDouble("Введіть змінну з плаваючою комою: ");

    int y = inputInt("Введіть цілочисельну змінну y: ");
    int z = inputInt("Введіть цілочисельну змінну z: ");
    int t = inputInt("Введіть цілочисельну змінну t: ");

    vector<function<double(double)>> equations = {
        [](double x) { return -2 * pow(x, 3) + 3 * pow(x, 2) + 4 * x - 1; },
        [](double x) { return 3 * pow(x, 3) - 4 * pow(x, 2) + 5 * x - 2; },
        [](double x) { return -pow(x, 3) + 2 * pow(x, 2) - 3 * x + 1; },
        [](double x) { return 2 * pow(x, 3) + 5 * pow(x, 2) + x + 3; }
    };

    vector<double> results;
    for (size_t i = 0; i < equations.size(); ++i) {
        double result = equations[i](x);
        results.push_back(result);
        cout << "horemulta" << i + 1 << " = " << result << endl;
    }

    for (size_t i = 0; i < results.size(); ++i) {
        results[i] /= 4;
        cout << "Зменшена змінна horemulta" << i + 1 << " дорівнює: " << results[i] << endl;
    }

    double max_value = results[0];
    for (size_t i = 1; i < results.size(); ++i) {
        if (results[i] > max_value) {
            max_value = results[i];
        }
    }
    cout << "Максимальна змінна дорівнює: " << max_value << endl;

    double min_value = results[0];
    for (size_t i = 1; i < results.size(); ++i) {
        if (results[i] < min_value) {
            min_value = results[i];
        }
    }
    cout << "Мінімальна змінна дорівнює: " << min_value << endl;
}
