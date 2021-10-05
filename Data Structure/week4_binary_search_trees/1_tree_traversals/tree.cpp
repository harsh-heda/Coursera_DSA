#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int key[100004];
    int r[100004];
    int l[100004];
void printpostorder(int i,int n){
    if(l[i]==-1 && r[i]==-1){
        cout <<key[i]<<" ";
        return;
    }
    else if(l[i]==-1 && r[i]!=-1)
         printpostorder(r[i],n);
    else if(l[i]!=-1 && r[i]==-1)
         printpostorder(l[i],n);
    else{
        printpostorder(l[i],n);
        printpostorder(r[i],n);
    }
    cout << key[i]<<" ";
}
void printpreorder(int i,int n){
    cout <<key[i]<<" ";
    if(l[i]==-1 && r[i]==-1){
        return;
    }
    else if(l[i]==-1 && r[i]!=-1)
         printpreorder(r[i],n);
    else if(l[i]!=-1 && r[i]==-1)
         printpreorder(l[i],n);
    else{
        printpreorder(l[i],n);
        printpreorder(r[i],n);
    }
}
void printinorder(int i,int n){
    if(l[i]==-1 && r[i]==-1){
        cout <<key[i]<< " ";
        return;
    }
    else if(l[i]==-1 && r[i]!=-1){
        cout <<key[i]<< " ";
        printinorder(r[i],n);
    }
    else if(l[i]!=-1 && r[i]==-1){
        printinorder(l[i],n);
        cout <<key[i]<<" ";
    }
    else{
        printinorder(l[i],n);
        cout <<key[i] << " ";
        printinorder(r[i],n);
    }
}
int main(){
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> key[i]>> l[i]>>r[i];
    }
    printinorder(0,n);
    cout <<endl;
    printpreorder(0,n);
    cout <<endl;
    printpostorder(0,n);
}
