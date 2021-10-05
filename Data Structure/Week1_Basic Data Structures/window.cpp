#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,k;
   cin >>n;
   int a[n+2];
   for(int i=0;i<n;i++){
    cin >>a[i];
   }
   cin >>k;
   deque<int>q;
   for(int i=0;i<k;i++){
        while(q.empty()==false && a[i]>=a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
   }
   for(int i=k;i<n;i++){
        cout<<a[q.front()] << " ";
        while(q.empty()==false && q.front()<=i-k){
            q.pop_front();
        }
        while(q.empty()==false && a[i]>=a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
   }
   cout <<a[q.front()];
}

