#include <iostream>

void executeTask1();
void executeTask2();
void executeTask3();

int main() {
    system("chcp 1251");
    int choice;
    std::cout << "Виберіть завдання для виконання (1, 2, або 3): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        executeTask1();
        break;
    case 2:
        executeTask2();
        break;
    case 3:
        executeTask3();
        break;
    default:
        std::cout << "Невірний вибір!" << std::endl;
    }

    return 0;
}
