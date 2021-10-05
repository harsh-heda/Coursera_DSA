#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int p=1000000007;
int x=263;
long long int calchash(string s,long long int b){
    long long int ans=0;
    int t=s.length();
    for(int i=t-1;i>=0;i--){
        ans=(ans*x+s[i])%p;
    }
    return ans%b;
}
int main(){
    list<pair<string,long long int> >m;
    long long int b,q;cin >>b>>q;
    for(int i=0;i<q;i++){
        string w,word;
        cin >>w;
        if(w=="add"){
            cin >>word;
            int flag=0;
            for(auto it=m.begin();it!=m.end();it++){
                if(it->first==word){
                    flag=1;
                    break;
                }
            }
            if(!flag)
                m.insert(m.begin(),make_pair(word,calchash(word,b)));
        }
        else if(w=="del"){
            cin >>word;
            for(auto it=m.begin();it!=m.end();it++){
                if(it->first==word){
                    m.erase(it);
                    break;
                }
            }
        }
        else if(w=="find"){
            cin >>word;
            int flag=0;
            for(auto it=m.begin();it!=m.end();it++){
                if(it->first==word){
                    flag=1;
                    break;
                }
            }
            if(flag)
                cout <<"yes"<<endl;
            else
                cout <<"no"<<endl;
        }
        else{
            long long int no;cin >>no;
            for(auto it=m.begin();it!=m.end();it++){
                if(it->second==no)
                    cout <<it->first<< " ";
            }
            cout <<endl;
        }
    }
}

