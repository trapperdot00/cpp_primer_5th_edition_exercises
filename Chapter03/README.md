# Chapter03: Strings, Vectors, and Arrays
## [Exercise 3.1](Chapter03/3.01)
Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appro-
priate using declarations.
## [Exercise 3.2](Chapter03/3.02)
Write a program to read the standard input a line at a time. Modify your
program to read a word at a time.
## [Exercise 3.3](Chapter03/3.03.txt)
Explain how whitespace characters are handled in the string input op-
erator and in the getline function.
## [Exercise 3.4](Chapter03/3.04)
Write a program to read two strings and report whether the strings
are equal. If not, report which of the two is larger. Now, change the program to report
whether the strings have the same length, and if not, report which is longer.
## [Exercise 3.5](Chapter03/3.05)
Write a program to read strings from the standard input, concatenat-
ing what is read into one large string. Print the concatenated string. Next, change
the program to separate adjacent input strings by a space.
## [Exercise 3.6](Chapter03/3.06.cpp)
Use a range for to change all the characters in a string to X.
## [Exercise 3.7](Chapter03/3.07.cpp)
What would happen if you define the loop control variable in the previ-
ous exercise as type char? Predict the results and then change your program to use a
char to see if you were right.
## [Exercise 3.8](Chapter03/3.08)
Rewrite the program in the first exercise, first using a while and again
using a traditional for loop. Which of the three approaches do you prefer and why?
## [Exercise 3.9](Chapter03/3.09.txt)
What does the following program do? Is it valid? If not, why not?
```
string s;
cout << s[0] << endl;
```
## [Exercise 3.10](Chapter03/3.10.cpp)
Write a program that reads a string of characters including punctuation
and writes what was read but with the punctuation removed.
## [Exercise 3.11](Chapter03/3.11)
Is the following range for legal? If so, what is the type of c?
```
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```
## [Exercise 3.12](Chapter03/3.12.txt)
Which, if any, of the following vector definitions are in error? For
those that are legal, explain what the definition does. For those that are not legal,
explain why they are illegal.
```
(a) vector<vector<int>> ivec;
(b) vector<string> svec = ivec;
(c) vector<string> svec(10, "null");
```
## [Exercise 3.13](Chapter03/3.13.txt)
How many elements are there in each of the following vectors? What
are the values of the elements?
```
(a) vector<int> v1;
(b) vector<int> v2(10);
(c) vector<int> v3(10, 42);
(d) vector<int> v4{10};
(e) vector<int> v5{10, 42};
(f) vector<string> v6{10};
(g) vector<string> v7{10, "hi"};
```
## [Exercise 3.14](Chapter03/3.14.cpp)
Write a program to read a sequence of ints from cin and store those
values in a vector.
## [Exercise 3.15](Chapter03/3.15.cpp)
Repeat the previous program but read strings this time.
## [Exercise 3.16](Chapter03/3.16.cpp)
Write a program to print the size and contents of the vectors from
exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy
§ 3.3.1 (p. 97) until you understand why you were wrong.
## [Exercise 3.17](Chapter03/3.17.cpp)
Read a sequence of words from cin and store the values a vector. Af-
ter you’ve read all the words, process the vector and change each word to uppercase.
Print the transformed elements, eight words to a line.
## [Exercise 3.18](Chapter03/3.18.txt)
Is the following program legal? If not, how might you fix it?
```
vector<int> ivec;
ivec[0] = 42;
```
## [Exercise 3.19](Chapter03/3.19.cpp)
List three ways to define a vector and give it ten elements, each with
the value 42. Indicate whether there is a preferred way to do so and why.
## [Exercise 3.20](Chapter03/3.20)
Read a set of integers into a vector. Print the sum of each pair of
adjacent elements. Change your program so that it prints the sum of the first and last
elements, followed by the sum of the second and second-to-last, and so on.
## [Exercise 3.21](Chapter03/3.21.cpp)
Redo the first exercise from § 3.3.3 (p. 105) using iterators.
## [Exercise 3.22](Chapter03/3.22.cpp)
Revise the loop that printed the first paragraph in text to instead
change the elements in text that correspond to the first paragraph to all uppercase.
After you’ve updated text, print its contents.
## [Exercise 3.23](Chapter03/3.23.cpp)
Write a program to create a vector with ten int elements. Using an
iterator, assign each element a value that is twice its current value. Test your program
by printing the vector.
## [Exercise 3.24](Chapter03/3.24.cpp)
Redo the last exercise from § 3.3.3 (p. 105) using iterators.
## [Exercise 3.25](Chapter03/3.25.cpp)
Rewrite the grade clustering program from § 3.3.3 (p. 104) using itera-
tors instead of subscripts.
## [Exercise 3.26](Chapter03/3.26.txt)
In the binary search program on page 112, why did we write mid = beg
+ (end - beg) / 2; instead of mid = (beg + end) /2;?
## [Exercise 3.27](Chapter03/3.27.txt)
Assuming txt_size is a function that takes no arguments and returns
an int value, which of the following definitions are illegal? Explain why.
```
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
```
## [Exercise 3.28](Chapter03/3.28.txt)
What are the values in the following arrays?
```
string sa[10];
int ia[10];
int main() {
  string sa2[10];
  int ia2[10];
}
```
## [Exercise 3.29](Chapter03/3.29.txt)
List some of the drawbacks of using an array instead of a vector.
## [Exercise 3.30](Chapter03/3.30.txt)
Identify the indexing errors in the following code:
```
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
  ia[ix] = ix;
```
## [Exercise 3.31](Chapter03/3.31.cpp)
Write a program to define an array of ten ints. Give each element the
same value as its position in the array.
## [Exercise 3.32](Chapter03/3.32)
Copy the array you defined in the previous exercise into another array.
Rewrite your program to use vectors.
## [Exercise 3.33](Chapter03/3.33.txt)
What would happen if we did not initialize the scores array in the
program on page 116?
## [Exercise 3.34](Chapter03/3.34)
Given that p1 and p2 point to elements in the same array, what does
the following code do? Are there values of p1 or p2 that make this code illegal?
```
p1 += p2 - p1;
```
## [Exercise 3.35](Chapter03/3.35.cpp)
Using pointers, write a program to set the elements in an array to zero.
## [Exercise 3.36](Chapter03/3.36)
Write a program to compare two arrays for equality. Write a similar
program to compare two vectors.
## [Exercise 3.37](Chapter03/3.37)
What does the following program do?
```
const char ca[] = {’h’, ’e’, ’l’, ’l’, ’o’};
const char *cp = ca;
while (*cp) {
  cout << *cp << endl;
  ++cp;
}
```
## [Exercise 3.38](Chapter03/3.38.txt)
In this section, we noted that it was not only illegal but meaningless to
try to add two pointers. Why would adding two pointers be meaningless?
## [Exercise 3.39](Chapter03/3.39)
Write a program to compare two strings. Now write a program to
compare the values of two C-style character strings.
## [Exercise 3.40](Chapter03/3.40.cpp)
Write a program to define two character arrays initialized from string
literals. Now define a third character array to hold the concatenation of the two arrays.
Use strcpy and strcat to copy the two arrays into the third.
## [Exercise 3.41](Chapter03/3.41.cpp)
Write a program to initialize a vector from an array of ints.
## [Exercise 3.42](Chapter03/3.42.cpp)
Write a program to copy a vector of ints into an array of ints.
## [Exercise 3.43](Chapter03/3.43)
Write three different versions of a program to print the elements of ia.
One version should use a range for to manage the iteration, the other two should use
an ordinary for loop in one case using subscripts and in the other using pointers. In
all three programs write all the types directly. That is, do not use a type alias, auto, or
decltype to simplify the code.
## [Exercise 3.44](Chapter03/3.44)
Rewrite the programs from the previous exercises using a type alias for
the type of the loop control variables.
## [Exercise 3.45](Chapter03/3.45)
Rewrite the programs again, this time using auto.
