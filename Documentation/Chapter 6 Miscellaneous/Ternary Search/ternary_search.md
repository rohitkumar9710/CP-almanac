## Ternary Search
 
<br>

### What is Ternary Search?
#### Ternary Search is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element). We can divide the array into three parts by taking mid1(denoted by m1) and mid2(denoted by m2) which can be calculated as shown below. Initially, l and r will be equal to 0 and n-1 respectively, where n is the length of the array. 
![image](https://user-images.githubusercontent.com/62798923/145089272-07f637e6-3642-4fa7-808a-ec992b19c52b.png)

#### Note : Array needs to be sorted to perform ternary search on it.
<br>

### Algorithm : 
#### 1. First, we compare the key with the element at mid1. If found equal, we return mid1.
#### 2. If not, then we compare the key with the element at mid2. If found equal, we return mid2.
#### 3. If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
#### 4. If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
#### 5. If not, then we recur to the second (middle) part.
![image](https://user-images.githubusercontent.com/62798923/145089421-0af61e37-c3f9-4cc2-8a41-ab827585ad1a.png)


<br>

### Iterative implementation :
``` 
#include <iostream>
using namespace std;

// Function to perform Ternary Search
int ternarySearch(int l, int r, int key, int ar[])

{
	while (r >= l) {
		// Find the mid1 and mid2
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;

		// Check if key is present at any mid
		if (ar[mid1] == key) {
			return mid1;
		}
		if (ar[mid2] == key) {
			return mid2;
		}

		// Since key is not present at mid,
		// check in which region it is present
		// then repeat the Search operation
		// in that region

		if (key < ar[mid1]) {
    
			// The key lies in between l and mid1
			r = mid1 - 1;
		}
		else if (key > ar[mid2]) {
    
			// The key lies in between mid2 and r
			l = mid2 + 1;
		}
		else {
    
			// The key lies in between mid1 and mid2
			l = mid1 + 1;
			r = mid2 - 1;
		}
	}

	// Key not found
	return -1;
}

int main()
{
	int l, r, p, key;

	// Get the array
	// Sort the array if not sorted
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Starting index
	l = 0;

	// length of array
	r = 9;

	// Checking for 5

	// Key to be searched in the array
	key = 5;

	// Search the key using ternarySearch
	p = ternarySearch(l, r, key, ar);

	// Print the result
	cout << "Index of "<<key<<" is " << p << endl;

	// Checking for 50

	// Key to be searched in the array
	key = 50;

	// Search the key using ternarySearch
	p = ternarySearch(l, r, key, ar);

	// Print the result
	cout << "Index of "<<key<<" is " << p;
}
```

### Recursive implementation :
```
#include <bits/stdc++.h>
using namespace std;

// Function to perform Ternary Search
int ternarySearch(int l, int r, int key, int ar[])
{
	if (r >= l) {
		// Find the mid1 and mid2
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;

		// Check if key is present at any mid
		if (ar[mid1] == key) {
			return mid1;
		}
		if (ar[mid2] == key) {
			return mid2;
		}

		// Since key is not present at mid,
		// check in which region it is present
		// then repeat the Search operation
		// in that region
		if (key < ar[mid1]) {
    
			// The key lies in between l and mid1
			return ternarySearch(l, mid1 - 1, key, ar);
		}
		else if (key > ar[mid2]) {
    
			// The key lies in between mid2 and r
			return ternarySearch(mid2 + 1, r, key, ar);
		}
		else {
    
			// The key lies in between mid1 and mid2
			return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
		}
	}

	// Key not found
	return -1;
}

int main()
{
	int l, r, p, key;

	// Get the array
	// Sort the array if not sorted
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Starting index
	l = 0;

	// length of array
	r = 9;

	// Checking for 5

	// Key to be searched in the array
	key = 5;

	// Search the key using ternarySearch
	p = ternarySearch(l, r, key, ar);

	// Print the result
	cout << "Index of " << key
		<< " is " << p << endl;

	// Checking for 50

	// Key to be searched in the array
	key = 50;

	// Search the key using ternarySearch
	p = ternarySearch(l, r, key, ar);

	// Print the result
	cout << "Index of " << key
		<< " is " << p << endl;
}

```  
### Output :
```
Index of 5 is 4
Index of 50 is -1
```

### Time Complexity :
![image](https://user-images.githubusercontent.com/62798923/145089514-58aad11e-c6a7-4096-938c-98d49715a56b.png)
#### It can be visualized as follows: every time after evaluating the function at points m1 and m2, we are essentially ignoring about one third of the interval, either the left or right one. Thus the size of the search space is 2n/3 of the original one. Using master theorem, we can solve above recurrence , to get desired result.

### Space Complexity : 
#### Since we are using constant space , so space complexity is O(1).

<br>

### Practice Problems
#### 1. https://www.codechef.com/problems/AMCS03
#### 2. https://www.spoj.com/problems/KOPC12A/
#### 3. https://codeforces.com/problemset/problem/578/C

<br>
