## Ternary Search
 
<br>

### What is Ternary Search?
#### Like binary search , ternary search is a searching algorithm, where we divide the array into three parts whereas in binary search, we divide the array in two parts and determine which part contains our value. We can divide the array into three blocks by taking first middle(denoted by m1) and second middle(denoted by m2) that can be calculated as shown below. Here, l and r denotes the left and right boundaries of the range respectively . Initially, l and r equals to 0 and n-1 respectively, where n is the size of the array. 
![image](https://user-images.githubusercontent.com/62798923/145089272-07f637e6-3642-4fa7-808a-ec992b19c52b.png)

#### Note : Since algorithm is similar to binary search , only difference is no of parts of the array done for searching, so array must be sorted to apply ternary search.
<br>

### Algorithm : 
#### 1. First, we compare our value with the value at mid1 and mid2. If either of them are equal , we return that index.
#### 2. If 1 doesn't holds , then we will check whether our value is smaller than value at mid1, if so, we recur for first part.
#### 3. If 2 doesn't holds, then we will check whether our value is greater than value at mid2, if so, we recur for third part.
#### 4. Else we recur for second (middle) part.
![image](https://user-images.githubusercontent.com/62798923/145089421-0af61e37-c3f9-4cc2-8a41-ab827585ad1a.png)


<br>

### Code :
```
#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int nums[], int l, int r, int value) {
   if(l <= r) {
      int m1 = (l + (r - l) /3); // endpoint of first block;
      int m2 = (r - (r - l) /3); // endpoint of second block;
      if(nums[m1] == value)//Checking value equal to value at first middle or not
         return m1;
      if(nums[m2] == value)//Checking value equal to value at second middle or not
         return m2;
      if(value < nums[m1])
         return ternarySearch(nums, l, m1-1, value);//recur for first part
      if(value > nums[m2])
         return ternarySearch(nums, m2+1, r, value);//recur for third part
	 
      return ternarySearch(nums, m1+1, m2-1, value);//recur for second part
   }
   return -1;
}

int main() {
   int n,value;
   cin >> n;
   int nums[n]; //array of size n , that is to be searched
   
   for(int j = 0; j< n; j++) {
      cin >> nums[j];
   }

   cin>>value;// value to be searched
   int id;//to store index of search value
   id=ternarySearch(arr, 0, n-1, value);
   if(id==-1)
   {
   	cout<<"Value not found"<<"\n";
   }
   else cout<<"Value found at index"<<" "<<id<<"\n";
}
```
### Input :
```
10
12 25 48 52 67 79 88 93 100 115
67
```
### Output :
```
Value found at index 4.
```

### Time Complexity :
![image](https://user-images.githubusercontent.com/62798923/145244037-c3703565-baa5-4dc0-9c6f-7b770490e96c.png)
#### Explanation :  In each iteration , we are rejecting the two-third of the range, only searching the one- third part. So recurrence is T(n) = T(n/3) + c , where n is the size of the array and c is constant. Solving the reccurence, we get required time complexity.

### Space Complexity : O(1)
#### Explanation : Since we are using constant space only.

<br>

### Practice Problems
#### 1. https://www.codechef.com/problems/AMCS03
#### 2. https://www.spoj.com/problems/KOPC12A/
#### 3. https://codeforces.com/problemset/problem/578/C

<br>
