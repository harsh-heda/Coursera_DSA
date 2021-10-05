#include<iostream>
#include<bits/stdc++.h>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;
long long int key[100004];
    int r[100004];
    int l[100004];
bool isbst(int i,int mi,int ma){
    if(key[i]<mi)
        return false;
    if(key[i]>=ma && key[i]!=2147483647)
        return false;
    if(r[i]==-1 && l[i]==-1)
        return true;
    if(r[i]==-1)
        return (true && isbst(l[i],mi,key[i]));
    if(l[i]==-1)
        return (isbst(r[i],key[i],ma) && true);
    return (isbst(r[i],key[i],ma) && isbst(l[i],mi,key[i]));

}
int main_with_large_stack_space() {
    ios_base::sync_with_stdio(0);
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
int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}
