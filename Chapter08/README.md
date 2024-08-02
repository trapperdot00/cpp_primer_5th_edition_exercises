# Chapter08: The IO Library
## [Exercise 8.1](Chapter08/8.01.cpp)
Write a function that takes and returns an istream&. The function
should read the stream until it hits end-of-file. The function should print what it reads
to the standard output. Reset the stream so that it is valid before returning the stream.
## [Exercise 8.2](Chapter08/8.02.cpp)
Test your function by calling it, passing cin as an argument.
## [Exercise 8.3](Chapter08/8.03.txt)
What causes the following while to terminate?
```
while (cin >> i) /* ... */
```
## [Exercise 8.4](Chapter08/8.04.cpp)
Write a function to open a file for input and read its contents into a
vector of strings, storing each line as a separate element in the vector.
## [Exercise 8.5](Chapter08/8.05.cpp)
Rewrite the previous program to store each word in a separate element.
## [Exercise 8.6](Chapter08/8.06.cpp)
Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transac-
tions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).
## [Exercise 8.7](Chapter08/8.07.cpp)
Revise the bookstore program from the previous section to write its out-
put to a file. Pass the name of that file as a second argument to main.
## [Exercise 8.8](Chapter08/8.08.cpp)
Revise the program from the previous exercise to append its output to
its given file. Run the program on the same output file at least twice to ensure that the
data are preserved.
## [Exercise 8.9](Chapter08/8.09.cpp)
Use the function you wrote for the first exercise in § 8.1.2 (p. 314) to print
the contents of an istringstream object.
## [Exercise 8.10](Chapter08/8.10.cpp)
Write a program to store each line from a file in a vector<string>.
Now use an istringstream to read each element from the vector a word at a time.
## [Exercise 8.11](Chapter08/8.11.cpp)
The program in this section defined its istringstream object inside
the outer while loop. What changes would you need to make if record were defined
outside that loop? Rewrite the program, moving the definition of record outside the
while, and see whether you thought of all the changes that are needed.
## [Exercise 8.12](Chapter08/8.12.txt)
Why didn’t we use in-class initializers in PersonInfo?
## [Exercise 8.13](Chapter08/8.13.cpp)
Rewrite the phone number program from this section to read from a
named file rather than from cin.
## [Exercise 8.14](Chapter08/8.14.txt)
Why did we declare entry and nums as const auto &?
