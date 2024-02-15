//Program for Topological Sort DFS

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

    void topologicalSortDFSHelper(int start,vector<bool>& visited,vector<int>& output)
    {
        //call the children -> push the node
        visited[start] = true;
        for(auto nbr : adjList[start])
        {
            if(!visited[nbr])
            {
                topologicalSortDFSHelper(nbr,visited,output);
            }
        }
        output.push_back(start);
        return;
    }

    void topologicalSortDFS()
    {
        vector<int> output;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                topologicalSortDFSHelper(i,visited,output);
            }
        }
        reverse(output.begin(),output.end());
        for(int x: output)
        {
            if(x!=output[output.size()-1]) cout<<"Task : "<<x<<"-> ";
            else cout<<"Task : "<<x;
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
    g.topologicalSortDFS();
    return 0;
}
