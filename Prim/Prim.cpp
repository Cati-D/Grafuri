// Prim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//arborele partial de cost minim 

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");
vector<pair<int, int> > graf[200005];
priority_queue<pair<int, pair<int, int> > > coada[200005];
pair<int, pair<int, int> > elem;
pair<int, int> v[200005];
int n, m;
int nrt, nrv = 0;
bool viz[200005];

void read()
{
	f >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		f >> x >> y >> c;
		graf[x].push_back(make_pair(y, c));
		graf[y].push_back(make_pair(x, c));
	}
}

void Prim()
{
	viz[1] = true;
	for (int i = 0; i < graf[1].size(); i++)
		coada->push(make_pair( -graf[1][i].second, make_pair(1, graf[1][i].first)));

	m = n - 1;
	while (m)
	{
		elem = coada->top();
		coada->pop();
		if (!viz[elem.second.first])
		{
			viz[elem.second.first] = true;
			for (int i = 0; i < graf[elem.second.first].size(); i++)
				if (!viz[graf[elem.second.first][i].first])
					coada->push({ -graf[elem.second.first][i].second, {elem.second.first, graf[elem.second.first][i].first} });
		}

		else
		{
			if (!viz[elem.second.second])
			{
				viz[elem.second.second] = true;
				for (int i = 0; i < graf[elem.second.second].size(); i++)
					if (!viz[graf[elem.second.second][i].first])
						coada->push({ -graf[elem.second.second][i].second, {elem.second.second, graf[elem.second.second][i].first} });
			}
			else
				continue;
		}

		nrt += -elem.first;
		--m;
		v[++nrv] = elem.second;
	}
}

void display()
{
	g << nrt << '\n' << n - 1 << '\n';
	for (int i = 1; i <= nrv; i++)
	{
		g << v[i].first << " " << v[i].second << '\n';
	}
}

int main()
{
	read();
	Prim();
	display();
}


