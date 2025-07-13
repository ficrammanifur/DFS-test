// dfs_fire_sim.cpp
#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 7;
const int COLS = 7;

vector<vector<char>> maze = {
    {'.', '.', '.', '.', '#', '.', '.'},
    {'#', '#', '.', '.', '#', 'F', '.'},
    {'F', '#', '.', '.', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '.', '.', '#', '#', '#'},
    {'.', '.', '.', '.', '#', '.', 'F'},
    {'F', '#', '.', '.', '.', '.', '.'}
};

vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

int fireCount = 0; // jumlah api yang berhasil dipadamkan

void dfs(int x, int y) {
    // Batas & obstacle
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) return;
    if (maze[x][y] == '#' || visited[x][y]) return;

    visited[x][y] = true;
    cout << "🔍 Visiting: (" << x << "," << y << ")" << endl;

    if (maze[x][y] == 'F') {
        cout << "🔥 Fire found at (" << x << "," << y << ") - Extinguishing!" << endl;
        maze[x][y] = 'E'; // extinguished
        fireCount++;
    }

    // DFS ke 4 arah: atas, kanan, bawah, kiri
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dfs(nx, ny);
    }
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

    dfs(0, 0); // start dari kiri atas

    printMaze();
    cout << "✅ Simulation done.\n";
    cout << "🔥 Total fires extinguished: " << fireCount << endl;
    return 0;
}
