### Question
Consider a grid in which some cells are empty and some cells are filled. Call a cell in this grid `exitable` if, starting at that cell, you can exit the grid by moving up and left through only empty cells. This includes the cell itself, so all filled in cells are not exitable. Note that you can exit the grid from any leftmost empty cell (cell in the first column) by going left, and from any topmost empty cell (cell in the first row) by going up.<br>

Let's call a grid `determinable` if, given only which cells are exitable, we can exactly determine which cells are filled in and which aren't.<br>

You are given a grid a of dimensions `n×m` , i. e. a grid with n rows and m columns. You need to answer q queries (1≤q≤2⋅10<sup>5</sup>). Each query gives two integers x<sub>1</sub>,x<sub>2</sub> (1≤x<sub>1</sub>≤x<sub>2</sub>≤m) and asks whether the subgrid of a consisting of the columns x<sub>1</sub>,x<sub>1</sub>+1,…,x<sub>2</sub>−1,x<sub>2</sub> is determinable.<br>

### Input
The first line contains two integers n,m (1≤n,m≤10<sup>6</sup>, `n.m`≤10<sup>6</sup>)  — the dimensions of the grid a.<br>

n lines follow. The y-th line contains m characters, the x-th of which is 'X' if the cell on the intersection of the the y-th row and x-th column is filled and "." if it is empty.<br>

The next line contains a single integer q (1≤q≤2⋅10<sup>5</sup>)  — the number of queries.<br>

q lines follow. Each line contains two integers x<sub>1</sub>,x<sub>2</sub> (1≤x<sub>1</sub>≤x<sub>2</sub>≤m), representing a query asking whether the subgrid of a containing the columns x<sub>1</sub>,x<sub>1</sub>+1,…,x<sub>2</sub>−1,x<sub>2</sub> is determinable.<br>

Output
For each query, output one line containing "YES" if the subgrid specified by the query is determinable and "NO" otherwise. The output is case insensitive (so "yEs" and "No" will also be accepted).