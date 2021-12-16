### Topic name - Strings
 
### Sub-topic - Manacher's Algorithm

<br>

### Definition
#### Manacher's Algorithm is used to find the longest palindromic substring in linear time (i.e. in O(n)).


<br>

### Explanation (along with examples)
#### So by defination, we get to know that the purpose of the Manacher's Algorithm is to find the longest palindromic substring. We will do that by taking some of characters as the center one by one. But wait, a palindrome can be of even length too! The center of the even length palindrome is not any character but is the middle of two characters. This means we need to check the middle of two charaters too. So let's insert character 'X' in the middle of two character and at the ends too, so that the new string is of length 2*n+1 (where n is length of original string).
#### We need to check some conditions to check whether a character can be a center of not:
1. If a palindrome of mirror (of our current character) around the center is a prefix of the current palindrome, then this character is our next center.
2. If the palindrome of mirror expands beyond the left end of the current palindrome, then it will not be our next center. 
3. If the palindrome of mirror is completely contained inside our current palindrome, then it will not be our next center. 
4. If we can't find the next center in the current palindrome, then the character next to the current palindrome is our next center.
5. If the current substring expands till the end of the string, then we can stop our search. As there can't be any palindromic substring of longer length that we currently had in our analysis.

#### Let's solve a simple problem based on it.
#### We will check our longest palidromic substring in "abaaba"
After adding 'X' to the string, the new string will become:
XaXbXaXaXbXaX
We can store longest palindromic substring in array named P.
(Remember that the characters of string which are bold is the part of current palindromic substring.)
Let's start by taking the first center as index 0. 


|**Index**|0|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**String**|**X**|a|X|b|X|a|X|a|X|b|X|a|X|
|**P**|1| | | | | | | | | | | | |

Now our next center will be index 1 (4th point).


|**Index**|0|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**String**|**X**|**a**|**X**|b|X|a|X|a|X|b|X|a|X|
|**P**|1|3| | | | | | | | | | | |

Now our next center will be index 2 (1st point).


|**Index**|0|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**String**|X|a|**X**|b|X|a|X|a|X|b|X|a|X|
|**P**|1|3|1| | | | | | | | | | |

Now our next center will be index 3 (4th point).


|**Index**|0|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**String**|**X**|**a**|**X**|**b**|**X**|**a**|**X**|a|X|b|X|a|X|
|**P**|1|3|1|7| | | | | | | | | |

Now our next center will be index 5 (1st point). Index 4 can't be our center (3rd point).


|**Index**|0|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**String**|X|a|X|b|**X**|**a**|**X**|a|X|b|X|a|X|
|**P**|1|3|1|7|1|3| | | | | | | |

Now our next center will be index 6 (1st point).


|**Index**|0|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**String**|**X**|**a**|**X**|**b**|**X**|**a**|**X**|**a**|**X**|**b**|**X**|**a**|**X**|
|**P**|1|3|1|7|1|3|13| | | | | | |

So now our current palindromic substring expands till the end of the string. So we can now exit this process (5th point).
Finally the P array will be:


|**Index**|0|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**String**|**X**|**a**|**X**|**b**|**X**|**a**|**X**|**a**|**X**|**b**|**X**|**a**|**X**|
|**P**|1|3|1|7|1|3|13|3|1|7|1|3|1|

So now to get our longest palindromic substring, we should remove 'X' from the string and length of longest palindromic substring is maximum value in array P and then subtract it by 1 and divide the resultant by 2 (i.e. (max(p)-1)/2).


<br>

### Practice Problem
#### [Longest Palindromic Substring] (https://leetcode.com/problems/longest-palindromic-substring)

<br>