#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    vector<int> a(n+5);
    if(n==1){
        cout << 0 << endl << 1;
        return 0;
    }
    a[0]=0;
    a[1]=0;
    a[2]=1;
    a[3]=1;
    for(int i=4;i<=n;i++){
        if(i%6==0)
            a[i]=min(min(a[(i-1)/2]+1,a[i/2]+1),a[i/3]+1);
        else if(i%2==0)
            a[i]=min(a[i/2]+1,a[i-1]+1);
        else if(i%3==0)
            a[i]=min(a[i/3]+1,a[i-1]+1);
        else{
            if((i-1)%3==0)
            a[i]=1+min(min(a[(i-1)/2]+1,a[i-2]+1),a[(i-1)/3]+1);
            else if((i-1)%2==0)
            a[i]=1+min(a[(i-1)/2]+1,a[i-2]+1);
        }
    }
    vector<int>q;
    cout <<a[n] <<endl;
    q.push_back(n);
    while(n>1){
        if(n%6==0){
            int mi=a[n/2]+1;
            int mi2=a[n-1]+1;
            int x=min(min(mi,mi2),a[(n-1)/3]+1);
            if(x==mi){
                n/=2;
                q.push_back(n);
                continue;
            }
            else if(x==mi2){
                n-=1;
                q.push_back(n);
                continue;
            }
            else{
                n/=3;
                q.push_back(n);
                continue;
            }
        }
        else if(n%2==0){
            int mi=a[n/2]+1;
            int mi2=a[n-1]+1;
            if(mi<=mi2){
                n/=2;
                q.push_back(n);
                continue;
            }
            else{
                n-=1;
                q.push_back(n);
                continue;
            }
        }
        else if(n%3==0){
            int mi=a[n/3]+1;
            int mi2=a[n-1]+1;
            if(mi<=mi2){
                n/=3;
                q.push_back(n);
                continue;
            }
            else{
                n-=1;
                q.push_back(n);
                continue;
            }
        }
        else{
            n-=1;
            q.push_back(n);
            continue;
        }
    }
    for(int i=(int)q.size()-1;i>=0;i--){
        cout <<q[i] << " ";
    }
    return 0;
}
