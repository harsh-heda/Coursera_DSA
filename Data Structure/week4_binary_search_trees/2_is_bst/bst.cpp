#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int key[100004];
    int r[100004];
    int l[100004];
bool isbst(int i,int mi,int ma){
    if(key[i]<mi)
        return false;
    else if(key[i]>ma)
        return false;
    else if(r[i]==-1 && l[i]==-1)
        return true;
    else if(r[i]==-1)
        return (true && isbst(l[i],mi,key[i]));
    else if(l[i]==-1)
        return (isbst(r[i],key[i],ma) && true);
    return (isbst(r[i],key[i],ma) && isbst(l[i],mi,key[i]));

}
int main(){
    int n;
    cin >>n;
    if(n==0){
        cout <<"CORRECT";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin >> key[i]>> l[i]>>r[i];
    }
    int ma = std::numeric_limits<int>::max();
    int mi = std::numeric_limits<int>::min();
    if(isbst(0,mi,ma))
        cout <<"CORRECT";
    else
        cout <<"INCORRECT";
}
