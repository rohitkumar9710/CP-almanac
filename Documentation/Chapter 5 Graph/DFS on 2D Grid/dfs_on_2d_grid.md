
## DFS on 2D Grid
<br>

### What actually is DFS on 2-D Grid?
#### Depth First Search on 2-D Grid is a basic algorithm for traversing or searching 2-D grids. Idea explained here can also be extended to grids with more than 2 dimensions.

<br>

### Let's dive deeper in it
#### Approach : 
#### Depth First Search (DFS) on 2D Grid is similar to DFS on graph , so we can interpret each grid cell as node of a graph but here edges will always in between adjacent grid cells(up,down,left,right). The algorithm starts at the root node (we can select some arbitrary grid cell as the root node) and explores as far as possible along each cell before backtracking. So the basic idea is to start from the root or any arbitrary grid cell and mark the grid cell as visited and move to the adjacent unmarked grid cell and continue traversing until there is no unmarked grid cell.
#### Algorithm :
#### 1. Initialize an auxiliary boolean 2D array of dimensions equal to grid size with all values as false, which is used to mark the visited cells.
#### 2. Declare a function isValid() to check if the cell coordinates are valid or not, i.e lies within the boundaries of the given grid and is unvisited.
#### 3. Create a recursive function that takes coordinates of the grid cell to be visited next, grid array,and bool visited array as input.
#### 4. Call the function created above with any valid grid cell coordinates.
#### 5. Mark the current grid cell as visited and print the value contained in grid cell.
#### 6. Traverse all the adjacent grid cells of current cell and call the recursive function with the coordinates of the adjacent valid grid cells.
#### Note: Direction vectors are used to traverse the adjacent cells of a given cell in a given order. For example, (x, y) is a cell whose adjacent cells (x – 1, y), (x, y - 1), (x + 1, y), (x, y + 1) need to be traversed, then it can be done using the direction vectors (-1, 0), (0, -1), (1, 0), (0, 1) in the up, left, down and right order.

#### Code : 
```
// C++ program of the above approach
#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3

// Initialize direction vectors
int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

// Function to check if mat[row][col]
// is unvisited and lies within the
// boundary of the given matrix
bool isValid(bool vis[][COL], int row, int col)
{
    // If cell is out of bounds
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return false;

    // If the cell is already visited
    if (vis[row][col])
        return false;

    // Otherwise, it can be visited
    return true;
}

// Function to perform DFS
// Traversal on the matrix grid[]
void DFS(int row, int col, int grid[][COL], bool vis[][COL])
{
    // Check if the current cell is a valid cell or not
    if (!isValid(vis, row, col))
        return;

    // Mark the current
    // cell as visited
    vis[row][col] = true;

    // Print the value of the current cell
    cout << grid[row][col] << " ";

    // Call DFS for all the adjacent cells
    for (int i = 0; i < 4; i++)
    {
        int adjx = row + dRow[i];
        int adjy = col + dCol[i];
        DFS(adjx, adjy, grid, vis);
    }
}

int main()
{
    int grid[3][3] = {{-1, 2, 3},
                      {0, 9, 8},
                      {1, 0, 1}};

    // Stores whether the current
    // cell is visited or not
    bool vis[3][3];
    memset(vis, false, sizeof vis);

    // Function call
    DFS(0, 0, grid, vis);

    return 0;
}
```
#### Output :
```
 -1 2 3 8 1 0 9 0 1
 ```
 <br>
 
 ![image](https://user-images.githubusercontent.com/62798923/144748067-47ff5d30-bb12-45b6-9730-e7332e9d6b64.png)

<br>

### Practice Problems
#### 1. https://leetcode.com/problems/detect-cycles-in-2d-grid/ <!--medium problem-->
#### 2. https://leetcode.com/problems/unique-paths-iii/ <!--hard problem-->
#### 3. https://codeforces.com/problemset/problem/1613/E <!--hard problem-->

<br>
