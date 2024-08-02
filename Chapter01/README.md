# Chapter01: Getting Started
## [Exercise 1.1](Chapter01/1.01.cpp)
Review the documentation for your compiler and determine what file
naming convention it uses. Compile and run the main program from page 2.
## [Exercise 1.2](Chapter01/1.02.cpp)
Change the program to return -1. A return value of -1 is often treated
as an indicator that the program failed. Recompile and rerun your program to see how
your system treats a failure indicator from main.
## [Exercise 1.3](Chapter01/1.03.cpp)
Write a program to print Hello, World on the standard output.
## [Exercise 1.4](Chapter01/1.04.cpp)
Our program used the addition operator, +, to add two numbers. Write
a program that uses the multiplication operator, *, to print the product instead.
## [Exercise 1.5](Chapter01/1.05.cpp)
We wrote the output in one large statement. Rewrite the program to use
a separate statement to print each operand.
## [Exercise 1.6](Chapter01/1.06.txt)
Explain whether the following program fragment is legal.
```
std::cout << "The sum of " << v1;
<< " and " << v2;
<< " is " << v1 + v2 << std::endl;
```
If the program is legal, what does it do? If the program is not legal, why not? How
would you fix it?
## [Exercise 1.7](Chapter01/1.07.cpp)
Compile a program that has incorrectly nested comments.
## [Exercise 1.8](Chapter01/1.08.txt)
Indicate which, if any, of the following output statements are legal:
```
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
After you’ve predicted what will happen, test your answers by compiling a program
with each of these statements. Correct any errors you encounter.
## [Exercise 1.9](Chapter01/1.09.cpp)
Write a program that uses a while to sum the numbers from 50 to 100.
## [Exercise 1.10](Chapter01/1.10.cpp)
In addition to the ++ operator that adds 1 to its operand, there is a
decrement operator (--) that subtracts 1. Use the decrement operator to write a while
that prints the numbers from ten down to zero.
## [Exercise 1.11](Chapter01/1.11.cpp)
Write a program that prompts the user for two integers. Print each
number in the range specified by those two integers.
## [Exercise 1.12](Chapter01/1.12.cpp)
What does the following for loop do? What is the final value of sum?
```
int sum = 0;
for (int i = -100; i <= 100; ++i)
sum += i;
```
## [Exercise 1.13](Chapter01/1.13.cpp)
Rewrite the first two exercises from § 1.4.1 (p. 13) using for loops.
## [Exercise 1.14](Chapter01/1.14.txt)
Compare and contrast the loops that used a for with those using a
while. Are there advantages or disadvantages to using either form?
## [Exercise 1.15](Chapter01/1.15.cpp)
Write programs that contain the common errors discussed in the box
on page 16. Familiarize yourself with the messages the compiler generates.
## [Exercise 1.16](Chapter01/1.16.cpp)
Write your own version of a program that prints the sum of a set of
integers read from cin.
## [Exercise 1.17](Chapter01/1.17.txt)
What happens in the program presented in this section if the input val-
ues are all equal? What if there are no duplicated values?
## [Exercise 1.18](Chapter01/1.18.txt)
Compile and run the program from this section giving it only equal
values as input. Run it again giving it values in which no number is repeated.
## [Exercise 1.19](Chapter01/1.19.cpp)
Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that
printed a range of numbers so that it handles input in which the first number is smaller
than the second.
## [Exercise 1.20](Chapter01/1.20.cpp)
http://www.informit.com/title/0321714113 contains a copy
of Sales_item.h in the Chapter 1 code directory. Copy that file to your working
directory. Use it to write a program that reads a set of book sales transactions, writing
each transaction to the standard output.
## [Exercise 1.21](Chapter01/1.21.cpp)
Write a program that reads two Sales_item objects that have the
same ISBN and produces their sum.
## [Exercise 1.22](Chapter01/1.22.cpp)
Write a program that reads several transactions for the same ISBN.
Write the sum of all the transactions that were read.
## [Exercise 1.23](Chapter01/1.23.cpp)
Write a program that reads several transactions and counts how many
transactions occur for each ISBN .
## [Exercise 1.24](Chapter01/1.24.txt)
Test the previous program by giving multiple transactions representing
multiple ISBNs. The records for each ISBN should be grouped together.
## [Exercise 1.25](Chapter01/1.25.cpp)
Using the Sales_item.h header from the Web site, compile and exe-
cute the bookstore program presented in this section.
