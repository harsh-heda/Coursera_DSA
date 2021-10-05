#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int n;
bool bfs(vector<vector<int> > residual,int s,int t,int parent[]){
    vector<bool> visited(n+1,false);
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<residual[u].size();i++){
            if(residual[u][i]>0 && visited[i]==false){
                q.push(i);
                parent[i]=u;
                visited[i]=true;
            }
        }
    }
    return (visited[t]==true);
}
int fordfeg(vector<vector<int> > cap,int s,int t){
    vector<vector<int> >residual(n+1,vector<int>(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            residual[i][j]=cap[i][j];
        }
    }
    int parent[n+1];
    int ans=0;
    while(bfs(residual,s,t,parent)){
        int counter=INT_MAX;
        for(int v=t;v!=s;v=v[parent]){
            int u=parent[v];
            counter=min(counter,residual[u][v]);
        }
        for(int v=t;v!=s;v=v[parent]){
            int u=parent[v];
            residual[u][v]-=counter;
            residual[v][u]+=counter;
        }
        ans+=counter;
    }
    return ans;

}
int main() {
    int m;
    cin >>n>>m;
    vector<vector<int> >cap(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int x,y,c;cin>>x>>y>>c;
        if(cap[x][y]!=0)
            cap[x][y]+=c;
        else
            cap[x][y]=c;
    }
    cout <<fordfeg(cap,1,n);
  /*  for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout <<cap[i][j]<< " ";
        }
        cout <<endl;
    }*/
    return 0;
}
