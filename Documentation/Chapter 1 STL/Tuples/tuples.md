# TUPLES - STL

Tuple is a data structure which stores multiple objects together. Multiple means it can store one element or 2 or 3 or 4 or .....
<br>
It can contain elements of different data types.
<br>
Library need to be included for tuple is <br>
```#include<tuple>```
<br>
or we can do <br>
```#include<bits/stdc++.h>```
<br>
Because bits/stdc++ header file contains tuple header file.
It is recommended to include bits/stdc++ because it contains almost all header files and no need to include each header file separately .

There are some non-member functions in tuple
<br>
1.make_tuple<br>
2.get<br>
3.swap<br>
4.tuple_cat<br>
5.tie<br>
6.forward_as_tuple<br>

Lets see each of them one by one what they means and how they will be useful for us.<br>

## make_tuple
It is used to create tuple.<br>
Syntax :
```
tuple<int,int,int> T;
tuple<int,char,float> T1;
T=make_tuple(1,2,3);
T1=make_tuple(1,'a',0.2365);
```

## get
It is used to access elements in tuple<br>
Syntax:
`get<i>(T) means get ith index element of tuple T`
<br>
Example:
```
tuple<int,int,int,string> T;
T=make_tuple(1,2,3,"Hi");
int first_element=get<0>(T);
int second_element=get<1>(T);
int third_element=get<2>(T);
string fourth_element=get<3>(T);
```

**IMPORTANT :** 
If you want to change ith index element in tuple then we can use this get function to do so.
Example:
```
tuple<int,int> T=make_tuple(1,2);
get<1>(T)=200;
cout<<get<1>(T)<<endl;
```

## Swap
It is used to swap two tuples.<br>
Syntax:
`T1.swap(T2);`
<br>
Example :
```
tuple<int,int> T1,T2;
T1=make_tuple(1,2);
T2=make_tuple(100,200);
T1.swap(T2);
```
For swapping two tuples we can use this for funtion or we can use swap function which is there STL.<br>
Example :
```
tuple<int,int> T1,T2;
T1=make_tuple(1,2);
T2=make_tuple(100,200);
swap(T1,T2);
```
**NOTE :**
We can swap two tuples if and only if they are of same type. Let’s see an example. This below code will throw an error because tuple T1 is <int,int> where as tuple T2 is <float,float>
Example :
```
tuple<int,int> T1;
tuple<float,float> T2;
T1=make_tuple(1,2);
T2=make_tuple(100.25,200.42);
T1.swap(T2);
swap(T1,T2);
/*Both the above statments gives error*/
```

## tuple_cat
This function is used to concatenate two or more tuples and returns a new tuple.
Example:
```
tuple<int,int,int,float> T=make_tuple(1,2,3,4.5);
tuple<int,char,int,int> T1=make_tuple(1,'$',3,4);
tuple<string,int> T2=make_tuple("HI",20);
auto T3=tuple_cat(T,T1,T2);
cout<<get<0>(T3)<<endl;
cout<<get<1>(T3)<<endl;
cout<<get<2>(T3)<<endl;
cout<<get<3>(T3)<<endl;
cout<<get<4>(T3)<<endl;
cout<<get<5>(T3)<<endl;
cout<<get<6>(T3)<<endl;
cout<<get<7>(T3)<<endl;
cout<<get<8>(T3)<<endl;
cout<<get<9>(T3)<<endl;
```
The reason for mentoining auto is for tuple T3 it would be really difficult for us to write it's tuple object 
`tuple<int,int,int,float,int,char,int,int,string,int>`

Suppose if we want to combine 10 tuples then it will be really messy if we want to write all those data types of those 10 tuples. So auto is recommended here because it calculates it self.

The returned tuple will have all the elements that are present in the tuples which are participated in concatenation

## tie
It is also used to access values but it is more preferable than get when we want to access more elements in tuple. Because if we want to assign variables to each element present in tuple (like in first example shown above) we need to use get operation n times (assuming n is number of elements in tuple) but it requires only one tie operation to do so.
```
int int_variable;
char char_variable;
float float_variable;
string string_variable;
tuple<int,char,float,string> T;
T=make_tuple(1,'z',0.26,"HI");
tie(int_variable,char_variable,float_variable,string_variable)=T;

```
Suppose if we don’t want to access some elements in tuple then instead of writing variable name in tie argument part we can simply write ignore .
```
char char_variable;
float float_variable;
string string_variable;
tuple<int,char,float,string> T;
T=make_tuple(1,'z',0.26,"HI");
tie(ignore,char_variable,float_variable,string_variable)=T;
```

Make sure that datatype of variable matches with your tuple data type for each element in tuple.

## forward_as_tuple

Even though it is not used that much lets have a quick discussion. 
When we want to pass tuple as an argument for this we don’t need to make tuple object and then pass it . Simply we can use this function. Let’s see an example for clear understanding
Example:
```
tuple<int,int> AddTwoTuple(tuple<int,int> T1,tuple<int,int> T2){
    tuple<int,int> ans;
    ans=make_tuple(get<0>(T1)+get<0>(T2),get<1>(T1)+get<1>(T2));
    return ans;
}
int main(){
    tuple<int,int> res=(forward_as_tuple(1,2),tuple(2,3));
}
```

This ends our discussion on useful functions of tuple object

And there is one more important part left about tuple is 
## tuple_size
It is not a function rather it is a class. As the name itself says it returns size of the tuple.

Example:
```
tuple<char,string> T=make_tuple('a',"HI");
int sz=tuple_size<decltype(T)>;
```

decltype depicts the data type of passed element 
