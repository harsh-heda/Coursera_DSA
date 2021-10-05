#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<long long int> table(100004),ra(100004,1),val(100004);
long long int ma=0;
long long int getparent(long long int x){
    if(table[x]!=x)
        getparent(table[x]);
    return x;
}
int jointset(long long int s,long long int d){
    long long int source=getparent(s);
    long long int dest=getparent(d);
    if(source==dest)
        return ma;
    else if(ra[dest]>=ra[source]){
        table[source]=dest;
        val[dest]+=val[source];
        val[source]=0;
        if(ma<val[dest])
            ma=val[dest];
        return ma;
    }
    else if(ra[dest]<ra[source]){
        table[dest]=source;
        val[source]+=val[dest];
        val[dest]=0;
        if(ma<val[source])
            ma=val[source];
        if(ra[source]==ra[dest])
            ra[source]++;
    }
}
int main(){
    int n,q;
    cin >>n>>q;
    for(int i=1;i<=n;i++){
        cin >>val[i];
        if(val[i]>ma)
            ma=val[i];
    }
    for(int i=1;i<=n;i++){
        table[i]=i;
    }
    for(int i=0;i<q;i++){
        long long int s,d;cin >>s>>d;
        cout <<jointset(s,d)<<endl;
    }
}

