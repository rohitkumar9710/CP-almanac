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
They are used while transmission of fax and text.
It is best used in cases where re-occuring characters are present in the database.
It is used to compress algorithms like DEFLATE,JPEG and MP3.
#### Steps to build Huffman Tree 
An array of unique characters along with their frequencies is input and the Huffman Tree is obtained as output. 
Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
From the min heap, proceed by extracting the two nodes with least frequencies. 

With the new frequency equal to the sum of the prior two nodes' frequencies, generate a new node. The first and the second extracted node become the left child and the right child respectively. Add the newly generated node to the min heap. 
Repeat the above steps until the heap contains only one node. The process of creating a Huffman tree concludes with the single only node, known as the root node.
Let us understand the algorithm with an example:<br>
character   Frequency<br>
    a    ---------- 5<br>
    b    ---------- 9<br>
    c    ---------- 12<br>
    d    ---------- 13<br>
    e    ---------- 16<br>
    f    ---------- 45<br>


Step 1. Begin to build a min heap containing 6 nodes of which each node represents root of a tree with single node.

Step 2.Proceed by extracting two nodes of minimum frequency from min heap. Create a new internal node with frequency the sum of the prior once, i.e. 5 + 9 = 14. 
The min heap, now,  contains 5 nodes of which 4 nodes are roots of trees each containing single element, and one heap node is root of tree with 3 elements.<br>

character           Frequency<br>
       c ---------- 12<br>
       d ----------13<br>
 Internal Node --  14<br>
       e ---------- 16<br>
       f ---------- 45<br>
       ![image](https://user-images.githubusercontent.com/94114688/145012779-6bea5b73-41fc-42fc-9411-913fcc91b74f.png)

       

Step 3.Proceed by extracting two minimum frequency nodes from heap. Create a new internal node with frequency as the sum of the first two, i.e. 12 + 13 = 25.
Now min heap contains 4 nodes where 2 nodes are roots of trees with single element each and two heap nodes are root of tree with more than one nodes<br>

character           Frequency<br>
Internal Node -- 14<br>
       e ---------- 16<br>
Internal Node -- 25<br>
       f ---------- 45<br>
       ![image](https://user-images.githubusercontent.com/94114688/145012884-0e22b635-1ff2-4a7f-9a68-87fb63f60378.png)


Step 4: Extract the next two minimum frequency nodes. Keep creating a new internal node with frequency with frequency as the sum of the previous two nodes, i.e. 14 + 16 = 30.
Now min heap contains 3 nodes(two of which are trees themselves).<br>

character          Frequency<br>
Internal Node  --      25<br>
Internal Node --       30<br>
      f    ----------           45 <br>
![image](https://user-images.githubusercontent.com/94114688/145012911-da7224c2-a2f9-4c69-bfc2-38383c11012f.png)


Step 5: Continue extracting two minimum frequency nodes, which are now 25 and 30. Create a new internal node with frequency 25 + 30 = 55
Now min heap contains 2 nodes, one being a tree.<br>

character     Frequency<br>
       f     ----------    45<br>
Internal Node   -- 55<br>

![image](https://user-images.githubusercontent.com/94114688/145012954-790afb87-50ae-438c-802f-60f2b5c3883e.png)


Step 6: While extracting the two minimum frequency nodes, create a new internal node with frequency as the sum of the only two nodes left, i.e. 45 + 55 = 100
The heap consists of one node.<br>

character      Frequency<br>
Internal Node --   100<br>

![image](https://user-images.githubusercontent.com/94114688/145013016-67275c2c-8a38-4570-a67e-0f9e906a40fd.png)

As the heap now contains only one node, the tree algorithm stops now.
Follow the below steps to print codes from Huffman Tree:
Traverse the tree formed starting from the top(root). Maintain an auxiliary array. While moving to the left child and the right child, write 0 and 1 to the array,respectively. Print the array when a leaf node, or single element node, is encountered.

![image](https://user-images.githubusercontent.com/94114688/145013066-b41f591a-a4af-431e-bd4e-f31afd49930c.png)

The codes obtained from the tree are as followed:
character    code-word<br>

    f   ----------       0<br>
    c    ----------      100<br>
    d       ----------   101<br>
    a     ----------     1100<br>
    b       ----------   1101<br>
    e    ----------      111<br>



###Link to practice question -
https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
