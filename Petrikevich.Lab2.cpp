//№5
#include <iostream>
#include <math.h>

using namespace std;

double Exponent(double, double);
double** AllocMemory(int);
void EllementsOfMyMatrix(double**, int, double);
void EllementsOfMatrix(double**, int);
void MatrixDifference(double**, double**, double**, int);
void DisplayMatrix(double**, int);
void FreeMemory(double**, int);
double MaxElementInDifference(double**, int);



int main()
{
	int n;
	double eps;
	while (true)
	{
		cout << "Please, enter size of matrix: ";
		cin >> n;
		cout << "Please, enter epsilon: ";
		cin >> eps;
		system("cls");
		if ((eps > 0 && eps < 1) || (n > 1)) break;
		cout << "Error! Please, enter other size or value of epsilon " << endl;
	}
	double** a = AllocMemory(n);
	EllementsOfMyMatrix(a, n, eps);
	//cout << "Matrix with our function: " << endl;
	//DisplayMatrix(a, n);
	double** b = AllocMemory(n);
	EllementsOfMatrix(b, n);
	//cout << endl << "Matrix with standart function: " << endl;
	//DisplayMatrix(b, n);
	double** c = AllocMemory(n);
	MatrixDifference(a, b, c, n);
	//cout << endl << "Difference:" << endl;
	//DisplayMatrix(c, n);
	double max = MaxElementInDifference(c, n);
	cout << "Epsilon:" << endl << eps << endl;
	cout << "Max ellement: " << endl;
	cout << max << endl;
	system("pause");
	FreeMemory(a, n);
	FreeMemory(b, n);
	FreeMemory(c, n);
	return 0;
}

double Exponent(double x, double eps)
{
	int i = 1;
	double sum = 0, p = 1;
	while (fabs(p) > eps)
	{
		sum += p;
		p *= x / i;
		i++;
	}
	return sum;
}

double** AllocMemory(int n)
{
	double** a = new double*[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	return a;

}

void EllementsOfMyMatrix(double** a, int n, double eps)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{

			if (i == j)
				a[i][j] = 0;
			else
				a[i][j] = (Exponent((i + j), eps) + (i + j)*(i + j)) / ((i + j)*(i + j));


		}
	}
}

void EllementsOfMatrix(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				a[i][j] = 0;
			else
				a[i][j] = (exp(i + j) + (i + j)*(i + j)) / ((i + j)*(i + j));


		}
	}
}

void MatrixDifference(double** a, double** b, double** c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = fabs(a[i][j] - b[i][j]);
		}
	}
}

double MaxElementInDifference(double** c, int n)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c[i][j] > max) max = c[i][j];
		}
	}
	return max;
}

void DisplayMatrix(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(15);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void FreeMemory(double** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}
