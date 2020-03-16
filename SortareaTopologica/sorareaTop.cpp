// sorareaTop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");

bool viz[50003];
vector<int> graf[50003];
stack <int> stck;
int n, m;

void read()
{
	f >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		f >> x >> y;
		graf[x].push_back(y);
	}
}

void DFS(int nod)
{
	viz[nod] = true;
	for (int i = 0; i < graf[nod].size(); i++)
		if (!viz[graf[nod][i]])
			DFS(graf[nod][i]);
	stck.push(nod);
}

void display()
{
	for (int i = 0; i < n; i++)
	{
		g << stck.top() << ' ';
		stck.pop();
	}
}

int main()
{
	read();

	for (int i = 1; i <= n; i++)
		if (!viz[i])
			DFS(i);

	display();
	return 0;
}


