#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	LinkedList lst;
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	lst.push_front(2);
	lst.push_front(1);

	cout << "Список после добавления элементов: ";
	lst.print_to_console();
	cout << endl << endl;

	lst.pop_back();
	lst.pop_front();
	cout << "Список после удаления: ";
	lst.print_to_console();
	cout << endl << endl;

	lst.insert(22, 0);
	cout << "Список после вставки: ";
	lst.print_to_console();
	cout << endl << endl;
	cout << "Элемент с индексом 0: ";
	cout << lst.at(0) << endl << endl;

	lst.remove(0);
	cout << "Список после удаления: ";
	lst.print_to_console();
	cout << endl << endl;

	cout << "Размер списка: " << lst.get_size() << endl << endl;

	lst.set(0, 21);
	cout << "Список после замены значения: ";
	lst.print_to_console();
	cout << endl << endl;

	bool empty = lst.isEmpty();
	cout << "Список пуст? " << empty << endl << endl;

	lst.reverse();
	cout << "Перевернутый список: ";
	lst.print_to_console();
	cout << endl << endl;

	return 0;
}