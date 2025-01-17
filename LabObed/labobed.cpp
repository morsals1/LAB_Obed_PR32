// labobed.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

struct pig {
    char number[12];
    int type;
    union Info {
        char fio[20];
        struct {
            char name_inst[20];
            char name_unit[20];
        } work;
    } info;
};

bool compare(const pig& a, const pig& b) {
    return std::strcmp(a.number, b.number) < 0;
}

int main() {

    setlocale(LC_ALL, "");

    pig phonebook[5];

    strncpy_s(phonebook[0].number, sizeof(phonebook[0].number), "89002118176", _TRUNCATE);
    phonebook[0].type = 0;
    strncpy_s(phonebook[0].info.fio, sizeof(phonebook[0].info.fio), "Kolya Merobov", _TRUNCATE);

    strncpy_s(phonebook[1].number, sizeof(phonebook[1].number), "89006571122", _TRUNCATE);
    phonebook[1].type = 1;
    strncpy_s(phonebook[1].info.work.name_inst, sizeof(phonebook[1].info.work.name_inst), "Institute", _TRUNCATE);
    strncpy_s(phonebook[1].info.work.name_unit, sizeof(phonebook[1].info.work.name_unit), "HR Department", _TRUNCATE);

    strncpy_s(phonebook[2].number, sizeof(phonebook[2].number), "89016669977", _TRUNCATE);
    phonebook[2].type = 1;
    strncpy_s(phonebook[2].info.work.name_inst, sizeof(phonebook[2].info.work.name_inst), "Institute", _TRUNCATE);
    strncpy_s(phonebook[2].info.work.name_unit, sizeof(phonebook[2].info.work.name_unit), "IT Department", _TRUNCATE);

    strncpy_s(phonebook[3].number, sizeof(phonebook[3].number), "89001122334", _TRUNCATE);
    phonebook[3].type = 0;
    strncpy_s(phonebook[3].info.fio, sizeof(phonebook[3].info.fio), "Ivan Petrov", _TRUNCATE);

    strncpy_s(phonebook[4].number, sizeof(phonebook[4].number), "89007778899", _TRUNCATE);
    phonebook[4].type = 1;
    strncpy_s(phonebook[4].info.work.name_inst, sizeof(phonebook[4].info.work.name_inst), "Institute", _TRUNCATE);
    strncpy_s(phonebook[4].info.work.name_unit, sizeof(phonebook[4].info.work.name_unit), "Finance Department", _TRUNCATE);

    int size = sizeof(phonebook) / sizeof(phonebook[0]);

    const char* target_institution = "Institute";
    std::vector<pig> filtered;

    for (int i = 0; i < size; ++i) {
        if (phonebook[i].type == 1 && std::strcmp(phonebook[i].info.work.name_inst, target_institution) == 0) {
            filtered.push_back(phonebook[i]);
        }
    }

    std::sort(filtered.begin(), filtered.end(), compare);

    std::cout << "Телефоны учреждения: " << target_institution << "\n";
    for (const auto& entry : filtered) {
        std::cout << "Номер: " << entry.number << ", Подразделение: " << entry.info.work.name_unit << "\n";
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
