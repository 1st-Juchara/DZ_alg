#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int INF = 1e9;


struct Edge {
    int start, end, weight;
};

vector<int> BF(vector<Edge> const& edges, vector<int>& parent, int source, int n)
{

    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    int u, v, w, k = n;

    while (--k)
    {
        for (Edge edge : edges)
        {

            u = edge.start;
            v = edge.end;
            w = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {

                distance[v] = distance[u] + w;

                parent[v] = u;
            }
        }
    }

    for (Edge edge : edges)
    {

        u = edge.start;
        v = edge.end;
        w = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Negative-weight cycle is found!!";
            return distance;
        }
    }

    return distance;
}


vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    vector<bool> visited(graph.size());

    for (int i = 0; i < graph.size(); i++) {
        int nearest = -1;
        for (int v = 0; v < graph.size(); v++) {
            if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v]))
                nearest = v;

        }

        visited[nearest] = true;

        for (auto& i : graph[nearest]) {
            if (dist[i.first] > dist[nearest] + i.second)
                dist[i.first] = dist[nearest] + i.second;
        }
    }

    return dist;
}


void TimirbaevErnest(std::ifstream& fin) {

    int vertex_count, edge_count;
    vector<Edge> edges;


    if (fin.is_open()) {

        vertex_count = tryChoose(fin, 0, 9999);
        edge_count = tryChoose(fin, 0, vertex_count*vertex_count);

        int length = edge_count + vertex_count;
        edges.resize(length);

        for (int i = 0; i < vertex_count; i++) {
            edges[i].start = 0;
            edges[i].end = i + 1;
            edges[i].weight = 0;
        }

        vertex_count += 1;

        while (!fin.eof()) {

            for (int i = vertex_count - 1; i < length; i++) {
                edges[i].start = tryChoose(fin); edges[i].end = tryChoose(fin); edges[i].weight = tryChoose(fin);
            }
        }

    }

    else cout << "Error! File does not exist.";

    vector<int> parent(vertex_count, -1);
    vector<int> distance = BF(edges, parent, 0, vertex_count);

    for (int i = 0; i < vertex_count - 1; i++)
        edges.erase(edges.begin() + 0);

    for (auto& i : edges) {
        i.weight = i.weight + distance[i.start] - distance[i.end];
    }

    vector<vector<pair<int, int>>> graph(vertex_count - 1);
    for (int i = 0; i < edge_count; i++) {
        graph[edges[i].start - 1].push_back({ edges[i].end - 1, edges[i].weight });
    }

    for (int u = 0; u < vertex_count - 1; u++) {
        vector<int> dist = dijkstra(graph, u);

        for (int v = 0; v < dist.size(); v++) {
            if (dist[v] != INF)
                cout << dist[v] - distance[u + 1] + distance[v + 1] << '\t';
            else
                cout << "X" << '\t';
        }
        cout << endl;
    }

}