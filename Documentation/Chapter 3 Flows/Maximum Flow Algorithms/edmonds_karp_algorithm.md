### Topic name
Flows

### Sub-topic
Edmonds-Karp algorithm
<br>

### Definition

1. Edmonds-Karp algorithm is one of the ways of implementing the Ford-Fulkerson Algorithm.
2. In particular the Edmonds-Karp algorithm uses breadth first search to compute the augmenting path.
3. If there are multiple augmenting paths, the path with smallest length is selected.
4. This way of choosing the augmenting path effectively leads to the computation of the max flow in O(V\*E\*E) time.

The pseudocode is given below<br>
- n = Number of Nodes
- CapacityMatrix[n][n] = CapacityMatrix[i][j] denotes the maximum units of flow that can be sent from node i to node j.
- AdjacencyMatrix[n][n] = AdjacencyMatrix[i][j] denotes whether there exists an edge be node i and node j. A value of 1 indicates
                        the presence of an edge where as 0 means there is no edge.
- SourceNode = This is the Source Node.
- DestinationNode = This is the Destination Node.

Note here it is assumed that all parameters are passed by reference so the changes that we make in the EdmondKarp function will
be reflected in the calling function.

```
EdmondKarp( n, SourceNode, DestinationNode, AdjacencyMatrix, CapacityMatrix)
    MaxFlow = 0
    ResidualMatrix = CapacityMatrix
    // We  initialize the ResidualMatrix to the CapacityMatrix
    MinFlow = 0
    AugmentingPath = []
    while true:
        bfs(CapacityMatrix , AdjacencyMatrix, SourceNode, DestinationNode , ResidualMatrix. MinFlow, AugmentingPath )
        if(MinFlow == 0):
            break
        for each edge(u,v) in AugmentingPath:
            ResidualMatrix[u][v] = ResidualMatrix[u][v] - MinFlow
            ResidualMatrix[v][u] = ResidualMatrix[v][u] + MinFlow
        Maxflow = Maxflow + MinFlow
        AugmentingPath = []
        MinFlow = 0
        //Remove the entries already stored in the AugmentingPath
    return MaxFlow
```
### Explanation
#### Code-Explanation
1. We begin by initializing the Maxflow and ResidualMatrix variables.
2. At each iteration we will be using the MinFlow and AugmentingPath variables so these are also initialized
3. At each iteration we are calling the bfs() function. We pass AdjacencyMatrix, SourceNode, TargetNode, ResidualMatrix as parameters. In addition to this MinFlow
and AugmentingPath are also passed. The bfs() function stores the appropriate path in the AugmentingPath variable, it also stores the minimum flow value along this
path in the MinFlow variable. Note that we are passing all the values by reference here so changes made in the bfs() function will be reflected in the EdmondKarp
function
4. Note that in the bfs function only those are edges are considered whose ResidualMatrix is greater than 0.More precisely we consider a directed edge between two nodes
u and v, if both of the following conditions are met
    * AdjacencyMatrix[u][v] is 1 or AdjacencyMatrix[v][u] = 1
    * ResidualMatrix[u][v] > 0
5. After this we iterate along the edges in the AugmentingPath and subtract MinFlow from the forward edge and add MinFlow to the backward edges, the value of MaxFlow
is incremented.
6. The MinFlow and AugmentingPath variables are set to their initial values so that they can be safely used in the next iteration
7. At the end we simply return the MaxFlow value.

#### Simple Example

![graph-pic1](https://github.com/shubhamshankar28/pcaprepo/blob/main/Edmonds-Karp1.JPG?raw=true)

Here 1 is the source node and 3 is the destination node.
Initially there are three augmenting paths (1,2,3) , (1,4,3) and (1,2,4,3). <br>
Since the algorithm chooses the smallest length path that is one of (1,2,3) or (1,4,3) will be chosen, without loss of generality
let (1,2,3) be chosen. The value of the max flow will be 1000. <br>
Now the residual graph looks like this.

![graph-pic2](https://github.com/shubhamshankar28/pcaprepo/blob/main/Edmonds-Karp2.JPG?raw=true)

At this point (1,4,3) will be chosen as the augmenting path.The value of max flow will be 2000.The residual graph will look like this

![graph-pic3](https://github.com/shubhamshankar28/pcaprepo/blob/main/Edmonds-Karp3.JPG?raw=true)

Now at this point no augmenting paths are present hence the algorithm will terminate and 2000 will be returned as the Max Flow.
<br>

### Application

Edmonds-Karp algorithm can be used to find the size of the maximum matching in a bipartite graph.<br>
A matching in a graph is a set of edges that do not have a set of common vertices. <br>
A maximum matching is the matching with largest size. <br>
Let us see how Edmonds-Karp algorithm can be used to compute the size of the maximum matching in a graph.<br>
Consider the bipartite graph shown below

![graph-pic4](https://github.com/shubhamshankar28/pcaprepo/blob/main/Edmonds-Karp4.JPG?raw=true)

We will add a virtual source node and a virtual destination node. All the undirected edges are converted to directed edges such that the edges
point from source to destination.We must also add directed edges the from the virtual source node 9 to all nodes on the left side. Also we
add directed edges from the nodes on the right hand side to the virtual destination node 10. The capacity of each edge is 1 unit.
The new graph is shown below

![graph-pic5](https://github.com/shubhamshankar28/pcaprepo/blob/main/Edmonds-Karp5.JPG?raw=true)

Edmonds-Karp algorithm is used to compute the maximum flow of this graph. This value of maximum flow is equal to the size of the maximum matching.
We can modify the Edmonds-Karp Algorithm to return the exact flow and thereby we can obtain the edges in the maximum matching.<br>
To do this we consider only the edges between the real nodes , if the flow is assigned to an edge is 1 then it is a part of the maximum matching
otherwise it is not a part of the maximum matching. Note that any edge that is incident to either the virtual source or virtual destination is not
considered.
