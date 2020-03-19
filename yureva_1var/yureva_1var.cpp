/*
  Юрьева Надежда ПМИ 2 курс 5 группа

  задача1: Дан неориентированный невзвешенный граф. Необходимо определить, является ли он деревом.
  
  Входные данные:
                 В первой строке входного файла содержится одно натуральное число N (N ≤ 100) -
                 количество вершин в графе. Далее в N строках по N чисел - матрица смежности
                 графа: в i-ой строке на j-ом месте стоит 1, если вершины i и j соединены ребром, и
                 0, если ребра между ними нет. На главной диагонали матрицы стоят нули. Матрица
                 симметрична относительно главной диагонали.
  Выходные данные:
                 Вывести "YES", если граф является деревом, и "NO" иначе.

  дерево: 1)все вершины связаны
          2)кол-во ребер: N-1
		  3)нет циклов
  примеч.: выполнение первых двух условий достаточно для того, чтобы граф являлся деревом.
*/

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int check(int n,int h);
void DFS(int node_index, int **matrix, int N, bool *used, int &k);
bool IsTree(int **matrix, int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N = 0;
	cout << "Введите кол-во вершин в графе: ";
	N = check(N,0);
	int **matrix = new int *[N];
	for (int i = 0; i < N; i++) matrix[i] = new int[N];

	cout << "Введите значения матрицы смежности:"<<endl;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			matrix[i][j] = check(matrix[i][j],-1);

	bool t = false;
	t = IsTree(matrix, N);
	if (t) cout << "\nYES\n\n";
	else cout << "\nNO\n\n";
	system("pause");
	return 0;
}

int check(int n,int h)//проверка
{
	while (!(cin >> n) || (n <= h))
	{
		cout << "Ввод некорректен. Повторите ввод: ";
		cin.clear();
		while (cin.get() != '\n');

	}
	return n;
}
void DFS(int node_index, int **matrix, int N, bool *used, int &k)
{
	used[node_index] = true;
	k++;//кол-во вершин кот. посетили 
	for (int i = 0; i < N; i++) if (matrix[node_index][i] == 1 && !used[i]) DFS(i, matrix, N, used, k);
}
bool IsTree(int **matrix, int N)
{

	int k = 0;
	bool *used = new bool[N];
	for (int i = 0; i < N; i++)used[i] = false;

	DFS(0, matrix, N, used, k);//проверяем связность графа

	if (k != N)return 0;
	else
	{
		int edges = 0;//проверяем кол-во ребер
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (matrix[i][j]) {
					edges++;
				}
			}
		}
		if (edges != N - 1) return 0;
		else return 1;

	}

}