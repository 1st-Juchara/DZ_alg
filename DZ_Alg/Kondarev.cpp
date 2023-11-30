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
    int n = tryChoose(fin, 0, 9999);
    int ways_cnt = tryChoose(fin, 0, n*n);

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < ways_cnt; i++)
    {
        int index1 = tryChoose(fin);
        int index2 = tryChoose(fin);
        graph[index1 - 1][index2 - 1] = tryChoose(fin);
    }

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