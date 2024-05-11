#include <iostream>
#include <vector>
using namespace std;
//problem 7
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c, int V) {
    for (int i = 0; i < V; ++i) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v, int V) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m, int V) {
    vector<int> color(V, 0);

    if (!graphColoringUtil(graph, m, color, 0, V))
        return false;

    return true;
}

int main() {
    int N1 = 4, M1 = 3, E1 = 5;
    vector<vector<int>> Edges1 = { {0,1},{1,2},{2,3},{3,0},{0,2} };
    vector<vector<int>> graph1(N1, vector<int>(N1, 0));
    for (auto edge : Edges1) {
        graph1[edge[0]][edge[1]] = 1;
        graph1[edge[1]][edge[0]] = 1;
    }
    cout << graphColoring(graph1, M1, N1) << endl; 

    int N2 = 3, M2 = 2, E2 = 3;
    vector<vector<int>> Edges2 = { {0,1},{1,2},{0,2} };
    vector<vector<int>> graph2(N2, vector<int>(N2, 0));
    for (auto edge : Edges2) {
        graph2[edge[0]][edge[1]] = 1;
        graph2[edge[1]][edge[0]] = 1;
    }
    cout << graphColoring(graph2, M2, N2) << endl; 

    return 0;
}
