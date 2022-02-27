// week13HomeWork1Task3KrestNoll.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задание 3. Написать игру «Крестики-нолики».

#include <iostream>
using namespace std;

char pole[9] = {};

bool XO(char XO) {
	int pobed[][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{6,4,2} };

	for (int i = 0; i < 8; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (pole[pobed[i][j]] == XO) {
				count++;
			}
		}
		if (count == 3)
		{
			return true;
		}
	}
	return false;
}
void VivodPole()
{
	cout << "\n";


	cout << "\t\t\t" << pole[6] << " | " << pole[7] << " | " << pole[8] << endl;
	cout << "\t\t\t" << pole[3] << " | " << pole[4] << " | " << pole[5] << endl;
	cout << "\t\t\t" << pole[0] << " | " << pole[1] << " | " << pole[2] << endl;
}

int Pohodit()
{
	cout << "\t\t\t 7 | 8 | 9 " << endl;
	cout << "\t\t\t 4 | 5 | 6 " << endl;
	cout << "\t\t\t 1 | 2 | 3 " << endl;

	cout << endl;

	VivodPole();

	cout << "Vvedite hod";
	int move;
	cin >> move;

	if (move > 9 || move < 1)
	{
		cout << "Vvedite ewe raz(1-9)" << endl;
		cin >> move;
	}
	return move;
}
char KtoPobedit() {
	int turn = 1;

	while (!XO('X') && !XO('O')) {
		int move = Pohodit();
		if (turn % 2 == 1) {
			pole[move - 1] = 'X';
			if (XO('X')) {
				cout << "X pobedil\n";
				return 'X';
			}
		}
		else {
			pole[move - 1] = 'O';
			if (XO('O')) {
				cout << "O pobedil\n";
				return 'O';
			}
		}
		turn++;
		if (turn == 10) {
			cout << "Ni4iya\n";
			return 'D';
		}
	}
}
int main() {
	KtoPobedit();
	VivodPole();

}
