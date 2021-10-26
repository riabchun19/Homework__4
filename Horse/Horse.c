#include <stdio.h> 
#define N 8 // размер поля
#define M 8 // количество ходов
//3.Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски
//по одному разу.Здесь алгоритм решения такой же, как и в задаче о 8 ферзях.
//Разница только в проверке положения коня.

const int HODx[M] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int HODy[M] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void PrintField(int A[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

void Horse(int field[N][N], int num, int y, int x)
{
    static long count = 0; //Количество общих ходов коня
    field[y][x] = num++; // Отметить ход коня на клетке, в которой он стоит
    count++;
    if (num > N * N) // Если все ходы сделаны
    {
        printf("Number of total knight moves = %d\n\n", count); // От себя добавил
        PrintField(field); // Вывод поля
        exit();
    }
    for (int i = 0; i < M; i++)
    {
        int iNew = y + HODy[i]; // Новый ход по оси y
        int jNew = x + HODx[i]; // новый ход по оси х

        if ((field[iNew][jNew] != 0) || (iNew < 0 || iNew > N - 1) || (jNew < 0 || jNew > N - 1))
            continue;
        Horse(field, num, iNew, jNew); // Ход конем на выбранную клетку 

        field[iNew][jNew] = 0; // Обнуляем клетку, если в цикле не найдено решение
    }
}

void Zero(int a[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = 0;
}

void main()
{
    int Field[N][N]; // Шахматное поле
    Zero(Field);     // Обнуление поля
    Horse(Field, 1, 0, 0);
}