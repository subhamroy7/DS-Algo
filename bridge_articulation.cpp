#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;  // Max nodes

vector<int> adj[N];
int timer = 0;
int disc[N], low[N];
bool visited[N];
vector<pair<int, int>> bridges;       // Store bridges
set<int> articulationPoints;          // Store APs

void dfs(int u, int parent = -1) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            // BRIDGE condition
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }

            // ARTICULATION POINT condition (except root)
            if (parent != -1 && low[v] >= disc[u]) {
                articulationPoints.insert(u);
            }

            children++;
        } else {
            // Back edge
            low[u] = min(low[u], disc[v]);
        }
    }

    // Special case: root is an articulation point if it has 2+ children
    if (parent == -1 && children > 1) {
        articulationPoints.insert(u);
    }
}
