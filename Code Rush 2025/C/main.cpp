#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_A = 10, MAX_B = 10, MAX_C = 10;

/// Pero disimulen tantitooooo

int moves[12][3] = {
    { 2,  1,  0},
    { 2, -1,  0},
    {-2,  1,  0},
    {-2, -1,  0},

    { 2,  0,  1},
    { 2,  0, -1},
    {-2,  0,  1},
    {-2,  0, -1},

    { 1,  2,  0},
    {-1,  2,  0},
    { 1, -2,  0},
    {-1, -2,  0}
};

int moves2[12][3] = {
    { 1,  0,  2},
    {-1,  0,  2},
    { 1,  0, -2},
    {-1,  0, -2},

    { 0,  1,  2},
    { 0, -1,  2},
    { 0,  1, -2},
    { 0, -1, -2},

    { 0,  2,  1},
    { 0,  2, -1},
    { 0, -2,  1},
    { 0, -2, -1}
};

int a, b, c;
bool block[MAX_A+1][MAX_B+1][MAX_C+1];

void solve() {
    cin >> a >> b >> c;
    int k;
    cin >> k;

    for (int x = 1; x <= a; x++){
        for (int y = 1; y <= b; y++){
            for (int z = 1; z <= c; z++){
                block[x][y][z] = false;
            }
        }
    }

    for (int i = 0; i < k; i++){
        int x,y,z;
        cin >> x >> y >> z;
        block[x][y][z] = true;
    }

    int left[11][11][11] = {0};
    int right[11][11][11] = {0};

    vector<tuple<int,int,int>> leftCells, rightCells;

    int left_count = 0, right_count = 0;
    for (int x = 1; x <= a; x++){
        for (int y = 1; y <= b; y++){
            for (int z = 1; z <= c; z++){
                if(block[x][y][z]) continue;
                if( (x+y+z) % 2 == 0 ){
                    left[x][y][z] = left_count;
                    leftCells.emplace_back(x,y,z);
                    left_count++;
                } else {
                    right[x][y][z] = right_count;
                    rightCells.emplace_back(x,y,z);
                    right_count++;
                }
            }
        }
    }

    vector<vector<int>> graph(left_count);

    auto ok = [&](const int x, const int y, const int z, const int dx, const int dy, const int dz) {
        int nx = x + dx;
        int ny = y + dy;
        int nz = z + dz;
        if(nx < 1 || nx > a || ny < 1 || ny > b || nz < 1 || nz > c)
            return false;
        if(block[nx][ny][nz])
            return false;
        return true;
    };

    for (const auto &cell : leftCells){
        int x, y, z;
        tie(x, y, z) = cell;
        const int u = left[x][y][z];

        for (const auto & move : moves){
            const int dx = move[0];
            const int dy = move[1];
            const int dz = move[2];
            if(ok(x,y,z,dx,dy,dz)){
                const int nx = x+dx;
                const int ny = y+dy;
                const int nz = z+dz;
                if((nx+ny+nz) % 2 == 1){
                    int v = right[nx][ny][nz];
                    graph[u].push_back(v);
                }
            }
        }
        for (auto & i : moves2){
            const int dx = i[0];
            const int dy = i[1];
            const int dz = i[2];
            if(ok(x,y,z,dx,dy,dz)){
                const int nx = x+dx;
                const int ny = y+dy;
                const int nz = z+dz;
                if((nx+ny+nz) % 2 == 1){
                    int v = right[nx][ny][nz];
                    graph[u].push_back(v);
                }
            }
        }
    }

    vector<int> matchR(right_count, -1);

    function<bool(int, vector<bool>&)> dfs = [&](int u, vector<bool> &used) -> bool {
        for (const int v : graph[u]){
            if(used[v]) continue;
            used[v] = true;
            if(matchR[v] == -1 || dfs(matchR[v], used)){
                matchR[v] = u;
                return true;
            }
        }
        return false;
    };

    int match = 0;
    for (int u = 0; u < left_count; u++){
        if(vector<bool> used(right_count, false); dfs(u, used))
            match++;
    }
    const int ans = left_count + right_count - match;

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}
