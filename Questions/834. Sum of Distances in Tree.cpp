/*
834. Sum of Distances in Tree

There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node,int par,vector<vector<int> >& tree,vector<int>& noc)
    {
        int ans=1;
        for(auto itr:tree[node])
        {
            if(itr!=par)
            {
                dfs(itr,node,tree,noc);
                ans+=noc[itr];
            }
        }
        noc[node]=ans;
    }

    void dfs2(int node,int par,int dist,int& tot_dist,vector<vector<int> >& tree)
    {
        tot_dist+=dist;
        for(auto itr:tree[node])
        {
            if(itr!=par)
            {
                dfs2(itr,node,dist+1,tot_dist,tree);
            }
        }
    }
    void dfs3(int node,int par,vector<int>& tot_dist,vector<vector<int> >& tree,vector<int>& noc)
    {
        if(par!=-1)
        {
            tot_dist[node] = tot_dist[par]-noc[node]+(noc.size()-noc[node]);
        }
        for(auto itr:tree[node])
        {
            if(itr!=par)
            {
                dfs3(itr,node,tot_dist,tree,noc);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> noc(n);
        vector<vector<int> > tree(n);
        for(int i =0 ;i<n-1;i++)
        {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,tree,noc);
        vector<int> tot_dist(n);
        dfs2(0,-1,0,tot_dist[0],tree);
        dfs3(0,-1,tot_dist,tree,noc);
        return tot_dist;


    }
};



int main()
{
    return 0;
}
