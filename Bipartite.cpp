#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int flag;

void dfs(int i,int visited[],int group[], vector <int> graph[],int grp) {
    int v;
    group[i]=grp;
    visited[i]=1;
    for(int j=0;j<graph[i].size();j++) {
        v=graph[i][j];
        if(!visited[v]) {
            dfs(v,visited,group,graph,!grp);
        } 
        else {
            if(group[v]==0 && grp==0) {
                flag=0;
                return;
            }
            else if(group[v]==1 && grp==1) {
                flag=0;
                return;
            }
            //else do nothing
        }
    }

}

void solve() {
    flag=1;
    int n,e,u,v;
    scanf("%d %d",&n,&e);
    vector <int> graph[n+1];
    int visited[n+1];
    int group[n+1];
    for(int i=1;i<=n;i++) {
        visited[i]=0;
        group[i]=-1;
    }
    for(int i=0;i<e;i++) {
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int grp=0;
    for(int i=1;i<=n;i++) {
        if(flag==0) {
            break;
        }
        if(!visited[i]) {
            dfs(i,visited,group,graph,grp);
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
}

int main() {
    int q;
    cin>>q;
    while(q--) solve();
    return 0;
}