#include <iostream>
#include <cmath>
using namespace std;

// функция создания массива
double** create(int n)
{
	double** matrix = new double* [n];
	for (int count = 0; count < n; count++)
		matrix[count] = new double[n];
	return matrix;
}
void Inputmas(double** mas, int n)  //ввод массива
{
	for (int count_strok = 0; count_strok < n; count_strok++)
		for (int count_stolb = 0; count_stolb < n; count_stolb++)
			cin >> mas[count_strok][count_stolb];
}
void Outputmas(double** mas, int n) //вывод массива
{
	for (int count_strok = 0; count_strok < n; count_strok++)
	{
		for (int count_stolb = 0; count_stolb < n; count_stolb++)
			cout << mas[count_strok][count_stolb] << "   ";
		cout << endl;
	}
}
void Clear_mas(double** mas,int n)
{
	for (int count = 0; count < n; count++)
		delete[] mas[count];
	delete[] mas;
}
double** MatrixSum(double** matrixA, double** matrixB, int n)
{
	double** matrixOtv = create(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			matrixOtv[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	return matrixOtv;
}
double** MatrixRazn(double** matrixA, double** matrixB, int n)
{
	double** matrixOtv = create(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			matrixOtv[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	return matrixOtv;
}
double** MatrixProiz(double** matrixA, double** matrixB, int n) 
{
	double** matrixOtv = create(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			matrixOtv[i][j] = 0;
			for (int t = 0; t < n; t++)
					matrixOtv[i][j] += matrixA[i][t] * matrixB[t][j];
		}
	return matrixOtv;
}
int main()
{
	
    setlocale(LC_ALL, "russian");
    cout << "Вычислить значение матричного выражения. " << endl;
	cout << "Введите три квадратные матрицы : " << endl;
	int n1, n2, n3;
	cout << "Матрица A= " << endl;
	cout << "Размерность квадратной матрицы = ";	cin >> n1;
	double** matrix1 = create(n1);
	Inputmas(matrix1, n1);
	cout << "Матрица B= " << endl;
	cout << "Размерность квадратной матрицы = ";	cin >> n2;
	double** matrix2 = create(n2);
	Inputmas(matrix2, n2);
	cout << "Матрица C= " << endl;
	cout << "Размерность квадратной матрицы = ";	cin >> n3;
	double** matrix3 = create(n3);
	Inputmas(matrix3, n3);
	if (n1 != n2 || n1 != n3 || n2 != n3)
	{
		cout << "Error! Invalid sizes of matrix!" << endl;
		return 0;
	}
	else 
	{
		double** matrixOtv = MatrixProiz(matrix2, matrix3, n1);
		double** matrixOtv1 = MatrixSum(matrix1, matrix3, n1);
		double** matrixOtv2 = MatrixSum(matrixOtv, matrixOtv1, n1);
		cout << "Полученная матрица = " << endl;
		Outputmas(matrixOtv2, n1);
		Clear_mas(matrixOtv, n3);
		Clear_mas(matrixOtv1, n3);
		Clear_mas(matrixOtv2, n3);
	}
	Clear_mas(matrix1, n1);
	Clear_mas(matrix2, n2);
	Clear_mas(matrix3, n3);
	
    return 0;
}
