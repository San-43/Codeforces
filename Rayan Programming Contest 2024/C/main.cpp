#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

enum State { UNVISITED, VISITING, VISITED };

int n, m;
char maze[MAX_N][MAX_M];
State state[MAX_N][MAX_M];  // Estado de cada celda: UNVISITED, VISITING, VISITED
bool isTrapped[MAX_N][MAX_M];  // Si la celda está atrapada en un ciclo

// Direcciones correspondientes a 'U', 'D', 'L', 'R'
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char directions[] = {'U', 'D', 'L', 'R'};

bool inBounds(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// DFS para detectar ciclos
bool dfs(int x, int y) {
    if (!inBounds(x, y)) return false;

    if (state[x][y] == VISITING) return true;  // ciclo detectado
    if (state[x][y] == VISITED) return false;  // ya procesada, no hay ciclo

    state[x][y] = VISITING;  // Marcar como en proceso

    // Mover según la dirección de la celda
    int nx = x, ny = y;
    if (maze[x][y] == 'U') nx--;
    else if (maze[x][y] == 'D') nx++;
    else if (maze[x][y] == 'L') ny--;
    else if (maze[x][y] == 'R') ny++;

    if (dfs(nx, ny)) {
        isTrapped[x][y] = true;  // Marcar la celda como atrapada
        return true;
    }

    state[x][y] = VISITED;  // Marcar como procesada
    return false;
}

void solve() {
    memset(state, UNVISITED, sizeof(state));
    memset(isTrapped, false, sizeof(isTrapped));

    // Inicializamos con las direcciones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] != '?' && state[i][j] == UNVISITED) {
                dfs(i, j);
            }
        }
    }

    // Ahora llenamos las celdas con '?' de forma que maximicemos los ciclos
    int trappedCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '?') {
                // Asignar dirección de forma que se maximicen los ciclos.
                // Tomamos decisiones en función de las celdas adyacentes para formar ciclos.
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir], ny = j + dy[dir];
                    if (inBounds(nx, ny) && isTrapped[nx][ny]) {
                        maze[i][j] = directions[dir];
                        break;
                    }
                }
            }
            if (isTrapped[i][j]) {
                trappedCount++;
            }
        }
    }

    cout << trappedCount << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maze[i][j];
            }
        }

        solve();
    }

    return 0;
}
