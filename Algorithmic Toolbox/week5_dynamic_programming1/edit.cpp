#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string s,c;
    cin >>s>>c;
    int a[101][101];
    int n=(int)s.length();
    int m=(int)c.length();
    a[0][0]=0;
    for(int i=1;i<=n;i++){
        a[0][i]=i;
    }
    for(int i=1;i<=m;i++){
        a[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            if(c[j-1]==s[i-1]){
                x=a[j-1][i-1];
                a[j][i]=min(min(min(a[j-1][i]+1,a[j][i-1]+1),a[j-1][i-1]+1),x);
            }
            else
                a[j][i]=min(min(a[j-1][i]+1,a[j][i-1]+1),a[j-1][i-1]+1);
        }
    }
    cout <<a[m][n];
}
