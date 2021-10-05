#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

struct Node
{
	vector<Node*> nextNodes;
	vector<pair<int, int> > edges;
};

int getCommonStringLength(const string& text, int startPos1, int startPos2, int string1Len)
{
	int charnum = 0;
	while (text[startPos1 + charnum] == text[startPos2 + charnum])
	{
		charnum++;
		if (charnum == string1Len || startPos2 + charnum == text.size())
		{
			break;
		}
	}
	return charnum;
}
void updateTree(Node* root, const string& text, int index)
{

	if (index >= text.size())
	{
		return;
	}
	for (int i = 0; i < root->nextNodes.size(); i++)
	{
		int startingPos = root->edges[i].first;
		int commonStrLen = getCommonStringLength(text, startingPos, index, root->edges[i].second);
		if (commonStrLen > 0 && commonStrLen < root->edges[i].second)
		{
			Node* oldNode = root->nextNodes[i];
			Node* newNode = new Node;
			pair<int, int> partOldEdge(startingPos + commonStrLen, root->edges[i].second - commonStrLen);
			pair<int, int> newEdge(index + commonStrLen, text.size() - index - commonStrLen);
			Node* middle = new Node;
			middle->nextNodes.push_back(oldNode);
			middle->nextNodes.push_back(newNode);
			middle->edges.push_back(partOldEdge);
			middle->edges.push_back(newEdge);
			root->nextNodes[i] = middle;
			root->edges[i].second = commonStrLen;
			return;
		}
		else if (commonStrLen == root->edges[i].second)
		{
			Node* nextNode = root->nextNodes[i];
			updateTree(nextNode, text, index + commonStrLen);
			return;
		}
		else if (commonStrLen == 0 && i == root->nextNodes.size() - 1)
		{
			Node* newNode = new Node;
			pair<int, int> newEdge(index, text.size() - index);
			root->nextNodes.push_back(newNode);
			root->edges.push_back(newEdge);
			pair<int,int> test= root->edges[0];
			return;
		}
	}
	Node* nextNode = new Node;
	root->nextNodes.push_back(nextNode);

	pair<int, int> stringIdx(index, text.size() - index);
	root->edges.push_back(stringIdx);
	return;

}

void getSubStrings(Node* root, const string& text, vector<string>& result)
{
	for (int u=0;u<root->nextNodes.size();u++)
	{
		result.push_back(text.substr(root->edges[u].first, root->edges[u].second));
		Node* nextNode = root->nextNodes[u];
		getSubStrings(nextNode, text, result);
	}

}
vector<string> ComputeSuffixTreeEdges(const string& text) {
	vector<string> result;
	Node* root = new Node;
	for (int i = 0; i < text.size(); i++)
	{
		updateTree(root, text, i);
	}
	getSubStrings(root, text, result);
	return result;
}

int main() {
	string text;
	cin >> text;
	vector<string> edges = ComputeSuffixTreeEdges(text);
	for (int i = 0; i < edges.size(); ++i) {
		cout << edges[i] << endl;
	}
	return 0;
}
