#include <iostream>
#include <cstring>

using namespace std;

struct PhoneEntry {
    char type[20];
    char number[15];
    union Details {
        struct Personal {
            char name[50];
        } personal;
        struct Service {
            char institution[50];
            char department[50];
        } service;
    } details;
};

void poisk(const char* institution, PhoneEntry spisok[], int size, PhoneEntry results[], int& resultCount) {
    resultCount = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(spisok[i].type, "Служебный") == 0 &&
            strcmp(spisok[i].details.service.institution, institution) == 0) {
            results[resultCount++] = spisok[i];
        }
    }
}

void bubbleSort(PhoneEntry arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].number, arr[j + 1].number) > 0) {
                PhoneEntry temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    PhoneEntry entries[5];

    strcpy_s(entries[0].type, "Личный");
    strcpy_s(entries[0].number, "123-45-67");
    strcpy_s(entries[0].details.personal.name, "Иванов Иван Иванович");

    strcpy_s(entries[1].type, "Служебный");
    strcpy_s(entries[1].number, "555-01-02");
    strcpy_s(entries[1].details.service.institution, "Больница №1");
    strcpy_s(entries[1].details.service.department, "Приемный покой");

    strcpy_s(entries[2].type, "Служебный");
    strcpy_s(entries[2].number, "555-03-04");
    strcpy_s(entries[2].details.service.institution, "Поликлиника №3");
    strcpy_s(entries[2].details.service.department, "Терапия");

    strcpy_s(entries[3].type, "Служебный");
    strcpy_s(entries[3].number, "555-05-06");
    strcpy_s(entries[3].details.service.institution, "Больница №1");
    strcpy_s(entries[3].details.service.department, "Хирургия");

    const int count = 5;
    char needInstitution[50] = "Больница №1";

    PhoneEntry needs[5];
    int foundCount = 0;

    poisk(needInstitution, entries, count, needs, foundCount);

    bubbleSort(needs, foundCount);

    cout << "Телефоны учреждения '" << needInstitution << "':" << endl;
    for (int i = 0; i < foundCount; i++) {
        cout << "Номер: " << needs[i].number
            << ", Учреждение: " << needs[i].details.service.institution
            << ", Подразделение: " << needs[i].details.service.department << endl;
    }

    return 0;
}