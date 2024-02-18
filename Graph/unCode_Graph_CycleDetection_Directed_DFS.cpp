//Program for cycle detection in directed graph using DFS

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

    bool cycleDetectionDFS(int s,vector<bool>& visited,vector<bool>& callStack)
    {
        visited[s] = true;
        callStack[s] = true;
        for(int nbr : adjList[s])
        {
            if(!visited[nbr])
            {
                bool cycleFound = cycleDetectionDFS(nbr,visited,callStack);
                if(cycleFound) return true;
            }
            else if(callStack[nbr])
            {
                return true;
            }
        }
        callStack[s] = false;
        return false;
    }

};

int main()
{
    //input if cycle is present
    Graphs g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(3,0);
    vector<bool> visited(5,false);
    vector<bool> callStack(5,false);
    bool check = g.cycleDetectionDFS(0,visited,callStack);
    if(check) cout<<"Cycle is Present";
    else cout<<"Cycle is not present";
    return 0;
}
