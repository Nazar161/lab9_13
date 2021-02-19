#include "Ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>


using namespace std;

FILE *fl;
char flName[20];
TTicket *tickets;
int nst = 0;

int Menu() {
    cout << "Выберете меню:" << endl;
    cout << "1. Ввод имени файла" << endl;
    cout << "2. Создание файла" << endl;
    cout << "3. Ввод списка телевизоров" << endl;
    cout << "4. Прочитать данные из файла" << endl;
    cout << "5. Вывести результат по состоянию готовности" << endl;
    cout << "6. Сохранить результат в файл" << endl;
    cout << "7. Выход" << endl;
    int userChoise;
    cout << endl;
    cout << "Введите пункт меню ";
    cin >> userChoise;
    return userChoise;
}

void Nnf() {
    cout << "Введите именя файла ";
    cin >> flName;
}

void Newf() {
    if ((fl = fopen(flName, "wb")) == NULL) {
        cout << "Ошибка создания файла..." << endl;
        system("pause");
        exit(1);
    }
    cout << endl;
    cout << "Успешно..." << endl;
    fclose(fl);
}

void Spisok() {
    setlocale(0, "");
    if ((fl = fopen(flName, "rb+")) == NULL) {
        cout << "Ошибка чтения файла..." << endl;
        system("pause");
        exit(1);
    }
    cout << "Введите количество телевизоров ";
    cin >> nst;
    tickets = new TTicket[nst];
    for (int i = 0; i < nst; i++) {
        cout << "Введите марку телевизора: ";
        //getline(cin, students[i].fio);
        (cin >> tickets[i].brand).get();
        cout << "Введите дату приема в ремонт: ";
        cin >> tickets[i].date;
        cout << "Укажите состояние готовности 1-выполнен или 0-невыполнен: ";
        cin >> tickets[i].status;
        fwrite(&tickets[i], sizeof(TTicket), 1, fl);
    }
    cout << "Сохранение..." << endl;
    fclose(fl);
}

void Opf() {
    setlocale(0, "");
    if ((fl = fopen(flName, "rb")) == NULL) {
        cout << "Ошибка открытия файла..." << endl;
        exit(1);
    }
    nst = 0;
    TTicket stud;
    while (true) {
        int nwrt = fread(&stud, sizeof(TTicket), 1, fl);
        if (nwrt != 1) {
            break;
        }
        tickets[nst] = stud;
        cout << tickets[nst].brand << " " << tickets[nst].date << " " <<
            tickets[nst].status << endl;
        nst++;
    }
    fclose(fl);
}

void Resc() {
    setlocale(0, "");
    cout << "Невыполненные заказы: " << endl;
    for (int i = 0; i < nst; i++)
        if (tickets[i].status == false)
            cout << tickets[i].brand <<" "<< tickets[i].date << endl;
}

void Resf() {
    char namet[30];
    FILE* ft;
    cout << "Введите имя файлв" << endl;
    cin >> namet;
    if ((ft = fopen(namet, "w")) == NULL) {
        cout << "Ошибка создания файла..." << endl;
        exit(1);
    }
    char s[80];
    for (int i = 0; i < nst; i++)
        if (tickets[i].status == true) {
            strcpy(s, (tickets[i].brand + "\n").c_str());
            fputs(s, ft);
        }
    fclose(ft);
}