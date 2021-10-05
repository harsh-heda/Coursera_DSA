#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct Edge {
    int from;
    int to;
};

struct ConvertHampathToSat {
    ConvertHampathToSat(int n, int m)
        : cla_num(0)
        , vertices_num(n)
        , matrix(n, vector<bool>(n, false))
        , data(n, vector<int>(n))
    {
        for (int i = 0, counter = 0; i < vertices_num; ++i) {
            for (int j = 0; j < vertices_num; ++j) {
                data[i][j] = ++counter;
            }
        }
    }

    void printEquisatisfiableSatFormula(const int max_cla_num)noexcept {
        cla_stream.reserve(max_cla_num * 3);

        each_vertext_in_path();
        each_vertext_in_path_only_once();
        each_path_position_occupied();
        verteces_occupy_diff_positions();
        nonadjacent_vertices_nonadjacent_in_path();

        printf("%d %d \n%s", cla_num, vertices_num * vertices_num, cla_stream.c_str());
    }
    void each_vertext_in_path() noexcept
    {
        for (int i = 0; i < vertices_num; ++i, ++cla_num) {
            for (int j = 0; j < vertices_num; ++j) {
                cla_stream += std::to_string(data[i][j]) + " ";
            }
            cla_stream += "0\n";
        }
    }

    void each_vertext_in_path_only_once() noexcept
    {
        for (int i = 0; i < vertices_num; ++i) {
            for (int j = 0; j < vertices_num; ++j) {
                for (int k = i + 1; k < vertices_num; ++k, ++cla_num) {
                    cla_stream += std::to_string(-data[i][j]) + " " + std::to_string(-data[k][j]) + " 0\n";
                }
            }
        }
    }

    void each_path_position_occupied() noexcept
    {
        for (int i = 0; i < vertices_num; ++i, ++cla_num) {
            for (int j = 0; j < vertices_num; ++j) {
                cla_stream += std::to_string(data[j][i]) + " ";
            }
            cla_stream += "0\n";
        }
    }

    void verteces_occupy_diff_positions() noexcept
    {
        for (int i = 0; i < vertices_num; ++i) {
            for (int j = 0; j < vertices_num; ++j) {
                for (int k = j + 1; k < vertices_num; ++k, ++cla_num) {
                    cla_stream += std::to_string(-data[i][j]) + " " + std::to_string(-data[i][k]) + " 0\n";
                }
            }
        }
    }

    void nonadjacent_vertices_nonadjacent_in_path() noexcept
    {
        for (int i = 0; i < vertices_num; ++i) {
            for (int j = 0; j < vertices_num; ++j) {
                if (!matrix[i][j] && j != i) {
                    for (int k = 0; k < vertices_num - 1; ++k, ++cla_num) {
                        cla_stream += std::to_string(-data[i][k]) + " " + std::to_string(-data[j][k + 1]) + " 0\n";
                    }
                }
            }
        }
    }

    unsigned int cla_num;
    const unsigned int vertices_num;
    vector<vector<bool> > matrix;
    vector<vector<int> > data;
    std::string cla_stream;
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ConvertHampathToSat converter(n, m);
    for (int i = 0; i < m; ++i) {
        int x,y;cin>>x>>y;
        converter.matrix[x-1][y-1]=true;
        converter.matrix[y-1][x-1]=true;
    }

    converter.printEquisatisfiableSatFormula(120000);

    return 0;
}
