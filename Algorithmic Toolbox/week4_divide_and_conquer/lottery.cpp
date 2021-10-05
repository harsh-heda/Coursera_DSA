#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int s,p;
    cin>>s >> p;
    pair<long long int, long long int>a[s+5];
    long long int b[p+5];
    for(int i=0;i<s;i++){
        cin >>a[i].first >> a[i].second;
    }
    for(int i=0;i<p;i++){
        cin >>b[i];
    }
    sort(a,a+s);
  //  for(int i=0;i<s;i++){
    //    cout<<a[i].first << a[i].second;
    //}
    for(int i=0;i<p;i++){
        int counter=0;
        if(b[i]<a[0].first){
            cout <<0 << " ";
            continue;
        }
        for(int j=0;j<s;j++){
            if(b[i]>=a[j].first && b[i]<=a[j].second)
                counter++;
        }
        cout << counter << " ";
    }
    return 0;
}
