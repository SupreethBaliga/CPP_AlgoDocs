#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int stck[100002];
int top,length=0;

void dfs(int i,int visited[], vector<int> graph[]) {
    visited[i]=1;
    int v;
    for(int j=0;j<graph[i].size();j++) {
        v= graph[i][j];
        if(!visited[v]) {
            dfs(v,visited,graph);
        }
    }
    stck[top]=i;
    top++;
    return;
}

void rev_dfs(int i, int revisited[],vector<int> revgraph[]) {
    revisited[i]=1;
    int v;
    for(int j=0;j<revgraph[i].size();j++) {
        v=revgraph[i][j];
        if(revisited[v]) {
            // do nothing
        }
        else {
            length++;
            rev_dfs(v,revisited,revgraph);
        }    
    }
    return;
}

void solve() {
    int n,e,u,v;
    cin>>n>>e;
    top=0;
    int maxlength=0;
    vector<int> graph[n],revgraph[n];
    int visited[n],revisited[n];
    for(int i=0;i<n;i++) {
        visited[i]=0;
        revisited[i]=0;
    }
    for(int i=0;i<e;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            dfs(i,visited,graph);
        }
    }
    for(int i=top-1;i>=0;i--) {
        if(!revisited[stck[i]]) {
            length=1;
            rev_dfs(stck[i],revisited,revgraph);
            if(maxlength<length) maxlength=length;
        }
    }
    cout<<maxlength<<'\n';
    return;
}

int main() {
    
    int q;
    cin>>q;
    while(q--) solve();
    return 0;
}
