// Решение задачи о 8 ферзях (для примера)
#include <stdio.h>
#include <math.h>
#define N 8
#define M 8
// Доска для ферзей.
// 0 - клетка пустая
// число - номер ферзя
int board[N][M];

int SearchSolution(int n);
int CheckBoard();
int CheckQueen(int x, int y);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);
void Pause(int key);

int main()
{
    Zero(N, M, board);
    SearchSolution(1);
    printf("\n\n");
    Print(N, M, board);
    getch();
    return 0;
}

int SearchSolution(int n) //Решение для поиска 
{
    // Если проверка доски возвращает 0, то эта расстановка не подходит
    if (CheckBoard() == 0)
        return 0;
    // 9 ферзя не ставим. Решение найдено
    if (n == 9)
        return 1;
    int row;
    int col;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < M; col++)
        {
            if (board[row][col] == 0)
            {
                //Расширяем test_solution
                board[row][col] = n;
                // Рекурсивно проверяем, ведет ли это к решению.
                if (SearchSolution(n + 1))
                    return 1;
                // Если мы дошли до этой строки, данное частичное решение
                // не приводит к полному.
                board[row][col] = 0;
            }
        }
    }
    return 0;
}

// Проверка всей доски
int CheckBoard() //Проверить доску
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (board[i][j] != 0)
                if (CheckQueen(i, j) == 0)
                    return 0;
        }
    }
    return 1;
}
// Проверка определённого ферзя
int CheckQueen(int x, int y) // Проверка ферзя
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            // Если нашли фигуру
            if (board[i][j] != 0)
                if (!(i == x && j == y)) // Если это не наша фигура
                {
                    // Лежат на одной вертикали или горизонтали
                    if (i - x == 0 || j - y == 0)
                        return 0;
                    // Лежат на одной диагонали
                    if (abs(i - x) == abs(j - y))
                        return 0;
                }
    // Если дошли до сюда, то всё в порядке
    return 1;
}

// Выводим доску на экран
void Print(int n, int m, int a[N][M])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

// Очищаем доску
void Zero(int n, int m, int a[N][M])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[i][j] = 0;
}

void Pause(int key)
{
    if (key == 1)
        getch();
    else
        for (int i = 0; i < 100000000; i++);
}