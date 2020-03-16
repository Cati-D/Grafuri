// dijkstra n2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#define pb push_back
#define oo 99999999

using namespace std;

ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

vector<pair<int, int> > g[50005];
int n, m;
int d[50005];
bool v[50005];

void read()
{
	in >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		in >> x >> y >> c;
		g[x].pb({ y, c });
	}
	for (int i = 1; i <= n; i++)
		d[i] = oo;
}

void dijkstra()
{
	d[1] = 0;
	int mnm, idx;
	for (int i = 1; i <= n; i++)
	{
		mnm = oo;
		for (int j = 1; j <= n; j++)
		{
			if (!v[j] && d[j] < mnm)
			{
				mnm = d[j];
				idx = j;
			}
		}
		v[idx] = true;
		for (auto j:g[idx])
			if (d[idx] + j.second < d[j.first])
			{
				d[j.first] = d[idx] + j.second;
			}
	}
}

void display()
{
	for (int i = 2; i <= n; i++)
		if (d[i] == oo)
			out << "0" << ' ';
		else
			out << d[i] << ' ';
}




int main()
{
	read();
	dijkstra();
	display();

	return 0;

}
