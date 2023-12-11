#include "Header.h"
#include <vector>

using namespace std;

vector<int> get_path(vector<vector<int>>& from, int start, int finish) {
    vector<int> path;
    for (int i = finish; i != -1; i = from[start][i])
        path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}


void TimirbaevErik(ifstream& fin) {

    auto start = chrono::system_clock::now();

    int vertex_count = tryChoose(fin, 0, 9999);  int edge_count = tryChoose(fin, 0, 9999);
    const int INF = 1e9;

    vector<vector<int>> matrix(vertex_count, vector<int>(vertex_count, INF));

    vector<vector<int>> from(vertex_count, vector<int>(vertex_count, -1));

    for (int i = 1; i < vertex_count + 1; i++) {
        matrix[i - 1][i - 1] = 0;
    }

    for (int i = 0; i < edge_count; i++) {
        int a = tryChoose(fin, 0, vertex_count - 1);
        int b = tryChoose(fin, 0, vertex_count - 1);
        int weight = tryChoose(fin, -9999, 9999);

        if (matrix[a][b] > weight) {
            matrix[a][b] = weight;
            from[a][b] = a;

        }
    }

    for (int v = 0; v < vertex_count; v++) {
        for (int a = 0; a < vertex_count; a++) {
            if (matrix[a][v] != INF) {
                for (int b = 0; b < vertex_count; b++) {
                    if (matrix[v][b] != INF && matrix[a][b] > matrix[a][v] + matrix[v][b]) {
                        matrix[a][b] = matrix[a][v] + matrix[v][b];
                        from[a][b] = from[v][b];
                    }
                }
            }
        }
    }

    auto finish = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(finish - start).count();
    cout << "Time for method: " << time << " microseconds" << endl;

    for (int i = 0; i < vertex_count; i++) {
        for (int j = 0; j < vertex_count; j++) {
            if (matrix[i][j] == INF) cout << "INF\t";
            else cout << matrix[i][j] << "\t";
        }
        cout << endl << endl;
    }

    /*for (int i = 0; i < vertex_count; i++) {
        for (int j = 0; j < vertex_count; j++) {
            if (matrix[i][j] == INF) cout << "There is no path from " << i << " to " << j << "." << endl << endl;
            else {
                cout << "The shortest path from " << i << " to " << j << ": [";
                for (int k : get_path(from, i, j)) {
                    cout << " " << k;
                }
                cout << " ]" << endl << endl;;
            }
        }
    }*/
}