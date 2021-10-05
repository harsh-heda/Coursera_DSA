#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int d=256;
int q=257;
void rabin(string p, string t){
    long long int len1=(long long int)p.length();
    long long int len2=(long long int)t.length();
    long long int h1=0;
    long long int h2=0;
    long long int h=1;
    for(int i=0;i<len1-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<len1;i++){
        h1=(d*h1+(int)p[i])%q;
        h2=(d*h2+(int)t[i])%q;
    }
    for(int i=0;i<=len2-len1;i++){
        if(h1==h2){
            int flag=0;
            for(int j=0;j<len1;j++){
                if(t[i+j]!=p[j])
                    flag=1;
                    break;
            }
            if(flag==0)
                cout <<i<<" ";
        }
        if(i<len2-len1){
            h2=((d*(h2-t[i]*h)+t[i+len1])%q+q)%q;
        }
    }
}
int main(){
    string p,t;
    cin >>p >> t;
    rabin(p,t);
    return 0;

}
