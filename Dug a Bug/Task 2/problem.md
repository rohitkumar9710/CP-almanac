### Question
You are given a pair of integers (a,b) and an integer x.
You can change the pair in two different ways:

set (assign) a:=|a−b|;<br>
set (assign) b:=|a−b|,<br>

where |a−b| is the absolute difference between a and b.<br>
The pair (a,b) is called x-magic if x is obtainable either as a or as b using only the given operations (i.e. the pair (a,b) is x-magic if a=x or b=x after some number of operations applied). You can apply the operations any number of times (even zero).<br>

Your task is to find out if the pair (a,b) is x-magic or not.<br>

You have to answer t independent test cases.<br>

### Input
The first line of the input contains one integer t (1≤t≤10<sup>4</sup>) — the number of test cases. The next t lines describe test cases.<br>

The only line of the test case contains three integers a, b and x (1≤a,b,x≤10<sup>18</sup>).<br>

### Output
For the i-th test case, print YES if the corresponding pair (a,b) is x-magic and NO otherwise.

#### Input
8<br>
6 9 3<br>
15 38 7<br>
18 8 8<br>
30 30 30<br>
40 50 90<br>
24 28 20<br>
365 216 52<br>
537037812705867558 338887693834423551 3199921013340<br>

#### Correct Output
YES<br>
YES<br>
YES<br>
YES<br>
NO<br>
YES<br>
YES<br>
YES<br>
