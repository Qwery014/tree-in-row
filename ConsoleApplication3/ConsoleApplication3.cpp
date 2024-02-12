#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int horizontal;
	int vertical;
	int line;
	int max;

	cout << "Количество чисел по горизонтали: \n";
	cin >> horizontal;
	cout << "Количество чисел по вертикали: \n";
	cin >> vertical;
	cout << "Количество учёта одинаковых чисел в ряд: \n";
	cin >> line;

	if (line > horizontal || line > vertical) 
	{
		cout << "Введены неверные значения" << endl;
		system("pause");
		return 1;
	}

	cout << "Максимальное значения чисел: \n";
	cin >> max;

	vector<vector<int>> arr(vertical, vector<int>(horizontal));

	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizontal; j++)
		{
			// Создание генератора случайных чисел
			std::random_device rd; // устройство, генерирующее случайные числа
			std::mt19937 gen(rd()); // генератор Mersenne Twister с начальным значением, полученным из rd()

			// Определение пределов
			int lower_bound = 1;
			int upper_bound = max;

			// Создание распределения
			std::uniform_int_distribution<> distrib(lower_bound, upper_bound);

			// Генерация случайного числа в заданных пределах
			arr[i][j] = distrib(gen);

			cout << " " << arr[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizontal; j++)
		{
			int sameHorizontal = 0;
			int sameVertical = 0;
			int sameDiagonalTop = 0;
			int sameDiagonalBottom = 0;

			for (int k = 0; k < line; k++)
			{
				if (sameDiagonalTop == k && i + k < vertical && j + k < horizontal && arr[i][j] == arr[i + k][j + k])
				{
					sameDiagonalTop += 1;
				}
				if (sameDiagonalBottom == k && i - k >= 0 && j + k < horizontal && arr[i][j] == arr[i - k][j + k])
				{
					sameDiagonalBottom += 1;
				}
				if (sameVertical == k && i + k < vertical && arr[i][j] == arr[i + k][j])
				{
					sameVertical += 1;
				}
				if (sameHorizontal == k && j + k < horizontal && arr[i][j] == arr[i][j + k])
				{
					sameHorizontal += 1;
				}


				if (sameDiagonalTop == line) {
					cout << "Есть по диагонали!" << i << " " << j << endl;
					sameDiagonalTop = 0;
				}
				if (sameDiagonalBottom == line) {
					cout << "Есть по диагонали!" << i << " " << j << endl;
					sameDiagonalBottom = 0;
				}
				if (sameVertical == line)
				{
					cout << "Есть по вертикали!" << i  << " " << j << endl;
					sameVertical = 0;
				}
				if (sameHorizontal == line)
				{
					cout << "Есть по горизонтали!" << i << " " << j << endl;
					sameHorizontal = 0;
				}
			}
		}
	}

	return 0;
}
