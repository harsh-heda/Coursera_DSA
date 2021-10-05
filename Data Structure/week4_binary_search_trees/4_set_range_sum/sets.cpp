#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int m=1000000001;
int main(){
    set<int>s;
    int n;
    cin >>n;
    int sum=0;
    for(int i=0;i<n;i++){
        char sign;cin >>sign;
        if(sign=='?'){
            int x;cin >>x;
            if(s.find((x+sum)%m)!=s.end())
                cout <<"Found"<<endl;
            else
                cout << "Not found"<<endl;
        }
        else if(sign=='+'){
            int x;cin >>x;
            s.insert((x+sum)%m);
          //  for(auto it=s.begin();it!=s.end();it++){
             //   cout <<*it << " ";
            //}
        }
        else if(sign=='-'){
            int x;cin >>x;
            if(s.find((x+sum)%m)!=s.end())
                s.erase((x+sum)%m);
        }
        else{
            int l,r,ans=0;cin >>l>>r;
            for(auto it=s.begin();it!=s.end();it++){
                if(*it>=((l+sum)%m)&& *it<=((r+sum)%m))
                    ans=ans+(*it);
            }
            cout <<ans<<endl;
            sum=ans;
        }
    }
}

