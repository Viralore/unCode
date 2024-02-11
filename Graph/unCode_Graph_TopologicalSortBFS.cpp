//Program for Topological Sort

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

    void topologicalSortBFS()
    {
        //indegree
        vector<int> indegree(n,0);
        for(auto i=0;i<n;i++)
        {
            for(auto nbr: adjList[i])
            {
                indegree[nbr]++;
            }
        }

        //Queue
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        //bfs
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            cout<<"Task "<<f<<", ";
            for(auto nbr: adjList[f])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    //Sample Input
    Graphs g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.topologicalSortBFS();
    return 0;
}
