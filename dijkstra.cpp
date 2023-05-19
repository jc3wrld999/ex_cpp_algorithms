#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& edges, int num_v, int goal) {
    vector<int> dist(num_v, INT_MAX);
    dist[0] = 0;

    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    pq.push(make_pair(0, vector<int>{0}));

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        vector<int> curr_path = pq.top().second;
        int last = curr_path.back();
        pq.pop();

        if (last == goal) {
            return curr_path;
        }

        for (const auto& edge : edges[last]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[neighbor] > curr_dist + weight) {
                dist[neighbor] = curr_dist + weight;
                vector<int> new_path = curr_path;
                new_path.push_back(neighbor);
                pq.push(make_pair(dist[neighbor], new_path));
            }
        }
    }

    return vector<int>();
}

int main() {
    vector<vector<pair<int, int>>> edges = {
        {{1, 4}, {2, 3}},
        {{2, 1}, {3, 1}, {4, 5}},
        {{5, 2}},
        {{4, 3}},
        {{6, 2}},
        {{4, 1}, {6, 4}},
        {}
    };

    vector<int> shortest_path = dijkstra(edges, 7, 6);

    cout << "Shortest path: ";
    for (int node : shortest_path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}