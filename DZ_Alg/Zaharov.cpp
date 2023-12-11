#include "Header.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include <fstream>
#include <string>

using namespace std;


struct Edge {
    int source, dest, weight;
};


void printPath(vector<int> const& parent, int vertex, int source)
{
    if (vertex < 0) {
        return;
    }

    printPath(parent, parent[vertex], source);
    if (vertex != source) {
        cout << ", ";
    }
    cout << vertex;
}

void Print(vector<int> const& distance, vector<int> const& parent, const int& source, const int& n) {
    for (int i = 0; i < n; i++)
    {
        if (i != source && distance[i] < INT_MAX)
        {
            cout << "The distance of vertex " << i << " from the source is "
                << setw(2) << distance[i] << ". Its path is [";
            printPath(parent, i, source); cout << "]" << endl;
        }
    }
}


vector<int> bellmanFord(vector<Edge> const& edges, vector<int>& parent, int source, int n)
{

    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    int u, v, w, k = n;


    while (--k)
    {
        for (Edge edge : edges)
        {

            u = edge.source;
            v = edge.dest;
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

        u = edge.source;
        v = edge.dest;
        w = edge.weight;


        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Negative-weight cycle is found!!";
            return distance;
        }
    }

    return distance;
}

void Zaharov(std::ifstream& fin)
{
    auto start = chrono::system_clock::now();

    int vertex_count, edge_count;
    vector<Edge> edges;

    

    vertex_count = tryChoose(fin, 0, 9999); edge_count = tryChoose(fin, 0, 9999);

    edges.resize(edge_count);
    
    for (auto& i : edges) {
        i.source = tryChoose(fin); 
        i.dest = tryChoose(fin); 
        i.weight = tryChoose(fin);
    }



    for (int source = 0; source < vertex_count; source++) {
        vector<int> parent(vertex_count, -1);
        vector<int> distance = bellmanFord(edges, parent, source, vertex_count);

        
        //Print(distance, parent, source, vertex_count);
    }
    auto finish = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(finish - start).count();
    cout << "Time for method: " << time << " microseconds" << endl;
}