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
    cout << "�������� ����:" << endl;
    cout << "1. ���� ����� �����" << endl;
    cout << "2. �������� �����" << endl;
    cout << "3. ���� ������ �����������" << endl;
    cout << "4. ��������� ������ �� �����" << endl;
    cout << "5. ������� ��������� �� ��������� ����������" << endl;
    cout << "6. ��������� ��������� � ����" << endl;
    cout << "7. �����" << endl;
    int userChoise;
    cout << endl;
    cout << "������� ����� ���� ";
    cin >> userChoise;
    return userChoise;
}

void Nnf() {
    cout << "������� ����� ����� ";
    cin >> flName;
}

void Newf() {
    if ((fl = fopen(flName, "wb")) == NULL) {
        cout << "������ �������� �����..." << endl;
        system("pause");
        exit(1);
    }
    cout << endl;
    cout << "�������..." << endl;
    fclose(fl);
}

void Spisok() {
    setlocale(0, "");
    if ((fl = fopen(flName, "rb+")) == NULL) {
        cout << "������ ������ �����..." << endl;
        system("pause");
        exit(1);
    }
    cout << "������� ���������� ����������� ";
    cin >> nst;
    tickets = new TTicket[nst];
    for (int i = 0; i < nst; i++) {
        cout << "������� ����� ����������: ";
        //getline(cin, students[i].fio);
        (cin >> tickets[i].brand).get();
        cout << "������� ���� ������ � ������: ";
        cin >> tickets[i].date;
        cout << "������� ��������� ���������� 1-�������� ��� 0-����������: ";
        cin >> tickets[i].status;
        fwrite(&tickets[i], sizeof(TTicket), 1, fl);
    }
    cout << "����������..." << endl;
    fclose(fl);
}

void Opf() {
    setlocale(0, "");
    if ((fl = fopen(flName, "rb")) == NULL) {
        cout << "������ �������� �����..." << endl;
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
    cout << "������������� ������: " << endl;
    for (int i = 0; i < nst; i++)
        if (tickets[i].status == false)
            cout << tickets[i].brand <<" "<< tickets[i].date << endl;
}

void Resf() {
    char namet[30];
    FILE* ft;
    cout << "������� ��� �����" << endl;
    cin >> namet;
    if ((ft = fopen(namet, "w")) == NULL) {
        cout << "������ �������� �����..." << endl;
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