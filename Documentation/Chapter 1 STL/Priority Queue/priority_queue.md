# STL priority_queues

### Defination : 
<li>Priority queue is a data structure.
Every data structure is designed to perform effectively for some special purposes. Example, Binary Search tree is a data structure whose one of the major functionality is searching an element in O(1).

So lets see in which cases priority queue performs the best
## Functionality of priority_queues
<li>To get highest priority element
<li>To insert element
<li>To delete highest priority element

Yes Yes your thinking right . This are the functionalities those set/multiset can also perform and you are wondering why again priority queue.

The reason is ,in set all elements to be in ordered but here they need not be . Because we only need the highest priority element we don’t care about remaining elements until it is there in the priority queue where as in set we need to traverse through entire set for some of its functionalities like searching an element.

Now the main question comes is which underlying data structure we need to use to implement priority queue.

We can use arrays, linked list, heaps but we prefer heaps as it takes less time for heaps to perform those functionalities.

The library needed to be included for this is<br>
`#include<queue>`<br>
or<br>
`#include<bits/stdc++.h>`

### Declaration of priority queue
**To maintain elements according to highest priority**
```
priority_queue<int>
```

**To maintain elements according to lowest priority**
```
priority_queue<int,vector<int>,greater<int>>
```
**int** is the data type of the elements in priority queue. Here elements can be sets,vectors,queues,trees,..So for them we need to mention there data type like `set<int>`,`vector<int>`,`queue<int>`,`struct node *`,.. respectively

## **Main** Functions in priority_queue STL 
As the name itself is saying it is nothing but queue so all the functions will be same as queue

### push :
Inserts element into the priority queue

### top :
Returns the first element in the priority queue

### empty : 
Returns a boolean variable . If it is true then the priority queue is empty ,else it is not empty

### size : 
Returns number of elements in the priority queue

Now lets see an example for more clarification

```
Lets say there is a priority queue pq 
push(10) // inserting element 10 in priority queue
pq : 10
push(15) // inserting element 15 in priority queue
pq : 15 10
push(11) // inserting element 11 in priority queue
pq : 15 11 10
push(5) // inserting element 5 in priority queue
pq : 15 11 10 5
pop() // Remove the top priority element
pq : 11 10 5
```
**NOTE :** The elements after the highest priority element need not be in an order (the reason I have kept sorted is to avoid confusion while seeing example) because you can see max heap where elements will not be stored in a sorted order.

Priority queue where elements are stored according to high priority (Can be considered as max heap)
CODE : 
```
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq_max;
    pq_max.push(10);
    pq_max.push(100);
    pq_max.push(1000);
    pq_max.push(10000);
    pq_max.push(100000);
    cout<<"Number of elements are : "<<pq_max.size()<<endl;
    cout<<"Elements are : ";
    while(!pq_max.empty()){
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }
    cout<<endl;
}
```
**OUTPUT :** 
```
Number of elements are : 5
Elements are : 100000 10000 1000 100 10
```
Priority queue where elements are stored according to low priority (Can be considered as min heap)
CODE :
```
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> pq_min;
    pq_min.push(10);
    pq_min.push(100);
    pq_min.push(1000);
    pq_min.push(10000);
    pq_min.push(100000);
    cout<<"Number of elements are : "<<pq_min.size()<<endl;
    cout<<"Elements are : ";
    while(!pq_min.empty()){
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    cout<<endl;
}
```
**OUTPUT :** 
```
Number of elements are : 5
Elements are : 10 100 1000 10000 100000
```

## Applications 
One of the main applications of priority queue is dijkstra's algorithm where we will be finding shortest distance between two vertices

prerequisite : graphs

Lets say there are n vertices and m weighted edges. Now we want to find minimum distance between vertex a (source vertex) and vertex b (destination vertex).We will perform **breadth first search** . We are maintaining a distance array ‘dist’ in this algorithm where dist[i] represents distance of vertex i from source vertex.

### Brief explanation of Algorithm :
Select a vertex from where distance of that vertex from source vertex will be less. Explore all its adjacent vertices and update there distance (How to update will be explained in pseudo code).To select a vertex we will be using priority queue.

### Pesudo Code : 
```
1.Maintain priority_queue for BFS. Where each element is a pair .First value is distance value from vertex a and second value is vertex number.
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>> pq;
2.push vertex a in pq
pq.push({0,a});
since distance between vertex a and vertex a is zero
3.Now perform BFS. pop first element from priority_queue and check the following condition for all of its adjacent vertexes.
if(dist[adjacent_vertex]>dist[present_vertex]+weight_adjv_pres){
    /*If the veretx is already in the priority_queue we are removing it */
    if(pq.find({dist[adjacent_vertex]})!=pq.end()){
        pq.erase(pq.find({dist[adjacent_vertex]}));
    }
    /*We are updating distance array*/
    /*weight_adjv_pres represents weight of the edge which is connecting adjacent_vertex and the vertex we poped (present_vertex) */
    dist[adjacent_vertex]=dist[present_vertex]+weight_adjv_pres;
    /*Pushing this adjacent vertex into priority_qeueue along with its distance from vertex a*/
    pq.push({dist[adjacent_vertex],adjacent_vertex});
}
Now the final answer will be dist[b] because it denotes distance of vertex b from vertex a.
```

## Practice problems
[Top K frequent elements](https://leetcode.com/problems/top-k-frequent-elements/)

[Find the Kth Smallest Sum of a Matrix With Sorted Rows](https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)

[Potions (Hard version)](https://codeforces.com/contest/1526/problem/C2)

This are the problems that I felt good . You can search for more in leetcode and codeforces and codechef under the tag priority queue.

