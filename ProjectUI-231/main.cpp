#include <iostream>

void executeTask1();
void executeTask2();
void executeTask3();

int main() {
    system("chcp 1251");
    int choice;
    std::cout << "������� �������� ��� ��������� (1, 2, ��� 3): ";
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
        std::cout << "������� ����!" << std::endl;
    }

    return 0;
}
