#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >>n;
    stack<int>s;
    deque<int>q;
    for(int i=0;i<n;i++){
        string c;cin>>c;
        if(c=="push"){
            int v;cin>>v;
            s.push(v);
            if(q.empty()==true || q[0]<=v)
                q.push_front(v);
            else
                q.push_back(v);
        }
        else if(c=="pop"){
            if(s.top()==q[0])
                q.pop_front();
            s.pop();
        }
        else{
            if(s.empty())
                continue;
            else
                cout<<q[0]<<endl;
        }
    }
    return 0;

}
