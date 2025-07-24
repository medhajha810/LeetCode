class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights)
            graph[f[0]].emplace_back(f[1], f[2]);

        // Min-heap: (cost, current city, stops remaining)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);

        vector<int> visited(n, INT_MAX); // Min stops visited for each city

        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top(); pq.pop();

            if (city == dst) return cost;
            if (stops > k || visited[city] < stops) continue;

            visited[city] = stops;

            for (auto& [next, price] : graph[city]) {
                pq.emplace(cost + price, next, stops + 1);
            }
        }

        return -1;
    }
};
