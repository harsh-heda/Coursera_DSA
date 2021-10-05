#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;
void calc(const string& text, map<char, int>& total, vector<int>& freq, int& pos) {
	int a = 0;
	int c = 0;
	int g = 0;
	int t = 0;
	int d = 0;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == 'A') {
			freq.push_back(a);
			a++;
		} else if (text[i] == 'C') {
			freq.push_back(c);
			c++;
		} else if (text[i] == 'G') {
			freq.push_back(g);
			g++;
		} else if (text[i] == 'T') {
			freq.push_back(t);
			t++;
		} else if (text[i] == '$') {
			pos = i;
			freq.push_back(d);
			d++;
		}
	}
	total['$'] = 0;
	total['A'] = d;
	total['C'] = total['A'] + a;
	total['G'] = total['C'] + c;
	total['T'] = total['G'] + g;
}
string InverseBWT(const string& bwt) {
  string text = "";
    map<char, int> total;
	vector<int> freq;
	int pos = 0;
	calc(bwt,total,freq,pos);
	int index = pos;
  for(int i=0;i<(int)bwt.length();i++){
    text+=bwt[index];
    index=total[bwt[index]]+freq[index];
  }
  reverse(text.begin(),text.end());
  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
