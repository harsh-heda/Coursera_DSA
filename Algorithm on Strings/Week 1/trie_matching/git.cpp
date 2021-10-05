#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int const Letters =    4;
int const NA      =   -1;
struct Node{
	int next [Letters];
	Node (){
		fill (next, next + Letters, NA);
	}
	bool isLeaf () const{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};
typedef vector<Node> trie;
int letterToIndex (char letter){
	switch (letter){
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}
trie build_trie(vector<string> & patterns) {
  trie t;
  Node root;
  t.push_back(root);
  int nod = 0;
  for (auto it = patterns.begin(); it!=patterns.end(); ++it){
  	int currentnode = 0;
  	for (unsigned int i = 0; i < (*it).length(); i++){
  		char symbol = (*it)[i];
  		int index = letterToIndex(symbol);
  		int nextnode = t[currentnode].next[index];
  		if(nextnode != NA)
  			currentnode = nextnode;
  		else{
  			t[currentnode].next[index] = ++nod;
  			Node temp;
  			t.push_back(temp);
  			currentnode = nod;
  		}
  	}
  }
  return t;
}
int prefixTrieMatching(string text, trie &t){
	char symbol = text[0];
	Node currentnode = t[0];
	unsigned int id = 0;
	int letterno = letterToIndex(symbol);
	while(true){
		if(currentnode.isLeaf())
			return 1;
		else if(currentnode.next[letterno] != NA){
			currentnode = t[currentnode.next[letterno]];
			if (id < text.size() - 1){
				symbol=text[++id];
				letterno = letterToIndex(symbol);
			}
			else{
				if(currentnode.isLeaf())
					return 1;
				else
					return 0;
			}
		}
		else
			return 0;
	}
}
vector <int> solve (string text, int n, vector <string> patterns){
	vector <int> result;
	trie t = build_trie(patterns);
	for (int i = 0; i < text.length(); i++){
		string tes = text.substr(i, text.length() - i);
		int patt = prefixTrieMatching(tes,t);
		if (patt)
			result.push_back(i);
	}
	return result;
}
int main (void)
{
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector <string> patterns(n);
	for (int i = 0; i < n; i++){
		cin >> patterns[i];
	}
	vector <int> ans;
	ans = solve (t, n, patterns);
	for (int i = 0; i < (int) ans.size (); i++){
		cout << ans[i];
		if (i + 1 < (int) ans.size ()){
			cout << " ";
		}
		else{
			cout << endl;
		}
	}
	return 0;
}
