// link to the problem: https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1}; //generally we only go L, U, R, D
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool isValid(vector<vector<int>>& mat, int i, int j, vector<vector<bool>>& visited) {
    if (i < 0 or j < 0 or i >= mat.size() or j >= mat[0].size() or visited[i][j]
        or mat[i][j] == 0) {
            return false;
        }
    return true;
}

void dfs(vector<vector<int>>& mat, int i, int j, int &area, vector<vector<bool>>& visited) {
    area++;
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        if (isValid(mat, new_i, new_j, visited)) {
            dfs(mat, new_i, new_j, area, visited);
        }
    }
}

int findMaxRegion(vector<vector<int>>& mat) {
    //we will do dfs
    int largestArea = 0;
    // int connected_components = 0;
    vector<vector<bool>> visited(mat.size(), vector<bool> (mat[0].size()));
    for (int i = 0; i < (int)mat.size(); i++) {
        for (int j = 0; j < (int)mat[0].size(); j++) {
            if (!visited[i][j] and mat[i][j] == 1) {
                int area = 0;
                // connnected_components++;
                dfs(mat, i, j, area, visited);
                largestArea = max(largestArea, area);
            }
        }
    }
    // return connected_components;
    return largestArea;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    cout << findMaxRegion(mat) << "\n";
}

void FIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    FIO();
    solve();
    return 0;
}
