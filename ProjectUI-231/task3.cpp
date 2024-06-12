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

    // ������� ��� ���������� �������� ���� ��������
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
        cout << "��� ��������: " << type << ", �������: " << startTime << ", ���������: " << duration
            << " ��, ������: " << episodeNumber << ", ��������: " << participants << endl;
    }
};

class ProgramList {
public:
    vector<Program> programs;

    // ��������� �������� �� ������
    void addProgram(const Program& program) {
        if (isTimeSlotFree(program)) {
            programs.push_back(program);
        }
        else {
            cout << "�������� �� ���� ���� ������, ������� ��� ������ � ���� ������������ � ����� ���������." << endl;
        }
    }

    // �������� �� ���������� ������� � ���
    bool isTimeSlotFree(const Program& newProgram) const {
        for (const auto& program : programs) {
            if (newProgram.startTime < program.getEndTime() && newProgram.getEndTime() > program.startTime) {
                return false;
            }
        }
        return true;
    }

    // ³���������� ������ �������
    void displayAll() const {
        for (const auto& program : programs) {
            program.display();
        }
    }

    // ����� ������� �� �����
    vector<Program> searchByType(const string& type) const {
        vector<Program> result;
        for (const auto& program : programs) {
            if (program.type == type) {
                result.push_back(program);
            }
        }
        return result;
    }

    // ����� ������� �� ����� ������ � ����
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

    schedule.addProgram(Program("������", "05:00", 30, 1, 2));
    schedule.addProgram(Program("Գ���", "09:00", 120, 1, 10));
    schedule.addProgram(Program("���", "11:00", 60, 5, 3));
    schedule.addProgram(Program("������", "12:00", 30, 2, 2));

    cout << "ѳ��� ��������:" << endl;
    schedule.displayAll();

    while (true) {
        int choice;
        cout << "\n������ ����� ��� ������:\n1. ����� ������� �� �����\n2. ����� ������� �� ����� ������ � ����\n3. �����\n��� ����: ";
        cin >> choice;

        if (choice == 3) {
            break;
        }

        if (choice == 1) {
            string searchType;
            cout << "������ ��� �������� ��� ������: ";
            cin >> searchType;

            auto foundPrograms = schedule.searchByType(searchType);
            cout << "\n���������� ������ �� ����� \"" << searchType << "\":" << endl;
            for (const auto& program : foundPrograms) {
                program.display();
            }
            if (foundPrograms.empty()) {
                cout << "�������� �� ��������." << endl;
            }
        }
        else if (choice == 2) {
            string searchStartTime;
            cout << "������ ��� ������ � ���� ��� ������ (� ������ HH:MM): ";
            cin >> searchStartTime;

            auto foundPrograms = schedule.searchByStartTime(searchStartTime);
            cout << "\n���������� ������ �� ����� ������ � ���� \"" << searchStartTime << "\":" << endl;
            for (const auto& program : foundPrograms) {
                program.display();
            }
            if (foundPrograms.empty()) {
                cout << "�������� �� ��������." << endl;
            }
        }
        else {
            cout << "������� ����. ��������� �� ���." << endl;
        }
    }
}
