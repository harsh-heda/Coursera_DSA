#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    map<int,string>m;
    for(int i=0;i<n;i++){
        string work,name;long long int x;
        cin >> work;
        if(work=="add"){
            cin >> x>> name;
            if(m.find(x)==m.end())
                m.insert(make_pair(x,name));
            else
                m[x]=name;
        }
        else if(work =="find"){
            cin >> x;
            if(m.find(x)!=m.end())
                cout <<m[x]<<endl;
            else
                cout <<"not found"<<endl;
        }
        else{
            cin >> x;
            m.erase(x);
        }
    }
    return 0;

}
