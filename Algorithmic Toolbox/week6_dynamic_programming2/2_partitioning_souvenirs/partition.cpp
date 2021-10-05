#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int part3(int val,int n,vector<int>a, int no){
    vector< vector<int> > arr(n+1,vector<int>(val+1));
    for(int q=1;q<=no;q++){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=val;j++){
            if(i==0 || j==0)
                arr[i][j]=0;
            else{
                if(a[i]<=j){
                    arr[i][j]=max(arr[i-1][j],arr[i-1][j-a[i]]+a[i]);
                }
                else
                    arr[i][j]=arr[i-1][j];
            }
        }
    }
    }
    return arr[n][val];
}
int main()
{
    int n;
    cin >>n;
    vector<int> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        sum+=a[i];
    }

    if(sum%3==0){
        if(part3(sum/3,n,a,1)==sum/3 && part3(2*sum/3,n,a,2)==2*sum/3 && part3(sum,n,a,3)==sum)
            cout <<1;
        else
            cout <<0;
    }
    else{
        cout <<0;
    }
}
