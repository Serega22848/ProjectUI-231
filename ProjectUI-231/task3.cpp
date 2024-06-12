#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Program {
public:
    string type;
    string startTime;
    int duration;
    int episodeNumber;
    int participants;

    Program(string t, string st, int dur, int ep, int part)
        : type(t), startTime(st), duration(dur), episodeNumber(ep), participants(part) {}

    // Функція для визначення кінцевого часу програми
    string getEndTime() const {
        int hours = stoi(startTime.substr(0, 2));
        int minutes = stoi(startTime.substr(3, 2));
        minutes += duration;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
        return (hours < 10 ? "0" : "") + to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
    }

    void display() const {
        cout << "Тип програми: " << type << ", Початок: " << startTime << ", Тривалість: " << duration
            << " хв, Випуск: " << episodeNumber << ", Учасники: " << participants << endl;
    }
};

class ProgramList {
public:
    vector<Program> programs;

    // Додавання програми до списку
    void addProgram(const Program& program) {
        if (isTimeSlotFree(program)) {
            programs.push_back(program);
        }
        else {
            cout << "Програма не може бути додана, оскільки час виходу в ефір перетинається з іншою програмою." << endl;
        }
    }

    // Перевірка на накладання програм у часі
    bool isTimeSlotFree(const Program& newProgram) const {
        for (const auto& program : programs) {
            if (newProgram.startTime < program.getEndTime() && newProgram.getEndTime() > program.startTime) {
                return false;
            }
        }
        return true;
    }

    // Відображення списку програм
    void displayAll() const {
        for (const auto& program : programs) {
            program.display();
        }
    }

    // Пошук програм за типом
    vector<Program> searchByType(const string& type) const {
        vector<Program> result;
        for (const auto& program : programs) {
            if (program.type == type) {
                result.push_back(program);
            }
        }
        return result;
    }

    // Пошук програм за часом виходу в ефір
    vector<Program> searchByStartTime(const string& startTime) const {
        vector<Program> result;
        for (const auto& program : programs) {
            if (program.startTime == startTime) {
                result.push_back(program);
            }
        }
        return result;
    }
};

void executeTask3() {
    system("chcp 1251");
    ProgramList schedule;

    schedule.addProgram(Program("Новини", "05:00", 30, 1, 2));
    schedule.addProgram(Program("Фільм", "09:00", 120, 1, 10));
    schedule.addProgram(Program("Шоу", "11:00", 60, 5, 3));
    schedule.addProgram(Program("Новини", "12:00", 30, 2, 2));

    cout << "Сітка мовлення:" << endl;
    schedule.displayAll();

    while (true) {
        int choice;
        cout << "\nОберіть опцію для пошуку:\n1. Пошук програм за типом\n2. Пошук програм за часом виходу в ефір\n3. Вихід\nВаш вибір: ";
        cin >> choice;

        if (choice == 3) {
            break;
        }

        if (choice == 1) {
            string searchType;
            cout << "Введіть тип програми для пошуку: ";
            cin >> searchType;

            auto foundPrograms = schedule.searchByType(searchType);
            cout << "\nРезультати пошуку за типом \"" << searchType << "\":" << endl;
            for (const auto& program : foundPrograms) {
                program.display();
            }
            if (foundPrograms.empty()) {
                cout << "Програми не знайдено." << endl;
            }
        }
        else if (choice == 2) {
            string searchStartTime;
            cout << "Введіть час виходу в ефір для пошуку (у форматі HH:MM): ";
            cin >> searchStartTime;

            auto foundPrograms = schedule.searchByStartTime(searchStartTime);
            cout << "\nРезультати пошуку за часом виходу в ефір \"" << searchStartTime << "\":" << endl;
            for (const auto& program : foundPrograms) {
                program.display();
            }
            if (foundPrograms.empty()) {
                cout << "Програми не знайдено." << endl;
            }
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }
}
