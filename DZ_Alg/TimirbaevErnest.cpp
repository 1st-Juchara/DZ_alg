#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <set>
#include <iterator>

using namespace std;

const int INF = 1e9;


struct Edge {
    int start, end, weight;
};



bool bellmanFord(vector<Edge>& edges, vector<int>& distance, int n) {

    int u, v, w, k = n;

    while (--k)
    {
        for (Edge& edge : edges)
        {

            u = edge.start;
            v = edge.end;
            w = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {

                distance[v] = distance[u] + w;

            }
        }
    }

    for (Edge& edge : edges)
    {

        u = edge.start;
        v = edge.end;
        w = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Negative-weight cycle is found!!";
            return false;
        }
    }

    return true;
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


void algorithm(vector<Edge>& edges, const int& vertex_count, const int& edge_count, const int& new_vertex) {
    vector<int> distance(new_vertex + 1, INT_MAX);
    distance[new_vertex] = 0;

    if (bellmanFord(edges, distance, new_vertex + 1)) {

        for (int i = 0; i < vertex_count; i++)
            edges.erase(edges.begin() + 0);

        for (auto& i : edges) {
            i.weight = i.weight + distance[i.start] - distance[i.end];
        }

        vector<vector<pair<int, int>>> graph(new_vertex);
        for (int i = 0; i < edge_count; i++) {
            graph[edges[i].start].push_back({ edges[i].end, edges[i].weight });
        }

        for (int u = 0; u < new_vertex; u++) {
            vector<int> dist = dijkstra(graph, u);

            for (int v = 0; v < dist.size(); v++) {
                if (dist[v] != INF)
                    cout << dist[v] - distance[u] + distance[v] << '\t';
                else
                    cout << "X" << '\t';
            }
            cout << endl;
        }

    }
}


void TimirbaevErnest(std::ifstream& fin) {
    ifstream file;
    file.open("input.txt", ios::in);

    int vertex_count, edge_count;
    set<int> vertex;
    vector<Edge> edges;


    if (file.is_open()) {

        vertex_count = tryChoose(file, 0, 9999); edge_count = tryChoose(file, 0, vertex_count * vertex_count);

        int length = edge_count + vertex_count;
        edges.resize(length);

        while (!file.eof()) {

            for (int i = vertex_count; i < length; i++) {
                edges[i].start = tryChoose(file); edges[i].end = tryChoose(file); edges[i].weight = tryChoose(file);
                vertex.insert(edges[i].start);
                vertex.insert(edges[i].end);
            }
        }

        set<int>::iterator it_end = vertex.end();
        set<int>::iterator it_begin = vertex.begin();
        it_end--;
        int new_vertex = *it_end + 1;

        for (int i = 0; i < vertex_count; i++) {
            edges[i].start = new_vertex;
            edges[i].end = *it_begin;
            edges[i].weight = 0;
            it_begin++;
        }

        algorithm(edges, vertex_count, edge_count, new_vertex);

    }

    else cout << "Error! File does not exist.";

}