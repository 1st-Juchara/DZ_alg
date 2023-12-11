#include "Header.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <fstream>


using namespace std;

const int INF = 9999;

void Kondarev(ifstream& fin) {

    auto start = chrono::system_clock::now();

    int n = tryChoose(fin, 0, 9999);
    int ways_cnt = tryChoose(fin, 0, 9999);

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
        int index_1 = tryChoose(fin, 0, n - 1);
        int index_2 = tryChoose(fin, 0, n - 1);
        graph[index_1][index_2] = tryChoose(fin, -9999, 9999);;
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

    auto finish = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(finish - start).count();
    cout << "Time for method: " << time << " microseconds" << endl;

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << "      INF";
            }
            else {
                cout << format("{:9}", dist[i][j]);
            }
        }
        cout << endl;
    }*/
}
