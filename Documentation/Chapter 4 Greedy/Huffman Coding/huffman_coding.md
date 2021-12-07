### Topic name - HUFFMAN CODING
### Sub-topic - Greedy

<br>

### Definition -Huffman coding is one of the various methods originating from Greedy Method of Optimization. 
It is a step-by-step algorithm dealing with transformation of data to reduce storage size without any loss.  

#### The algorithm involves assigning code to the characters of the data in a strategic and systematic manner, depending on the frequencies of occurance of a character.
The codes are assigned such that the character with minimum frequency has the longest code and the length of the code decreasing for more reoccuring characters.
The assigned data is ensured to follow the Prefix Code System.
The Prefix Code states that the code assigned to any of the data characters is not the prefix of the code assigned to another character.
This prevents dubeity while decoding the coded data.

<br>

### Explanation (along with examples)
#### TYPES
There are mainly two major parts in Huffman Coding
Build a Huffman Tree from input characters.
Traverse the Huffman Tree and assign codes to characters.

<br>

### Application-
They are used for transmitting fax and text.
They are used by conventional compression formats like PKZIP, GZIP, etc.
 It is useful in cases where there is a series of frequently occurring characters.
#### Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree. 
Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
Extract two nodes with the minimum frequency from the min heap.
 
Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.
Let us understand the algorithm with an example:
character   Frequency
    a           5
    b           9
    c           12
    d           13
    e           16
    f           45


Step 1. Build a min heap that contains 6 nodes where each node represents root of a tree with single node.

Step 2 Extract two minimum frequency nodes from min heap. Add a new internal node with frequency 5 + 9 = 14. 
Now min heap contains 5 nodes where 4 nodes are roots of trees with single element each, and one heap node is root of tree with 3 elements

character           Frequency
       c               12
       d               13
 Internal Node         14
       e               16
       f                45

Step 3: Extract two minimum frequency nodes from heap. Add a new internal node with frequency 12 + 13 = 25
Now min heap contains 4 nodes where 2 nodes are roots of trees with single element each, and two heap nodes are root of tree with more than one nodes

character           Frequency
Internal Node          14
       e               16
Internal Node          25
       f               45

Step 4: Extract two minimum frequency nodes. Add a new internal node with frequency 14 + 16 = 30 
Now min heap contains 3 nodes.

character          Frequency
Internal Node         25
Internal Node         30
      f               45 

Step 5: Extract two minimum frequency nodes. Add a new internal node with frequency 25 + 30 = 55
Now min heap contains 2 nodes.

character     Frequency
       f         45
Internal Node    55

Step 6: Extract two minimum frequency nodes. Add a new internal node with frequency 45 + 55 = 100
Now min heap contains only one node.

character      Frequency
Internal Node    100
Since the heap contains only one node, the algorithm stops here.

Steps to print codes from Huffman Tree:
Traverse the tree formed starting from the root. Maintain an auxiliary array. While moving to the left child, write 0 to the array. While moving to the right child, write 1 to the array. Print the array when a leaf node is encountered.
The codes are as follows:

character   code-word
    f          0
    c          100
    d          101
    a          1100
    b          1101
    e          111


<br>
