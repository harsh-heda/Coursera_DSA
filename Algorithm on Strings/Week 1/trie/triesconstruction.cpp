#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
using namespace std;
typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  edges root;
  t.push_back(root);
  int nod=0;
  for(auto it=patterns.begin();it!=patterns.end();it++){
    int currentnode=0;
    for(int i=0;i<(int)(*it).length();i++){
        char currentsymbol=(*it)[i];
        edges:: iterator edgeiter=t[currentnode].find(currentsymbol);
        if(edgeiter!=t[currentnode].end())
            currentnode=edgeiter->second;
        else{
            t[currentnode][currentsymbol]=++nod;
            edges temps;
            t.push_back(temps);
            currentnode=nod;
        }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
