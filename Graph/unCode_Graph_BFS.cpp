//Program for adding Edge and Printing according to BFS(Breadth First Search)

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

    void printAdjList()
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<" : ";
            for(auto nbr: adjList[i])
            {
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }

    void BFS(int s)
    {
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty())
        {
            int f = q.front();
            cout<<f<<" ";
            q.pop();
            for(auto nbr:adjList[f])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
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
    g.addEdge(0,1,false);//write true for directed graphs
    g.addEdge(1,2,false);
    g.addEdge(0,2,false);
    g.addEdge(0,3,false);
    g.addEdge(4,5,false);
    g.addEdge(5,1,false);
    g.addEdge(3,5,false);
    g.addEdge(2,4,false);
    g.addEdge(0,4,false);

    cout<<"Printing Node in BFS manner : ";
    g.BFS(0);//Parameter -> starting node

    return 0;
}
