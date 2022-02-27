#pragma once
#pragma once
#include <iostream>
#include <ctime>

#define DS 8

int desk[DS][DS];
int step[8][2] = { {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2} };
int n;

void print_desk()
{
	//	printf("n=%d\n", n);
	for (int i = 0; i < DS; i++)
	{
		for (int j = 0; j < DS; j++)
			printf(" %2d", desk[i][j]);
		printf("\n");
	}
}

bool set_horse(int x, int y)
{
	// проверка параметров
	if ((x < 0) || (x >= DS) || (y < 0) || (y >= DS))
		return false;

	if (desk[x][y] != 0)
		return false;

	// следующий ход
	n++;
	desk[x][y] = n;

	// стоп игра
	if (n == DS * DS)
		return true;

	//printf("n=%d\n", n);
	//print_desk();
	//system("pause");

	for (int i = 0; i < 8; i++)
		if (set_horse(x + step[i][0], y + step[i][1]))
			return true;
	n--;
	desk[x][y] = 0;

	return false;
}



int main()
{
	time_t t_start, t_end;

	setlocale(LC_ALL, "RUSSIAN");
	time(&t_start);

	n = 0;
	for (int i = 0; i < DS; i++)
		for (int j = 0; j < DS; j++)
			desk[i][j] = 0;

	set_horse(1, 1);

	print_desk();

	time(&t_end);
	std::cout << std::endl << "Решение найдено за " << t_end - t_start << " секунд" << std::endl;
	system("pause");
}