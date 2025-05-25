 int dijkstra(int k, int n, vector<pair<int,int>> g[]) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [dist_v, v] = pq.top();
        pq.pop();

        for (auto [child_v, wt] : g[v]) {
            if (dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                pq.push({dist[child_v], child_v});
            }
        }
    }

    int maxi = *max_element(dist.begin() + 1, dist.begin() + n + 1);
    return (maxi == INT_MAX) ? -1 : maxi;
}
