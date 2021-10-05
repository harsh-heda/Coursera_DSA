#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;
using namespace std;
vector<int> calcpref(string pattern){
    vector<int>v(pattern.length()+1);
    v[0]=0;int border=0;
    for(int i=1;i<(int)pattern.length();i++){
        while(border>0 && pattern[i]!=pattern[border]){
            border=v[border-1];
        }
        if(pattern[i]==pattern[border])
            border++;
        else
            border=0;
        v[i]=border;
    }
   /* for(int i=0;i<(int)pattern.length();i++){
        cout <<v[i]<<" ";
    }
    cout <<endl;*/
    return v;
}
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  string s;
  s=pattern+"$"+ text;
  vector<int> prefpat=calcpref(pattern);
  vector<int>prefs=calcpref(s);
  for(int i=(int)pattern.length()+1;i<(int)s.length();i++){
    if(prefs[i]==(int)pattern.length())
        result.push_back(i-2*(int)pattern.length());
  }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
