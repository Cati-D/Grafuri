#include <iostream>
#include <fstream>
#include <vector>
//findFather-functie care cauta tatal unui nod
//tata[i]
//grad[i]-cate componenete are componeenta conexa
//if (grad[fx] < grad[fy]) {tata[fx] = fy;grad[fy]+=graf[fx];}//fx/y - findFather(x/y)

using namespace std;

ifstream f("disjoint.in");
ofstream g("disjoint.out");

int tata[100003];
int grad[100003];
int N, M;
//N - nr de noduri
//M - nr operatii efectuate

int findFather(int node)
{
    if (tata[node] == node)
        return node;
    return findFather(tata[node]);//optimizare pentru ca actualizez tata[node]
}

void read_Disj()
{
    f>>N>>M;
    int k, s, d;
    //k - cheie
    //s - sursa
    //d - destinatie

    for (int i = 1; i <= N; i++)
    {
        tata[i] = i;
        grad[i] = 1;
    }

    int fs, fd;

    for (int i = 0; i < M; i++)
    {
        f>>k>>s>>d;
        fs = findFather(s);
        fd = findFather(d);
        if (k == 1)
            {  if (fs != fd)
                    if (grad[fs] <= grad[fd])
                    {
                        tata[fs] = fd;
                        grad[fd]+=grad[fs];
                    } else
                    {
                        tata[fd] = fs;
                        grad[fs]+=grad[fd];
                    }
            }
            else if (k == 2)
            {
                if (fs == fd)
                    g<<"DA"<<'\n';
                else g<<"NU"<<'\n';
            }

    }

}

int main()
{
    read_Disj();
    return 0;
}
