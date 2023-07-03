#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
using namespace std;
void autor(void) {
	printf("\n");
	for (int i = 1; i <= 120; i++) cout << "*";
	cout << "Autor programu: Simon Dudek\n\n";
	for (int i = 1; i <= 120; i++) cout << "*";
}
int main()
{
	int wym, beg, end, mac[10][10], control, d=1;
	time_t t;
	control = time(&t);
	setlocale(LC_ALL, "");
	autor();
	cout << "\nMaksymalny rozmiar macierzy to 10x10. ";
	cout << "Podaj wymiar macierzy: ";
	cin >> wym;
	while (wym > 10 || wym < 0)
	{
		cout << "Błędny rozmiar! Proszę ponowownie podać wymiar macierzy: ";
		cin >> wym;
	}
	cout << "Podaj zakres losowanych liczb.\n";
	cout << "Początek: ";
	cin >> beg;
	cout << "Koniec: ";
	cin >> end;
	while (beg >= end) {
		cout << "Błędne wpisanie zakresu! Aby zdefiniować liczba pocątkowa musi być mniejsza niż liczba końcowa!\n";
		cout << "Początek: ";
		cin >> beg;
		cout << "Koniec: ";
		cin >> end;
	}
	cout << endl;
	srand(control);
	if (beg == 0) {
		end++;
		for (int i = 0, j = 0; i < wym && j < wym; i++) {
			mac[j] [i] = (beg + rand() % end);
			if (i == wym - 1) {
				i = -1;
				j++;
			}
		}
	}
	else {
		if (beg > 0) {
			end -= beg - 1;
			for (int i = 0, j = 0; i < wym && j < wym; i++) {
				mac[j][i] = (beg + rand() % end);
				if (i == wym - 1) {
					i = -1;
					j++;
				}
			}
		}
		else {
			end += (beg * (-1)) + 1;
			for (int i = 0, j = 0; i < wym && j < wym; i++) {
				mac[j][i] = (beg + rand() % end);
				if (i == wym - 1) {
					i = -1;
					j++;
				}
			}
		}
	}
	for (int i = 0, j = 0; i < wym && j < wym; i++) {
		if (mac[j][i] >= 0)
		{
			cout <<" "<<mac[j][i] << " ";
			if (i == wym - 1) {
				cout << endl;
				i = -1;
				j++;
			}
		}
		else {
			cout <<mac[j][i] << " ";
			if (i == wym - 1) {
				cout << endl;
				i = -1;
				j++;
			}
		}
		
	}
	cout <<"\n\n\n";
	for (int i = 0, j = 0; i < wym && j < wym; i++) {
		if (i == j) {
			if (mac[j][i] == 0) {
				cout << " X ";
			}
			else {
				cout << " ! ";
			}
		}
		else
			if (mac[j][i] >= 0) {
				cout << " " << mac[j][i] << " ";
				if (i == wym - 1) {
					cout << endl;
					i = -1;
					j++;
				}
			}
			else {
				cout << mac[j][i] << " ";
				if (i == wym - 1) {
					cout << endl;
					i = -1;
					j++;
				}
			}
	}
		cout << "\n\n\n";
		for (int i = 0, j = 0; i < wym && j < wym; i++) {
			if (i > j) {
				cout << " 0 ";
				if (i == wym - 1) {
					cout << endl;
					i = -1;
					j++;
				}
			}
			else {
				if (mac[j][i] >= 0) {
					cout << " " << mac[j][i] << " ";
				}
				else {
					cout <<mac[j][i] << " ";
				}
			}

		}
		cout << "\n\n\n";
		if (wym == 0) {
			cout << "Macierz nie istnieje!\n";
		}
		else {
			for (int i = 0; i < wym; i++) {
				d *= mac[i][i];
			}
			cout << "det(macierzy) = " << d << endl;
		}
		system("pause");
		return 0;
}