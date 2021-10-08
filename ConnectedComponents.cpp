#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void DFS(int v,map<int,bool> &visited,map<int,vector<int>> adj, vector<int> &vec){
    visited[v]=true;
    vec.push_back(v);
    vector<int> ::iterator itr;
    for(itr=adj[v].begin();itr!=adj[v].end();itr++){
        if(!visited[*itr]){
            DFS(*itr,visited,adj,vec);
        } 
    }
}

void DFSUtil(map<int,bool> &visited,map<int,vector<int>> adj){
    int count=0;
    map<int,vector<int>> components;
    vector<int> vec;
    for(auto i:adj){
        if(!visited[i.first]){
            DFS(i.first,visited,adj,vec);
            count++;
            components[count]=vec;
            vec.clear();
        } 
    }
    cout<<"Number of connected components"<<count<<endl;
    for(auto i:components){
        cout<<"Components number: "<<i.first<<" are : ";
        for(int j=0;j<i.second.size();j++){
            cout<<i.second[j]<<" ";
        }
        cout<<endl;
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

