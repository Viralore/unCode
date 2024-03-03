//Program for solving Traveling Salesman

#include<bits/stdc++.h>
using namespace std;

int tsp(int dist[][10],int n, int city, int visited)
{
	//base case
	if(visited==(1<<n)-1)
    {
		// 1111111
		return dist[city][0]; // last node se 0th node edge cost
	}

	// rec case
	// give city se jaha jaha visit kr skte hai, vaha call krke min lenge
	// visit all unvisited cities and take the best / min cost '
	int ans = INT_MAX;
	for(int nbr=0;nbr<n;nbr++)
    {
		if((visited & (1<<nbr)) == 0)
		{
            int cost = dist[city][nbr] + tsp(dist,n,nbr, visited|(1<<nbr));
            ans = min(cost,ans);
		}
	}
	return ans;
}

int main(){

	int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
	};
	int n = 4;
	cout<< tsp(dist,n,0,1)<<endl;
	return 0;
}
