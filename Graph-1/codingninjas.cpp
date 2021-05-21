#include<iostream>
#include<string>
using namespace std;

bool DFS(char** Graph, int i, int j, int n, int m, bool** visited, string s) {

    if(s[0] == '\0')
        return true;

    if(i < 0 || j < 0 || i >= n || j >= m)
        return false;

    visited[i][j] = true;

    if(j > 0) {

        if(!visited[i][j - 1] && Graph[i][j - 1] == s[0]) {

            visited[i][j - 1] = true;
            if(DFS(Graph, i, j - 1, n, m, visited, s.substr(1))) return true;
            else visited[i][j - 1] = false;

        }

    }

    if(j < m - 1) {

        if(!visited[i][j + 1] && Graph[i][j + 1] == s[0]) {

            visited[i][j + 1] = true;
            if(DFS(Graph, i, j + 1, n, m, visited, s.substr(1))) return true;
            else visited[i][j + 1] = false;

        }

    }

    if(i < n - 1) {

        if(!visited[i + 1][j] && Graph[i + 1][j] == s[0]) {

            visited[i + 1][j] = true;
            if(DFS(Graph, i + 1, j, n, m, visited, s.substr(1))) return true;
            else visited[i + 1][j] = false;

        }

    }

    if(i > 0) {

        if(!visited[i - 1][j] && Graph[i - 1][j] == s[0]) {

            visited[i - 1][j] = true;
            if(DFS(Graph, i - 1, j, n, m, visited, s.substr(1))) return true;
            else visited[i - 1][j] = false;

        }

    }


    if(i < n - 1 && j < m - 1) {

        if(!visited[i + 1][j + 1] && Graph[i + 1][j + 1] == s[0]) {

            visited[i + 1][j + 1] = true;
            if(DFS(Graph, i + 1, j + 1, n, m, visited, s.substr(1))) return true;
            else visited[i + 1][j + 1] = false;

        }

    }

    if(i > 0 && j > 0) {

        if(!visited[i - 1][j - 1] && Graph[i - 1][j - 1] == s[0]) {

            visited[i - 1][j - 1] = true;
            if(DFS(Graph, i - 1, j - 1, n, m, visited, s.substr(1))) return true;
            else visited[i - 1][j - 1] = false;

        }

    }

    if(i > 0 && j < m - 1) {

        if(!visited[i - 1][j + 1] && Graph[i - 1][j + 1] == s[0]) {

            visited[i - 1][j + 1] = true;
            if(DFS(Graph, i - 1, j + 1, n, m, visited, s.substr(1))) return true;
            else visited[i - 1][j + 1] = false;

        }

    }

    if(i < n - 1 && j > 0) {

        if(!visited[i + 1][j - 1] && Graph[i + 1][j - 1] == s[0]) {

            visited[i + 1][j - 1] = true;
            if(DFS(Graph, i + 1, j - 1, n, m, visited, s.substr(1))) return true;
            else visited[i + 1][j - 1] = false;

        }

    }

    return false;

}

int main() {

    int n, m;
    cin >> n >> m;

    char** Graph = new char*[n];

    for(int i = 0; i < n; i++)  {

		Graph[i] = new char[m];

		for(int j = 0; j < m; j++)
			cin >> Graph[i][j];

	}

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            if(Graph[i][j] == 'C') {

                bool** visited = new bool*[n];

                for(int k = 0; k < n; k++) {

                    visited[k] = new bool[m];

                    for(int l = 0; l < m; l++) {

                        visited[k][l] = false;

                    }

                }

                string s = "ODINGNINJA";

                if(DFS(Graph, i, j, n, m, visited, s)) {

                    cout << "true";
                    return 1;

                }

            }

        }

    }

    cout << "false";
    return 0;

}