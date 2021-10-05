#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >q;
vector<int>v;
int counter=0;
void minheap(int n,int i){
    int l=2*i+1;
    int r=2*i+2;
    int index=i;
    if(l<n && v[index]>v[l])
        index=l;
    if(r<n && v[index]>v[r])
        index=r;
    if(index!=i){
        swap(v[index],v[i]);
        q.push_back(make_pair(i,index));
        counter++;
        minheap(n,index);
    }
}
void heap(int n){
    for(int i=(n/2-1);i>=0;i--){
        minheap(n,i);
    }
}
int main(){
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        int x;cin >>x;
        v.push_back(x);
    }
    heap(n);

   cout <<counter << endl;
   for(int i=0;i<(int)q.size();i++){
        cout <<q[i].first<< " "<< q[i].second << endl;
   }
    return 0;

}
