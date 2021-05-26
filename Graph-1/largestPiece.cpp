#include<iostream>
using namespace std;

int largestPiece(int** edges, bool** visited, int n, int i, int j, int count) {

    if(i < 0 || i > n || j < 0 || j > n) {

        return count;

    }

    visited[i][j] = true;

    if(i - 1 >= 0) {

        if(!visited[i - 1][j] && edges[i - 1][j] == 1) {

            count++;
            largestPiece(edges, visited, n, i - 1, j, count);

        }

    }

    if(i + 1 < n) {

        if(!visited[i + 1][j] && edges[i + 1][j] == 1) {

            count++;
            largestPiece(edges, visited, n, i + 1, j, count);

        }

    }

    if(j - 1 >= 0) {

        if(!visited[i][j - 1] && edges[i][j - 1] == 1) {

            count++;
            largestPiece(edges, visited, n, i, j - 1, count);

        }

    }

    if(j + 1 < n) {

        if(!visited[i][j + 1] && edges[i][j + 1] == 1) {

            count++;
            largestPiece(edges, visited, n, i, j + 1, count);

        }

    }

}

int main() {

    int n;
    cin >> n;

    int** edges = new int*[n];

    for(int i = 0; i < n; i++) {

        edges[i] = new int[n];

        for(int j = 0; j < n; j++) {

            cin >> edges[i][j];

        }

    }

    bool** visited = new bool*[n];

    for(int i = 0; i < n; i++) {

        visited[i] = new bool[n];

        for(int j = 0; j < n; j++) {

            visited[i][j] = false;

        }

    }

    int max = INT_MIN;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(!visited[i][j] && edges[i][j] == 1) {

                int count = 0;
                int temp = largestPiece(edges, visited, n, i, j, count);

                if(temp > max) {

                    max = temp;

                }

            }

        }

    }

    cout << max << endl;

}