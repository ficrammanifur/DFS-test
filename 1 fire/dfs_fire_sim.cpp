// dfs_fire_sim.cpp
#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 7;
const int COLS = 7;

vector<vector<char>> maze = {
    {'.', '.', '.', '.', '#', '.', '.'},
    {'#', '#', '.', '.', '#', '.', '.'},
    {'.', '#', '.', '.', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '.', '.', '#', '#', '#'},
    {'F', '.', '.', '.', '#', '.', '.'},
    {'.', '#', '.', '.', '.', '.', '.'}
};

vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

bool dfs(int x, int y) {
    // Batas dan obstacle
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) return false;
    if (maze[x][y] == '#' || visited[x][y]) return false;

    visited[x][y] = true;
    cout << "🔍 Visiting: (" << x << "," << y << ")" << endl;

    // Ketemu api
    if (maze[x][y] == 'F') {
        cout << "🔥 Fire found at (" << x << "," << y << ") - Extinguishing!" << endl;
        maze[x][y] = 'E'; // extinguished
        return true; // berhenti setelah ketemu api
    }

    // DFS ke 4 arah: atas, kanan, bawah, kiri
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (dfs(nx, ny)) return true;
    }
    return false;
}

void printMaze() {
    cout << "\n=== Maze Status ===" << endl;
    for (const auto& row : maze) {
        for (char c : row) cout << c << ' ';
        cout << endl;
    }
}

int main() {
    cout << "🚀 Starting DFS Fire Simulation...\n";
    printMaze();

    // Start dari kiri atas (0,0)
    dfs(0, 0);

    printMaze();
    cout << "✅ Simulation done.\n";
    return 0;
}
