#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void BFS(int root,map<int,bool> &visited,map<int,vector<int>> adj){
    visited[root]=true;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int temp=q.front();
        cout<<temp<<" ";
        q.pop();
        
        for(int j=0;j<adj[temp].size();j++){
            if(!visited[adj[temp][j]]){
                visited[adj[temp][j]]=true;
                q.push(adj[temp][j]);    
            }
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
    int root;
    cin>>root;
    BFS(root,visited,adj);
    return 0;
}

