#include <iostream>
#include <vector>
#include <queue>

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& edges, int num_v) {
    std::vector<int> dist(num_v, 100000 * 100000);
    dist[0] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, 0));

    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : edges[u]) {
            int u2 = edge.first;
            int w2 = edge.second;
            if (dist[u2] > w + w2) {
                dist[u2] = w + w2;
                pq.push(std::make_pair(dist[u2], u2));
            }
        }
    }
    return dist;
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> edges = {
        {{1, 4}, {2, 3}},
        {{2, 1}, {3, 1}, {4, 5}},
        {{5, 2}},
        {{4, 3}},
        {{6, 2}},
        {{4, 1}, {6, 4}},
        {}
    };

    std::vector<int> dist = dijkstra(edges, 7);

    for (int i = 0; i < dist.size(); ++i) {
        std::cout << "Shortest distance from vertex 0 to vertex " << i << ": " << dist[i] << std::endl;
    }

    return 0;
}