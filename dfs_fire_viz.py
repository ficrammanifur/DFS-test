# dfs_fire_viz.py
import matplotlib.pyplot as plt
import time

maze = [
    ['.', '.', '.', '.', '#', '.', '.'],
    ['#', '#', '.', '.', '#', '.', '.'],
    ['.', '#', '.', '.', '#', '#', '.'],
    ['.', '.', '.', '.', '.', '.', '.'],
    ['#', '#', '.', '.', '#', '#', '#'],
    ['', '.', '.', '.', '#', '.', '.'],
    ['.', '#', '.', '.', '.', '.', '.']
]

ROWS, COLS = len(maze), len(maze[0])
visited = [[False]*COLS for _ in range(ROWS)]
path = []

def dfs(x, y):
    if x < 0 or x >= ROWS or y < 0 or y >= COLS:
        return False
    if maze[x][y] == '#' or visited[x][y]:
        return False

    visited[x][y] = True
    path.append((x, y))
    draw()

    if maze[x][y] == 'F':
        print(f"🔥 Found fire at ({x},{y}) - Extinguishing!")
        maze[x][y] = 'E'
        draw()
        return True

    time.sleep(0.3)

    for dx, dy in [(-1,0), (0,1), (1,0), (0,-1)]:
        if dfs(x+dx, y+dy):
            return True

    return False

def draw():
    plt.clf()
    colors = {'#':'black', '.':'white', 'F':'red', 'E':'blue'}
    for x in range(ROWS):
        for y in range(COLS):
            color = colors.get(maze[x][y], 'white')
            plt.gca().add_patch(plt.Rectangle((y, ROWS-1-x), 1, 1, color=color, ec='gray'))

    for (x, y) in path:
        plt.gca().add_patch(plt.Circle((y+0.5, ROWS-1-x+0.5), 0.2, color='yellow'))

    plt.xlim(0, COLS)
    plt.ylim(0, ROWS)
    plt.gca().set_aspect('equal')
    plt.pause(0.1)

if __name__ == "__main__":
    print("🚀 Starting DFS Fire Visualization...")
    plt.ion()
    dfs(0, 0)
    plt.ioff()
    plt.show()
    print("✅ Done.")
