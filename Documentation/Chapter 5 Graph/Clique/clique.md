## Clique in graph

<br>

### What is clique in graph?
#### A clique is subset of vertices of graph such that any two vertices of the subset are connected ( adjacent) to each other i.e each vertex of the subset is connected with every other vertices of the subset.

<br>

### Explanation 
#### To demonstrate what has been explained above , we will solve famous two clique problem. In this problem , we are given a graph , we need to check whether given graph can be divided into two cliques or not.  Before moving ahead we will learn two new concepts to solve this problem :
![image](https://user-images.githubusercontent.com/62798923/145722749-a923032e-35e9-4f8b-bf90-0bf11cfa9b0a.png)


#### 1. Complement of a graph : To find the complement of a graph , we remove all actual edges and add edges between vertices which didn't have edge earlier.
![image](https://user-images.githubusercontent.com/62798923/145722948-71fd37b8-b268-4c45-a1ca-f4ee7e69bfd6.png)

#### 2. Bipartite graph :  If graph can be coloured from only two colours such that any two vertices of same colour are not adjacent(connected),  then graph is bipartite.
![image](https://user-images.githubusercontent.com/62798923/145722120-0ebf19bb-44a5-4e3c-b70c-6e8145a362e9.png)



#### Algorithm : If complement of graph is bipartite , then graph can be divided into two cliques otherwise not .
#### But why does this algorithm is correct? 
#### If complement of graph is bipartite, then we can the partition the complement graph into two disjoint sets , such that there is no edge connecting the vertices of the same set. Then in actual graph, these two sets have the property of being a clique( each vertex of the set is connected with every other vertex).

### Pseudocode :
```
  bool function for bipartness check of graph component(input graph, current node, color array, current color)
  {
      if node is already painted , and its color is different from current color, return false;
      Paint the node with current color
      FOR each neighbour of node{
         if not colored : paint it with color different from current color
         else : if color is same as current color, return false
      }
      Bipartite coloring has been done, return true
      
  }
  bool function for color initialisation and call for bipartness check for each component (input graph){
        Initialise color of each node of the graph with -1, denoting node is not painted yet
        FOR each not painted node : Function call for bipartness check 
  }
  bool function for checking the division into two cliques and for finding complement (input graph){
          Create another graph ,complement
          FOR each edge not present in input graph, add that edge in complement graph
          Function call for bipartness check of the complement graph
          if complement graph is bipartite then division is possible otherwise not, return that 
  }
  main function() {
      input graph 
      Function call for division check
  ]
  
```
### Code :
```

#include <bits/stdc++.h>
using namespace std;
  
const int max_edges = 5;
  
bool Bipartite(int Graph[][max_edges], int node, int color_node[],int val)
{
    if(color_node[node] != -1 && color_node[node] !=val)// If node is coloured and its color is same as adjacent node, then graph is not bipartite.
        return false;
         
    // color cuurent node with val and all its adjacent nodes as 1-val.
    color_node[node] = val;
    bool ok = true;
    for(int i=0;i<max_edges;i++){
        if(Graph[node][i]){
            if(color_node[i] == -1)
                ok = ok& Bipartite(Graph,i,color_node,1-val);//Recur(color) for neighbours.
                 
            if(color_node[i] !=-1 && color_node[i] != 1-val)// If neighbour is coloured and its color is not equal to 1-val, then return false.
                return false;
        }
        if (!ok)
            return false;
    }
     
    return true;
}
  
// To  check the bipartness of Graph[][]. Here,  graph may be disconnected as well.
bool Bipartite_check(int Graph[][max_edges])
{
    // Color array to store the color of each node.
    // Color of node having value 'i' is denoted as color_node[i]
    // Colors : 0 and 1
    int color_node[max_edges];
    for (int i = 0; i < max_edges; ++i)
        color_node[i] = -1;
  
    for (int i = 0; i < max_edges; i++)
        if (color_node[i] == -1)
            if (Bipartite(Graph, i, color_node,1) == false)//If component is not bipartite , then return false
                return false;
  
    return true;
}
  
bool check(int Graph[][max_edges])// Two check whether it is possible to divide the graph into into cliques or not.
{
    
    int complement[max_edges][max_egdes];
    for (int i=0; i<max_edges; i++)
        for (int j=0; j<max_edges; j++)
             complement[i][j] = (i != j)?  !Graph[i][j] : 0;// Finding complement of the graph
  
    return  Bipartite_check(complement);
}
  
int main()
{
    int Graph[][max_edges] = {{0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
  
    if(check(Graph))
    {
        cout<<"Yes, graph can be divided into two cliques."<<endl;
    }
    else cout<<"No, graph cannot be divided into two cliques"<<endl;
    
    return 0;
}
```
### Output :
```
  Yes, graph can be divided into two cliques.
```
<br>

### Practice Problems
#### 1. https://www.geeksforgeeks.org/find-all-cliques-of-size-k-in-an-undirected-graph/?ref=rp
#### 2. https://www.geeksforgeeks.org/count-the-number-of-prime-cliques-in-an-undirected-graph/?ref=rp

<br>
