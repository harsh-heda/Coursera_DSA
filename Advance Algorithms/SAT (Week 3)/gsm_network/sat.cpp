#include <ios>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

struct ConvertGSMNetworkProblemToSat {\
    static constexpr auto number = 3;
    struct edge {
        int from;
        int to;
    };

    ConvertGSMNetworkProblemToSat(int n, int m) :
        numVertices(n),
        edges(m)
    {  }

    void printEquisatisfiableSatFormula() const noexcept {
        int c=number*edges.size()+numVertices;
        int v=number*numVertices;

        cout << c<<v << endl;
        for(int i=0,counter=1;i<numVertices;i++,counter+=number){
            printf("%d %d %d 0\n", counter, counter + 1, counter + 2);
        }
        for(const edge& e:edges){
            printf("%d %d 0\n", -((e.from - 1) * number + 1), -((e.to - 1) * number + 1));
            printf("%d %d 0\n", -((e.from - 1) * number + 2), -((e.to - 1) * number + 2));
            printf("%d %d 0\n", -((e.from - 1) * number + 3), -((e.to - 1) * number + 3));
        }
    }
     int numVertices;
    vector<edge> edges;
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ConvertGSMNetworkProblemToSat converter(n, m);
    for (int i = 0; i < m; ++i) {
        cin >> converter.edges[i].from >> converter.edges[i].to;
    }

    converter.printEquisatisfiableSatFormula();

    return 0;
}
