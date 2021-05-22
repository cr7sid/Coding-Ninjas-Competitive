#include <iostream>
#include <vector>
using namespace std;

int dfs_search(vector<vector<char>> &board,int n,int m,int i,int j,int **visited,char current_char){
    visited[i][j]=1;
    // base case
    // check if any 2 directions from current are visited - means path found
    int count=0;
    // up
    if(i-1>=0){
        if(visited[i-1][j]==1){
            count++;
        }
    }
    // down
    if(i+1<n){
        if(visited[i+1][j]==1){
            count++;
        }
    }
    // left
    if(j-1>=0){
        if(visited[i][j-1]==1){
            count++;
        }
    }
    // right
    if(j+1<m){
        if(visited[i][j+1]==1){
            count++;
        }
    }
    if(count>=2){
        return 1;
    }
    // ---------------------------------------------------------------------------------
    // find next routes

    int ans=0;
    while(1){
        // check top
        if(i-1>=0){
            if(board[i-1][j]==current_char&&visited[i-1][j]==0){
                ans=dfs_search(board,n,m,i-1,j,visited,current_char);
            }
        }
        if(ans==1) break;
        // check bottom
        if(i+1<n){
            if(board[i+1][j]==current_char&&visited[i+1][j]==0){
                ans=dfs_search(board,n,m,i+1,j,visited,current_char);
            }
        }
        if(ans==1) break;
        // check left
        if(j-1>=0){
            if(board[i][j-1]==current_char&&visited[i][j-1]==0){
                ans=dfs_search(board,n,m,i,j-1,visited,current_char);
            }
        }
        if(ans==1) break;
        // check right
        if(j+1<m){
            if(board[i][j+1]==current_char&&visited[i][j+1]==0){
                ans=dfs_search(board,n,m,i,j+1,visited,current_char);
            }
        }
        if(ans==1) break;
        break;
    }
    visited[i][j]=0;
    return ans;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    int **visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char current=board[i][j];
            int result=dfs_search(board,n,m,i,j,visited,current);
            if(result==1){
                return true;
            }
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         visited[i][j]=0;
            //     }
            // }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasCycle(board, n, m) ? "true" : "false");
}