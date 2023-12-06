#include "Header.h"
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

typedef pair<int, int> edge;
typedef vector < vector<edge> > graph;

const int infinity = INT_MAX;

void Dubenko(std::ifstream& fin)
{
    auto time1 = steady_clock::now();
    int numberOfVertices = 0,
        startVertex = 1,
        finishVertex = 1,
        edge_count,
        source_file,
        dest_file,
        weight_file;
    edge pairs;
    graph g;

    if (fin.is_open()) {

        numberOfVertices = tryChoose(fin, 0, 9999); edge_count = tryChoose(fin, 0, numberOfVertices * numberOfVertices); finishVertex = numberOfVertices;
        for (size_t i = 0; i < numberOfVertices + 1; ++i)
        {
            g.push_back({});
        }

        while (!fin.eof()) {
            source_file = tryChoose(fin);
            dest_file = tryChoose(fin);
            weight_file = tryChoose(fin);
            pairs.first = dest_file; pairs.second = weight_file;
            g[source_file].push_back(pairs);
        }

    }

    else cout << "Error! File does not exist.";

    vector<int> d(numberOfVertices + 1, infinity);
    d[startVertex] = 0;

    vector<int> state(numberOfVertices + 1, 2);
    state[startVertex] = 1;

    deque<int> q;
    q.push_back(startVertex);

    vector<int> p(numberOfVertices + 1, -1);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop_front();
        state[vertex] = 0;
        for (size_t i = 0; i < g[vertex].size(); ++i)
        {
            int to = g[vertex][i].first,
                length = g[vertex][i].second;
            if (d[to] > d[vertex] + length)
            {
                d[to] = d[vertex] + length;
                if (state[to] == 2)
                    q.push_back(to);
                else if (state[to] == 0)
                    q.push_front(to);
                p[to] = vertex;
                state[to] = 1;
            }
        }
    }
    if (p[finishVertex] == -1)
    {
        cout << "No solution" << endl;
    }
    else
    {
        vector<int> path;
        for (int vertex = finishVertex; vertex != -1; vertex = p[vertex])
            path.push_back(vertex);
        reverse(path.begin(), path.end());
        cout << "Shortest path from vertex " << startVertex << "to vertex " << finishVertex << ": ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' > ';
        cout << endl << "Shortest path lenght: " << d[finishVertex];
    }
    auto time2 = steady_clock::now();
    auto time3 = duration_cast<microseconds>(time2 - time1).count();
    cout << endl << "Time of programm: " << time3 << endl;
    cin.get();
};