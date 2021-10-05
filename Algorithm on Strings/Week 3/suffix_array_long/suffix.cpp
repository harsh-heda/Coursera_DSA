#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using namespace std;
vector <int> sortchar(const string& text){
    vector<int>order((int)text.length());
    vector<int> freq(5,0);
    map<char,int>m;
    m['$']=0;
    m['A']=1;
    m['C']=2;
    m['G']=3;
    m['T']=4;
    for(int i=0;i<(int)text.length();i++){
        char c=text[i];
        freq[m[c]]++;
    }
    for(int i=1;i<5;i++){
        freq[i]=freq[i]+freq[i-1];
    }
    for(int i=(int)text.length()-1;i>=0;i--){
        int c=m[text[i]];
        freq[c]-=1;
        order[freq[c]]=i;
    }
    return order;
}
vector <int>computeclass(const string& text,vector<int>order){
    vector<int>clas((int)text.length());
    clas[order[0]]=0;
    for(int i=1;i<(int)text.length();i++){
        if(text[order[i]]!=text[order[i-1]])
            clas[order[i]]=clas[order[i-1]]+1;
        else
            clas[order[i]]=clas[order[i-1]];
    }
    return clas;
}
void sortdouble(const string &text,int l,vector<int>& order,const vector<int>& clas){
    vector<int>nworder(text.length());
    vector<int>freq(text.length(),0);
    for(int i=0;i<(int)text.length();i++){
        freq[clas[i]]++;
    }
    for(int i=1;i<(int)text.length();i++){
        freq[i]+=freq[i-1];
    }
    for(int i=text.length()-1;i>=0;i--){
        int k=(order[i]-l+(int)text.length())%(int)text.length();
        int cl=clas[k];
        freq[cl]-=1;
        nworder[freq[cl]]=k;
    }
    order=nworder;
}
void update(vector<int>& nworder,vector<int>& clas,int l){
    vector<int>nwclas(nworder.size());
    nwclas[nworder[0]]=0;
    for(int i=1;i<(int)nworder.size();i++){
        int c=nworder[i];
        int pre=nworder[i-1];
        int mid=c+l;
        int midprev=(pre+l)%(int)nworder.size();
        if(clas[c]!=clas[pre] || clas[mid]!=clas[midprev])
            nwclas[c]=nwclas[pre]+1;
        else
            nwclas[c]=nwclas[pre];
    }
    clas=nwclas;
}
// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  vector<int>order=sortchar(text);
  vector<int>clas=computeclass(text,order);
  int l=1;
  while(l<(int)text.length()){
    sortdouble(text,l,order,clas);
    update(order,clas,l);
    l*=2;
  }
  result =order;
  // Implement this function yourself
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
