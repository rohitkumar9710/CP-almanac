### Topic name - Graph
 
### Sub-topic - Clique

<br>

### What is clique in graph?
#### A clique is subset(subgraph) of vertices of graph such that any two vertices of the subset are connected ( adjacent) to each other i.e each vertex of the subset should be connected with every other vertices of the subset.

<br>

### Explanation 
#### To demonstrate what has been told above , we will solve famous two clique problem. In this problem , we are given a graph , we need to check whether given graph can be divided into two cliques.  Before moving ahead we will learn two concepts to solve this problem :
#### 1. Complement of a graph : To find the complement of a graph , we remove all actual edges and add edges between vertices which didn't have edge earlier.
#### 2. Bipartite graph :  If graph can be coloured from only two colours such that any two vertices of same colour are not adjacent(connected),  then graph is bipartite.
#### Algorithm : If complement of graph is bipartite , then graph can be divided into two cliques otherwise not . But why does this work? 
#### If complement of graph is bipartite, then we can the partition the complement graph into two disjoint sets , such that there is no edge connecting the vertices of the same set. Then in actual graph, these two sets have the property of being a clique( each vertex of the set is connected with every other verex).

<br>
Code :

<br>

### Practice Problems
#### 1. https://www.geeksforgeeks.org/find-all-cliques-of-size-k-in-an-undirected-graph/?ref=rp
#### 2. https://www.geeksforgeeks.org/maximal-clique-problem-recursive-solution/?ref=rp
#### 3. https://www.geeksforgeeks.org/count-the-number-of-prime-cliques-in-an-undirected-graph/?ref=rp

<br>
