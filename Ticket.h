#pragma once
#include <string>

using namespace std;

struct TTicket {
	string brand;
	string date;
	bool status;
};

int Menu();
void Nnf();
void Newf();
void Spisok();
void Opf();
void Resc();
void Resf();