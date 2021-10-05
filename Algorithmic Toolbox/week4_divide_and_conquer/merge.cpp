#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int merg(int arr[],int temp[],int l,int m,int r){
    int i=l,j=m,k=l;
    int counter=0;
    while(i<=(m-1) && j<=r){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            counter+=(m-i);
        }
    }
        while(i<=m-1){
            temp[k++]=arr[i++];
        }
        while(j<=r){
            temp[k++]=arr[j++];
        }
        for(int i=l;i<=r;i++){
            arr[i]=temp[i];
        }
        return counter;
}
int mergesort2(int arr[],int temp[],int l,int r){
    int counter=0;
    if(r>l){
        int m=(l+r)/2;
        counter+=mergesort2(arr,temp,l,m);
        counter+=mergesort2(arr,temp,m+1,r);
        counter+=merg(arr,temp,l,m+1,r);
    }
     return counter;
}
int mergesort(int arr[],int n){
    int temp[n];
    mergesort2(arr,temp,0,n-1);
}
int main()
{
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    int x;
    x=mergesort(a,n);
    cout <<x;
}
