/*

1.8.3 - Tarjan's Bridge-Finding Algorithm

Description: Given an *undirected* graph, a bridge is an edge,
when deleted, increases the number of connected components.
An edge is a bridge iff if it is not contained in any cycle.

Complexity: O(V + E) on the number of vertices and edges.

*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 101;
int nodes, edges, a, b, counter, num[MAX_N], low[MAX_N];
bool visit[MAX_N] = {0};
vector<int> adj[MAX_N];

void DFS(int a, int c) {
    int b;
    low[a] = num[a] = ++counter;
    for (int j = 0; j < adj[a].size(); j++) {
        if (num[b = adj[a][j]] == -1) {
            DFS(b, a);
            low[a] = min(low[a], low[b]);
        } else if (b != c)
            low[a] = min(low[a], num[b]);
    }
    for (int j = 0; j < adj[a].size(); j++)
        if (low[b = adj[a][j]] > num[a])
            cout << a+1 << "-" << b+1 << " is a bridge\n";
}

int main() {
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < nodes; i++) {
        num[i] = low[i] = -1;
        visit[i] = false;
    }
    counter = 0;
    for (int i = 0; i < nodes; i++) 
        if (num[i] == -1) DFS(i, -1);
    return 0;
}

/*

=~=~=~=~= Sample Input =~=~=~=~=
8 6
1 2
1 6
2 3
2 6
4 8
5 6

=~=~=~=~= Sample Output =~=~=~=~=
6-5 is a bridge.
2-3 is a bridge.
4-8 is a bridge.

*/