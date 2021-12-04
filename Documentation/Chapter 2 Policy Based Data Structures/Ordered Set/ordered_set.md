# POLICY BASED DATA STRUCTURES
## ordered\_set

**What is policy based data structures ?**

It is a library of data structures of associative containers . It is designed for high performance , flexibility, semantic safety and conformance

**What is ordered\_set ?**

It is a data structure which stores elements in sorted order and it is implemented by using red black tree . The main operations of this data structure are : 

- Insertion of element.
- Deletion of element.
- Searching element.
- Finding index of the element in the set.
- Finding kth index element in the set.

Okay it looks fine right . Then you may get doubt that we already have a set data structure which can do the operations mentioned above then are that both the same ones ? The answer is **NO** . Then how come they both are different ?

Both the data structures can do the above operations mentioned but the difference comes in the time complexities of the operations done by set and ordered\_set . The following table describes the time complexities of the operations done by set and ordered\_set.



|**OPERATIONS**|**SET**|**ORDERED\_SET**|
| :-: | :-: | :-: |
|**Insertion**|O(logn)|O(logn)|
|**Deletion**|O(logn)|O(logn)|
|**Searching**|O(logn)|O(logn)|
|**Finding index of given element**|O(n)|O(logn)|
|**Finding Kth index element**|O(n)|O(logn)|

Here n is the number of elements present in the data structure.

Now I hope that you can see that the difference is coming in the last two operations right .Why can’t the set data structure find the index of given element in O(n) ?  Why can’t it do it in the following way to get index of element ?

```int idx=S.lower_bound()-S.begin();```

The above piece of code will throw an error .What could be the reason ? 
**The reason is** in set data structure the iterators are non random-access iterators .
So again What are non random-access iterators , we cannot randomly access elements in set . It will be more clear with an example .

Lets say there is a set S with elements {1,2,3,4,5}
If we want to access Kth element we should start at 1st element which is S.begin() and we need to increment (k-1) times to get Kth element.
Time complexity is O(n) . Since we need to increase n times for nth element.

Where as let say a vector V contains those elements and we want to access Kth element then we can simply write V[k-1] to get the Kth element.
Time complexity is O(1) for vectors. 

We can achieve the last two operations in ordered\_set using order\_of\_key and find\_by\_order methods of ordered\_set.
To use ordered\_set we need to include few libraries .
Libraries need to be included : 
```
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
```
The Container which is to be used here for declaring variables for ordered\_set is :

**tree < int,  null\_type ,  less<int> ,  rb\_tree\_tag , tree\_order\_statistics\_node\_update >**

**Explaination of each terms in above container mentioned is** 

**int :** data type of elements stored in ordered\_set
**null\_type :**  It is mapped policy . It means if it is null\_type then we are using set container 
**less<int> :** It specifies comparator type . less<int> means the elements are stored in ascending order. To get stored in descending order we can use greater<int>.
**rb\_tree\_tag :**  It specifies which data structure to be used for implementing ordered\_set.
**tree\_order\_statistics\_node\_update :** carries necessary operations like size of sub tree .

Now the theory part is done . Lets see few lines of code to experience it practically .

**CODE :**
```
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{
    ordered_set OS;
    /*
    Inserting few elements
    */
    OS.insert(30);
    OS.insert(21);
    OS.insert(36);
    OS.insert(22);
    OS.insert(100);

    /*Lets see how the elements are stored*/
    for(auto element : OS) cout<<element<<" ";
    cout<<endl;

    /*Lets find 3rd element */
    cout << *(OS.find_by_order(3)) << endl;

    /*Lets find index of 36 which is in ordered_set*/
    cout << OS.order_of_key(36) << endl;

    /*Lets find index of 50 which is not in the ordered_set*/
    cout << OS.order_of_key(50) << endl;

    /*Lets delete 22*/
    OS.erase(OS.find(22));

    /*Now lets view the ordered_set*/
    for(auto element : OS) cout<<element<<" ";
    cout<<endl;

    /*Now lets see the 3rd element */
    cout << *(OS.find_by_order(3)) << endl;

    return 0;
}

```
**OUTPUT :** 
```
21 22 30 36 100 
36
3
4
21 30 36 100 
100
```

**Those Problems which are made easy by ordered\_set :**

1. [Find number of count inversions](https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1) .
1. [ORDERSET](https://www.spoj.com/problems/ORDERSET/) .
1. [More problems on order_set](https://leetcode.com/tag/ordered-set/) .


