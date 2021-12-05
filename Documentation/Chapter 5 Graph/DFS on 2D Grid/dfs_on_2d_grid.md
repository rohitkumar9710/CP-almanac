### Topic name - Graph
 
### Sub-topic - DFS on 2D Grid

<br>

### Definition
#### Depth First Search on 2-D Grid is a basic algorithm for traversing or searching 2-D grids. Given idea can also be extended to grids with more than 2 dimensions.

<br>

### Explanation 
#### Approach : 
#### Depth First Search (DFS) on 2D Grid is similar to DFS on graph , so we can interpet each grid cell as node of a graph but here edges will always in between adjacent grid cells(up,down,left,right). The algorithm starts at the root node (we can select some arbitrary grid cell as the root node) and explores as far as possible along each cell before backtracking. So the basic idea is to start from the root or any arbitrary grid cell and mark the grid cell as visited and move to the adjacent unmarked grid cell and continue traversing until there is no unmarked grid cell.
#### Algorithm :
#### Create a recursive function that coordinates of the grid cell to be visited next, vector of vectors storing the grid cell, dimensions of grid cell.
####       1. Mark the current grid cell as visited.
####       2. Traverse all the adjacent and unmarked grid cells of current cell and call the recursive function with the coordinates of the adjacent unmarked grid cells.

<br>

### Application(Only 1)
#### 

<br>

### Practice Problems(2 -3)
#### 1. https://leetcode.com/problems/detect-cycles-in-2d-grid/ <!--medium problem-->
#### 2. https://leetcode.com/problems/unique-paths-iii/ <!--hard problem-->
#### 3. https://codeforces.com/problemset/problem/1613/E <!--hard problem-->

<br>
