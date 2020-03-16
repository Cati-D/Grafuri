#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <utility>
#include <queue>

using namespace std;

ifstream f("prim.in");
ofstream g("prim.out");

vector <pair<int, int> > graph[10000]; //liste de adiacenta
int V, E;
//V - number of vertices
//E - number of edges
int vis[10000], t[10000];
int d[10000];
int str;

void read()
{
     int s, dr, w;
    //s - source
    //d - destination
    //w - weight

    f>>V>>E;
    cout<<"Introduceti nodul sursa: ";
    cin>>str;

    for(int i = 0; i < V; i++)
    {
        f>>s>>dr>>w;
        graph[s].push_back({dr, w});
        graph[dr].push_back({s, w});
    }
    for (int i = 1; i <= E; i++)
        d[i] = 1000;
    d[str] = 0;
}

void Prim()
{
    priority_queue<pair<int, int> > myQueue;
    myQueue.push({-d[str], str});
    int x, y, j, i;

    while(!myQueue.empty())
    {
        x = myQueue.top().second; //nod
        myQueue.pop();
        vis[x]++;
        //vector<pair<int, int> >::iterator it = graph.begin(); //e echivalent cu auto
        for (auto i: graph[x]) //vecinii lui x
        {
            y = i.first;
            j = i.second;
            if (!vis[y] && d[y]>j)
            {
                t[y] = x;
                d[y] = j;
                myQueue.push({-d[y], y});
            }
        }
    }
}

void display()
{
    for (int i = 1; i <= E; i++)
        g<<d[i]<<endl;
    //Perechi de muchii APM
    for(int i = 1; i <= E; i++)
        if (t[i])
            cout<<t[i]<<" "<<i<<endl;

}

int main()
{
    read();
    Prim();
    display();
    return 0;
}
