/*
    A* Search Algorithm in C++
    --------------------------
    Problem:
    Find the shortest path in a 2D grid from a start cell to a goal cell.

    Grid Representation:
    0 -> Free cell
    1 -> Blocked cell (Obstacle)

    Allowed Moves:
    Up, Down, Left, Right

    Heuristic Used:
    Manhattan Distance:
        h(n) = |x1 - x2| + |y1 - y2|

    Evaluation Function:
        f(n) = g(n) + h(n)

        g(n) = Cost from start to current node
        h(n) = Estimated cost from current node to goal

    Time Complexity:
        O(N log N) using priority queue

    Sample Input:
    Enter number of rows and columns: 5 5

    Enter grid (0 = free, 1 = blocked):
    0 0 0 0 0
    1 1 0 1 0
    0 0 0 1 0
    0 1 1 0 0
    0 0 0 0 0

    Enter start position (row col): 0 0
    Enter goal position (row col): 4 4

    Sample Output:
    Path found:
    (0,0) (0,1) (0,2) (1,2) (2,2) (2,1) (2,0)
    (3,0) (4,0) (4,1) (4,2) (4,3) (4,4)
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int x, y, g, h, f;
    Node(int _x, int _y, int _g, int _h)
    {
        x = _x;
        y = _y;
        g = _g;
        h = _h;
        f = g + h;
    }
};
struct compare
{
    bool operator()(Node a, Node b)
    {
        return a.f > b.f;
    }
};
int heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isvalid(int x, int y, vector<vector<int>> &grid, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 1);
}

void printpath(vector<vector<pair<int, int>>> &parent, int goalx, int goaly)
{
    int x = goalx;
    int y = goaly;
    vector<pair<int, int>> path;

    while (x != -1 && y != -1)
    {
        path.push_back({x, y});
        auto it = parent[x][y];
        x = it.first;
        y = it.second;
    }
    reverse(path.begin(), path.end());
    for (auto it : path)
    {
        cout << "(" << it.first << "," << it.second << ")" << " ";
    }
    cout << endl;
}

void astar(vector<vector<int>> &grid, int startx, int starty, int goalx, int goaly)
{
    int n = grid.size();
    int m = grid[0].size();
    // cost
    vector<vector<int>> gcost(n, vector<int>(m, INT_MAX));
    // vis
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    priority_queue<Node, vector<Node>, compare> pq;
    int h = heuristic(startx, starty, goalx, goaly);
    gcost[startx][starty] = 0;
    pq.push(Node(startx, starty, 0, h));
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();
        int x = curr.x;
        int y = curr.y;

        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        if (x == goalx && y == goaly)
        {
            printpath(parent, goalx, goaly);
            return;
        }
        for (int i = 0; i < 4; i++)
        {

            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (!isvalid(nx, ny, grid, n, m))
                continue;
            if (vis[nx][ny])
                continue;
            int ng = gcost[x][y] + 1;
            if (ng < gcost[nx][ny])
            {
                gcost[nx][ny] = ng;
                parent[nx][ny] = {x, y};
                int newh = heuristic(nx, ny, goalx, goaly);
                pq.push(Node(nx, ny, ng, newh));
            }
        }
    }
    cout << "NO path found" << endl;
}
int main()
{
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter grid (0 = free, 1 = blocked):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    int startX, startY, goalX, goalY;

    cout << "Enter start position (row col): ";
    cin >> startX >> startY;

    cout << "Enter goal position (row col): ";
    cin >> goalX >> goalY;

    // Replace the validation and function call section in main() with this:

    // Validate start and goal
    if (!isvalid(startX, startY, grid, rows, cols))
    {
        cout << "Invalid start position.\n";
        return 0;
    }

    if (!isvalid(goalX, goalY, grid, rows, cols))
    {
        cout << "Invalid goal position.\n";
        return 0;
    }

    // Call the A* function
    astar(grid, startX, startY, goalX, goalY);

    return 0;
}
