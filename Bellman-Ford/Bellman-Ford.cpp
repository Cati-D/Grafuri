// Bellman-Ford.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Se dă un graf orientat conex cu N noduri şi M muchii cu costuri. Definim un lanţ ca 
fiind un şir de noduri cu proprietatea că între oricare două consecutive există o 
muchie. Costul unui lanţ este dat de suma costurilor muchiilor care unesc nodurile ce 
îl formează. Definim un ciclu ca fiind un lanţ cu proprietatea că primul element al său
este egal cu ultimul.
*/

/*Să se determine dacă în graful dat există un ciclu de cost negativ. Dacă nu există, să 
se determine costul minim al unui lanţ de la nodul 1 la fiecare dintre nodurile 2, 3, 
... , N-1, N.
*/

///INPUT
//Fişierul de intrare bellmanford.in conţine pe prima linie numerele N şi M cu 
//semnificaţia din enunţ. Pe următoarele M linii se vor afla câte 3 numere x, y şi c cu 
//semnificaţia că există o muchie de cost c de la nodul x la nodul y.

///OUTPUT
//În fişierul de ieşire bellmanford.out se va afişa pe prima linie mesajul "Ciclu 
//negativ!" dacă în graf există un astfel de ciclu sau, în caz contrar, N-1 numere 
//separate printr-un spaţiu. Al i-lea număr va reprezenta costul minim al unui lanţ de 
//la nodul 1 la nodul i+1.

//1 ≤ N ≤ 50 000, 1 ≤ M ≤ 250 000
//Costurile muchiilor sunt numere întregi cel mult egale în modul cu 1 000.


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <list>
#include <utility>

using namespace std;

vector<pair<int, int> > adj[50010];
vector<int> adj_t[50010];
int n, m;
queue <int> myQueue;
int dist[50010];
int viz[50010];
int neg_cyc = 0;
int inf = 100000;

ifstream f("bellmanford.in");
ofstream g("bellmanfort.out");

void read()
{
	f >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		f >> x >> y >> c;
		adj[x].push_back({ y, c });
		adj_t[x].push_back(y);
	}
}

void Bellman_Ford()
{
	for (int i = 1; i <= n; i++)
		dist[i] = inf;

	myQueue.push(1);
	while (!myQueue.empty() && !neg_cyc)
	{
		int x = myQueue.front();
		myQueue.pop();
		for (auto i : adj[x])
			if (dist[x] < inf)
				if (dist[i.first] > dist[x] + i.second)
				{
					dist[i.first] = dist[x] + i.second;
					if (!viz[i.first])
						neg_cyc = 1;
					else
					{
						myQueue.push(i.first);
						viz[i.first] = 1;
					}
				}

	}
}

void display()
{
	if (!neg_cyc)
		for (int i = 2; i <= n; i++)
			g << dist[i] << " ";
	else
		g << "Ciclu negativ!\n";
}

int main()
{
	read();
	Bellman_Ford();
	display();
}

