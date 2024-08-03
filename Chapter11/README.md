# Chapter11
## [Exercise 11.1](11.01.txt)
Describe the differences between a map and a vector.
## [Exercise 11.2](11.02.txt)
Give an example of when each of list, vector, deque, map, and set
might be most useful.
## [Exercise 11.3](11.03.cpp)
Write your own version of the word-counting program
## [Exercise 11.4](11.04)
Extend your program to ignore case and punctuation. For example,
“example.” “example,” and “Example” should all increment the same counter.
## [Exercise 11.5](11.05.txt)
Explain the difference between a map and a set. When might you use
one or the other?
## [Exercise 11.6](11.06.txt)
Explain the difference between a set and a list. When might you use
one or the other?
## [Exercise 11.7](11.07.cpp)
Define a map for which the key is the family’s last name and the value
is a vector of the children’s names. Write code to add new families and to add new
children to an existing family.
## [Exercise 11.8](11.08.cpp)
Write a program that stores the excluded words in a vector instead of
in a set. What are the advantages to using a set?
## [Exercise 11.9](11.09.cpp)
Define a map that associates words with a list of line numbers on
which the word might occur.
## [Exercise 11.10](11.10.txt)
Could we define a map from vector<int>::iterator to int?
What about from list<int>::iterator to int? In each case, if not, why not?
## [Exercise 11.11](11.11)
Redefine bookstore without using decltype.
## [Exercise 11.12](11.12.cpp)
Write a program to read a sequence of strings and ints, storing each
into a pair. Store the pairs in a vector.
## [Exercise 11.13](11.13)
There are at least three ways to create the pairs in the program for
the previous exercise. Write three versions of that program, creating the pairs in each
way. Explain which form you think is easiest to write and understand, and why.
## [Exercise 11.14](11.14.cpp)
Extend the map of children to their family name that you wrote for the
exercises in § 11.2.1 (p. 424) by having the vector store a pair that holds a child’s
name and birthday.
## [Exercise 11.15](11.15.txt)
What are the mapped_type, key_type, and value_type of a map
from int to vector<int>?
## [Exercise 11.16](11.16.cpp)
Using a map iterator write an expression that assigns a value to an
element.
## [Exercise 11.17](11.17.txt)
Assuming c is a multiset of strings and v is a vector of
strings, explain the following calls. Indicate whether each call is legal:
```
copy(v.begin(), v.end(), inserter(c, c.end()));
copy(v.begin(), v.end(), back_inserter(c));
copy(c.begin(), c.end(), inserter(v, v.end()));
copy(c.begin(), c.end(), back_inserter(v));
```
## [Exercise 11.18](11.18.cpp)
Write the type of map_it from the loop on page 430 without using
auto or decltype.
## [Exercise 11.19](11.19)
Define a variable that you initialize by calling begin() on the
multiset named bookstore from § 11.2.2 (p. 425). Write the variable’s type without
using auto or decltype.
## [Exercise 11.20](11.20.cpp)
Rewrite the word-counting program from § 11.1 (p. 421) to use
insert instead of subscripting. Which program do you think is easier to write and
read? Explain your reasoning.
## [Exercise 11.21](11.21.txt)
Assuming word_count is a map from string to size_t and word
is a string, explain the following loop:
```
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```
## [Exercise 11.22](11.22.txt)
Given a map<string, vector<int>>, write the types used as an
argument and as the return value for the version of insert that inserts one element.
## [Exercise 11.23](11.23.cpp)
Rewrite the map that stored vectors of children’s names with a key
that is the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap.
## [Exercise 11.24](11.24.txt)
What does the following program do?
```
map<int, int> m;
m[0] = 1;
```
## [Exercise 11.25](11.25.txt)
Contrast the following program with the one in the previous exercise
```
vector<int> v;
v[0] = 1;
```
## [Exercise 11.26](11.26.txt)
What type can be used to subscript a map? What type does the sub-
script operator return? Give a concrete example—that is, define a map and then write
the types that can be used to subscript the map and the type that would be returned
from the subscript operator.
## [Exercise 11.27](11.27.txt)
What kinds of problems would you use count to solve? When might
you use find instead?
## [Exercise 11.28](11.28.cpp)
Define and initialize a variable to hold the result of calling find on a
map from string to vector of int.
## [Exercise 11.29](11.29.txt)
What do upper_bound, lower_bound, and equal_range return
when you pass them a key that is not in the container?
## [Exercise 11.30](11.30.txt)
Explain the meaning of the operand pos.first->second used in
the output expression of the final program in this section.
## [Exercise 11.31](11.31.cpp)
Write a program that defines a multimap of authors and their works.
Use find to find an element in the multimap and erase that element. Be sure your
program works correctly if the element you look for is not in the map.
## [Exercise 11.32](11.32.cpp)
Using the multimap from the previous exercise, write a program to
print the list of authors and their works alphabetically.
## [Exercise 11.33](11.33)
Implement your own version of the word-transformation program.
## [Exercise 11.34](11.34.txt)
What would happen if we used the subscript operator instead of find
in the transform function?
## [Exercise 11.35](11.35.txt)
In buildMap, what effect, if any, would there be from rewriting
```
trans_map[key] = value.substr(1);
```
as
```
trans_map.insert({key, value.substr(1)})
```
?
## [Exercise 11.36](11.36.txt)
Our program does no checking on the validity of either input file. In
particular, it assumes that the rules in the transformation file are all sensible. What
would happen if a line in that file has a key, one space, and then the end of the line?
Predict the behavior and then check it against your version of the program.
## [Exercise 11.37](11.37.txt)
What are the advantages of an unordered container as compared to the
ordered version of that container? What are the advantages of the ordered version?
## [Exercise 11.38](11.38)
Rewrite the word-counting (§ 11.1, p. 421) and word-transformation
(§ 11.3.6, p. 440) programs to use an unordered_map.
