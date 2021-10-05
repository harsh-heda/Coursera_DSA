#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;
string BWT(const string& text) {
  string result = "";
  vector<string>v;
  for(int i=0;i<(int)text.length();i++){
    string p=text.substr(i)+text.substr(0,i);
    v.push_back(p);
  }
  sort(v.begin(),v.end());
  for(auto it=v.begin();it!=v.end();it++){
    result=result+(*it)[text.length()-1];
  }

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
