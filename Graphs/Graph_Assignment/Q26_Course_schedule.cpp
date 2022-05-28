//Algo - Checking if given graph is DAG using BFS 
#include <bits/stdc++.h> 
using namespace std; 
class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
    int V=numCourses;
    vector<int> in_degree(V, 0); 
    vector<unordered_set<int>>adj(V);

    for(int i=0;i<prerequisites.size();i++)
    {
        int u=prerequisites[i][0];
        int v=prerequisites[i][1];

        adj[v].insert(u);
        in_degree[u]++;
    }
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    int cnt = 0; 

    while (!q.empty()) { 
        int u = q.front(); 
        q.pop();   
        for (auto itr : adj[u]) 
            {
                in_degree[itr]--;
                if(in_degree[itr] == 0) 
                    q.push(itr); 
            }
        cnt++; 
    } 
  
    if (cnt == V)  
        return true; 
    else
        return false; 
    }
};
