// Floyd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");

int n, a[103][103];//matricea ponderilor

void read()
{
	f >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			f >> a[i][j];
}

void royFloyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j)
					a[i][j] = a[i][k] + a[k][j];

}

void display()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			g << a[i][j] << ' ';
		g << endl;
	}
}

int main()
{
	read();
	royFloyd();
	display();
}

