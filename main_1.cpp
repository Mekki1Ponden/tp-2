#include "Keeper.h"
#include "Note.h"
#include "Menu.h"

int main() {

	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	Keeper<Note> obj;

	int menu;
	system("cls");
	Menu(obj, "phone_number.txt");
	return 0;
}