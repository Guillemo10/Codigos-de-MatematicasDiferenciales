#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> padre;

void init(int n)
{
    padre.resize(n);
    for (int i = 0; i < n; i++)
        padre[i] = i;
}

int find_set(int v)
{
    if (v == padre[v])
        return v;
    return padre[v] = find_set(padre[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    padre[b] = a;
}

vector<pair<int, pair<int,int>>> list;

int kruskal(int n, int m)
{
    sort(list.begin(), list.end());
    init(n);
    int sinusar = n, pos = 0, peso = 0;
    while (sinusar != 1 && pos < m)
    {
        pair<int, pair<int,int>> curr = list[pos];
        
        if(find_set(curr.second.first) != find_set(curr.second.second))
            {
                union_sets(curr.second.first, curr.second.second);
                cout << curr.second.first << "-" << curr.second.second <<endl;
                peso += curr.first;
                sinusar --;
            }
        pos ++;
    }
    return peso;
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    list.resize(m);
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        list[i] = {c, {a, b}};
    }

    cout << kruskal(n, m) << endl;
}
