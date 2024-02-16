//Program for Cycle Detection in Undirected Graphs using BFS method

#include<bits/stdc++.h>
using namespace std;

class Graphs
{
    public:
    int n;
    vector<int> *adjList;

    Graphs(int n)
    {
        this->n=n;
        adjList = new vector<int>[n];
    }

    void addEdge(int u,int v,bool directed=true)
    {
        if(directed) adjList[u].push_back(v);
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    bool cycleDetectionBFS(int s)
    {
        vector<bool> visited(n,false);
        visited[s] = true;
        vector<int> parent(n);
        parent[s] = -1;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(int nbr: adjList[f])
            {
                if(!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = f;
                    q.push(nbr);
                }
                else if(parent[f]!=nbr)
                {
                    return true;
                }
            }
        }
        return false;
    }

};

int main()
{
    //input if cycle is present
    Graphs g(5);
    g.addEdge(0,1,false);
    g.addEdge(1,2,false);
    g.addEdge(2,3,false);
    g.addEdge(0,3,false);
    g.addEdge(3,4,false);
    bool check = g.cycleDetectionBFS(0);//Parameter -> Source

    if(check) cout<<"Cycle is Present";
    else cout<<"Cycle Not Present"
    return 0;
}
