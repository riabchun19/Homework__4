#include <stdio.h> 
#include <string.h> 
// 2. Решите задачу о нахождении длины максимальной последовательности с помощью матрицы.
int LCS(char* x, char* y) { // Пример для тебе з рекурсией
	if (*x == '\0' || *y == '\0') // Если одна из строк дошла конца
		return 0;
	else if (*x == *y)
		return LCS(x + 1, y + 1) + 1;
	else {
		int x1 = LCS(x + 1, y);
		int x2 = LCS(x, y + 1);
		return (x1 > x2) ? x1 : x2;
	}
}

void LCS_2(char* x, char* y) { // с помощью матрицы
	int matrix[20][20] = { 0 };
	for (int i = 1; i < strlen(y) + 1; i++)
	{
		for (int j = 1; j < strlen(x) + 1; j++)
		{
			if (y[i - 1] == x[j - 1])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;// Если нашли совпадение, то дабавили +1 к счетчику
			}
			else
			{
				matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
			}
		}
	}

	for (int n = 0; n < strlen(y) + 1; n++) // вивод матрицы
	{
		for (int m = 0; m < strlen(x) + 1; m++)
		{
			printf("%3d", matrix[n][m]);
		}
		printf("\n");
	}
}

int main() {
	char a[] = "geekbrains";
	char b[] = "geekminds";
	printf("%d\n\n", LCS(&a, &b));
	LCS_2(&a, &b);
}