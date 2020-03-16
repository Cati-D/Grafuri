#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream f("kruskal.in");
ofstream g("kruskal.out");

vector <pair<pair<int, int>, int> > graph;
int V, E;
//V - number of vertices
//E - number of edges

vector <pair<pair<int, int>, int> > newGraph;
int vis[10003];

//compare 2 edges according to theur weights
bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int>  y)
{
    return x.second < y.second;
}

void read()
{
    int s, d, w;
    //s - source
    //d - destination
    //w - weight
    f>>V>>E;
    //graph = new vector <int>* [E];
    for(int i = 0; i < E; i++)
    {
        f>>w>>s>>d;
        graph.push_back(make_pair(make_pair(s, d), w));
    }

    //sort all the edges in increasing order after their weight
    sort(graph.begin(), graph.end(), cmp);
}

void DFS(int edge)
{
    vis[edge]= 1;
    vector <pair<pair<int, int>, int> >::iterator itv = newGraph.begin();
    for (itv = newGraph.begin(); itv != newGraph.end(); itv++)
    {
        if (itv->first.first == edge)
        {
            vis[edge] = 1;
            int ngh = itv->first.second;
            if(!vis[ngh])
                DFS(ngh);
        }
        else if (itv->first.second == edge)
        {
            vis[edge] = 1;
            int ngh = itv->first.first;
            if(!vis[ngh])
                DFS(ngh);
        }
    }

}

void display();

void Kruskal()
{
    for (int i = 0; i <= E; i++)
        vis[i] = 0;
    vector <pair<pair<int, int>, int> >::iterator itv = graph.begin();
    for (itv = graph.begin(); itv != graph.end(); itv++)
    {
        for (int i = 0; i <= E; i++)
            vis[i] = 0;
        DFS(itv->first.first);
        if (!vis[itv->first.second])
            newGraph.push_back(make_pair(make_pair(itv->first.first, itv->first.second), itv->second));
    }
}

void display()
{
    vector <pair<pair<int, int>, int> >::iterator itv = newGraph.begin();
    h<<"dim "<<newGraph.size()<<endl;
    for (itv = newGraph.begin(); itv != newGraph.end(); itv++)
        h<<itv->first.first<<' '<<itv->first.second<<' '<<itv->second<<endl;
}

int main()
{
    read();
    Kruskal();
    display();

    return 0;
}
