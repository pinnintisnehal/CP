#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

int dx[4] = {-1, 1, 0, 0}; // U, D, L, R
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

pair<int, int> start, finish;

bool is_valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && grid[x][y] != '#';
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (make_pair(x, y) == finish) return true;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    return false;
}

string get_path() {
    string path;
    auto [x, y] = finish;

    while (make_pair(x, y) != start) {
        auto [px, py] = parent[x][y];
        for (int d = 0; d < 4; ++d) {
            if (x - dx[d] == px && y - dy[d] == py) {
                path += dir[d];
                break;
            }
        }
        tie(x, y) = parent[x][y];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    parent = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') finish = {i, j};
        }
    }

    if (bfs()) {
        string path = get_path();
        cout << "YES\n" << path.size() << "\n" << path << "\n";
    } else {
        cout << "NO\n";
    }
}
