#include "Header.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <fstream>


using namespace std;

const int INF = 9999;

void Kondarev(ifstream& fin) {

    int n, ways_cnt;
    fin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = INF;
        }
    }

    fin >> ways_cnt;

    for (int i = 0; i < ways_cnt; i++)
    {
        int index1, index2;
        fin >> index1;
        fin >> index2;
        fin >> graph[index1 - 1][index2 - 1];
    }

    fin.close();

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF   ";
            }
            else {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
}