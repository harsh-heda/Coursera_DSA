#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits>

/*
 * This solver is based on Tarjan's SCCs algorithm (recursive).
 * Useful links:
 * - https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm
 * - https://en.wikipedia.org/wiki/2-satisfiability
 */

struct solve2sat {
    struct util {
        util()
            : index{ MIN }
            , lowlink{ MIN }
            , id{ -1 }
            , on_stack{ false }
        {
        }
        int index, lowlink, id;
        bool on_stack;
        std::vector<int> edges;
    };

    solve2sat(std::unordered_map<int, util> adj, int nums)
        : n{ nums }
        , graph{ std::move(adj) }
        , sol{ std::vector<bool>(n, false) }
    {
    }

    void process_vertex(int v)
    {
        auto& utl = graph[v];

        utl.lowlink = utl.index = t++;
        utl.on_stack = true;
        stk.push(v);

        for (auto w : utl.edges) {
            if (graph[w].index == MIN) {
                process_vertex(w);
                utl.lowlink = std::min(utl.lowlink, graph[w].lowlink);
            }
            else if (graph[w].on_stack) {
                utl.lowlink = std::min(utl.lowlink, graph[w].index);
            }
        }

        if (utl.lowlink == utl.index) {
            do {
                w = stk.top();
                stk.pop();

                if (id == graph[-w].id) {
                    sat = false;
                    return;
                }

                auto& w_utl = graph[w];
                w_utl.on_stack = false;
                w_utl.id = id;

                sol[abs(w) - 1] = w < 0 ? true : false;

            } while (w != v);
            ++id;
        }
    }

    void solve()
    {
        for (int i = -n; i <= n; ++i) {
            if (graph[i].index == MIN && i != 0) {
                process_vertex(i);
            }
        }
    }

    void print_solution() const noexcept
    {
        if (!sat) {
            printf("%s\n", "UNSATISFIABLE\0");
            return;
        }

        printf("%s\n", "SATISFIABLE\0");
        for (unsigned int i = 0, s = sol.size(); i < s; ++i) {
            printf("%d ", (sol[i] ? i + 1 : -(i + 1)));
        }

        printf("\n");
    }

    int t{ 0 }, id{ 0 }, w{ 0 }, n{ 0 };

    std::unordered_map<int, util> graph;
    std::vector<bool> sol;
    std::stack<int> stk;

    bool sat{ true };

    static constexpr int MIN = std::numeric_limits<int>::min();
};

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::unordered_map<int, solve2sat::util> adj(n * 2);

    for (int i = 0, x, y; i < m; ++i) {
        std::cin >> x >> y;
        adj[-x].edges.emplace_back(y);
        adj[-y].edges.emplace_back(x);
    }

    solve2sat solver(std::move(adj), n);
    solver.solve();
    solver.print_solution();
}
