//Program for Cycle Detection in Graph using DFS

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
    bool cycleDetectionDFS(int s,int parent,vector<bool>& visited)
    {
        visited[s]=true;
        for(int nbr : adjList[s])
        {
            if(!visited[nbr])
            {
                bool cycleFound = cycleDetectionDFS(nbr,s,visited);
                if(cycleFound) return true;
            }
            else if(nbr!=parent)
            {
                return true;
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
    vector<bool> visited(5,false);

    bool check = g.cycleDetectionDFS(0,-1,visited);//Parameter -> Source,Parent & visited array

    if(check) cout<<"Cycle is Present";
    else cout<<"Cycle Not Present";
    return 0;
}
