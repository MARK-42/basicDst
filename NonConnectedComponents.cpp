#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void DFS(int v,map<int,bool> &visited,map<int,vector<int>> adj){
    visited[v]=true;
    cout<<v<<" ";
    vector<int> ::iterator itr;
    for(itr=adj[v].begin();itr!=adj[v].end();itr++){
        if(!visited[*itr]){
            DFS(*itr,visited,adj);
        } 
    }
}

void DFSUtil(map<int,bool> &visited,map<int,vector<int>> adj){
    for(auto i:adj){
        if(!visited[i.first]){
            DFS(i.first,visited,adj);
        } 
    }
}

int main()
{
    map<int,bool> visited;
    map<int,vector<int>> adj;
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int start,end;
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }    
    DFSUtil(visited,adj);
    return 0;
}

