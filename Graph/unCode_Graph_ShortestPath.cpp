//Program for Printing Shortest Path b/w Source and Destination

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

    void BFS_ShortestPath(int s,int d)
    {
        vector<bool> visited(n,false);
        vector<int> dist(n,INT16_MAX);
        vector<int> parent(n,-1);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        dist[s] = 0;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(auto nbr:adjList[f])
            {
                if(!visited[nbr])
                {
                    dist[nbr] = dist[f]+1;
                    parent[nbr] = f;
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        int temp = d;
        vector<int> path;
        path.push_back(temp);
        while(parent[temp]!=-1)
        {
            temp = parent[temp];
            path.push_back(temp);
        }
        reverse(path.begin(),path.end());
        for(int i : path)
        {
            cout<<i<<" ";
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

    //Shortest path b/w 0 and 5
    g.BFS_ShortestPath(0,5);

    return 0;
}
