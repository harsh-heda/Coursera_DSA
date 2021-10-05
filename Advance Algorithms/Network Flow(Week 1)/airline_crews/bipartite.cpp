#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int n,m;
bool bfs(vector<vector<bool> > residual,int s,int t,int parent[]){
    vector<bool> visited(n+m+2,false);
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        if(u==t)
            break;
        q.pop();
        for(int i=0;i<=n+m+1;i++){
            if(residual[u][i]==true && visited[i]==false){
                q.push(i);
                parent[i]=u;
                visited[i]=true;
            }
        }
    }
    return (visited[t]==true);
}
void fordfeg(vector<vector<bool> > cap,int s,int t){
    vector<vector<bool> >residual(n+m+2,vector<bool>(n+m+2));
    for(int i=0;i<=n+m+1;i++){
        for(int j=0;j<=n+m+1;j++){
            residual[i][j]=cap[i][j];
        }
    }
    int parent[n+m+2];
    while(bfs(residual,s,t,parent)){
        for(int v=t;v!=s;v=v[parent]){
            int u=parent[v];
            residual[u][v]=0;
            residual[v][u]=1;
        }
    }
    vector<int>creq;
    vector<bool> freq(n+1,false);
    for(int i=n+1;i<=n+m;i++){
        if(!freq[parent[i]]){
            freq[parent[i]]=true;
            creq.push_back(parent[i]);
        }
    }
    for(auto it=creq.begin();it!=creq.end();it++){
        if(*it==0)
            cout <<-1<< " ";
        else
            cout << *it<< " ";
    }
}
int main() {
    cin >>n>>m;
    vector<vector<bool> >cap(n+m+2,vector<bool>(n+m+2,false));
    for(int i=1;i<=n;i++){
        cap[0][i]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=n+1;j<=n+m;j++){
            int x;cin>>x;
            cap[i][j]=x;
        }
    }
    for(int i=n+1;i<=n+m;i++){
        cap[i][n+m+1]=true;
    }
    fordfeg(cap,0,n+m+1);
  /*  for(int i=0;i<=n+m+1;i++){
        for(int j=0;j<=n+m+1;j++){
            cout <<cap[i][j]<< " ";
        }
        cout <<endl;
    }*/
    return 0;
}
