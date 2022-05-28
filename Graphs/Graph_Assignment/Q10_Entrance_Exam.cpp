//Algo - Slight Modification of Dijkstras algorithm
#include<bits/stdc++.h> 
using namespace std; 

set< pair<int, int> > setds;  
vector<int> dist;  

class Graph 
{ 
	int V; 
	list< pair<int, int> > *adj; 

public: 
	Graph(int V); 
	void addEdge(int u, int v, int w); 
	void shortestPath(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list< pair<int, int> >[V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

void Graph::shortestPath() 
{ 
	while (!setds.empty()) 
	{ 
		pair<int, int> tmp = *(setds.begin()); 
		setds.erase(setds.begin()); 
		int u = tmp.second; 

		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
			int v = (*i).first; 
			int weight = (*i).second; 
			if (dist[v] > dist[u] + weight) 
			{ 
				if (dist[v] != INT_MAX) 
					setds.erase(setds.find(make_pair(dist[v], v))); 
				dist[v] = dist[u] + weight; 
				setds.insert(make_pair(dist[v], v)); 
			} 
		} 
	} 

	// printf("Vertex Distance from Source\n"); 
	// for (int i = 0; i < V; ++i) 
	// 	printf("%d \t\t %d\n", i, dist[i]); 
} 

int main()
{
  int N,M,K,Q,i;
  scanf("%d %d %d %d",&N,&M,&K,&Q);
  Graph g(N);
  for(i=0;i<M;i++)
  {
    int U,V;
    int W;
    scanf("%d %d %d",&U,&V,&W);
    g.addEdge(U-1,V-1,W);
  }
  dist.resize(N+1,INT_MAX);
  for(i=0;i<K;i++)
  {
    int k;
    scanf("%d",&k);
    setds.insert(make_pair(0,k-1));
    dist[k-1]=0;
  }
  g.shortestPath();
  for(i=0;i<Q;i++)
  {
    int X;
    scanf("%d",&X);
    if(dist[X-1]==INT_MAX) printf("-1\n");
    else printf("%d\n",dist[X-1]);
  }
}