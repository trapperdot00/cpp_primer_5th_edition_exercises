# Chapter05: Statements
## [Exercise 5.1](Chapter05/5.01.txt)
What is a null statement? When might you use a null statement?
## [Exercise 5.2](Chapter05/5.02.txt)
What is a block? When might you might use a block?
## [Exercise 5.3](Chapter05/5.03.cpp)
Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from
§ 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite im-
proves or diminishes the readability of this code.
## [Exercise 5.4](Chapter05/5.04.txt)
Explain each of the following examples, and correct any problems you detect.
```
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
  if (!status) { /* . . . */ }
```
## [Exercise 5.5](Chapter05/5.05.cpp)
Using an if–else statement, write your own version of the program to
generate the letter grade from a numeric grade.
## [Exercise 5.6](Chapter05/5.06.cpp)
Rewrite your grading program to use the conditional operator (§ 4.7,
p. 151) in place of the if–else statement.
## [Exercise 5.7](Chapter05/5.07.txt)
Correct the errors in each of the following code fragments:
```
(a) if (ival1 != ival2)
        ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval)
        minval = ival;
        occurs = 1;
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
(d) if (ival = 0)
        ival = get_value();
```
## [Exercise 5.8](Chapter05/5.08.txt)
What is a “dangling else”? How are else clauses resolved in C++?
## [Exercise 5.9](Chapter05/5.09.cpp)
Write a program using a series of if statements to count the number of
vowels in text read from cin.
## [Exercise 5.10](Chapter05/5.10.cpp)
There is one problem with our vowel-counting program as we’ve im-
plemented it: It doesn’t count capital letters as vowels. Write a program that counts
both lower- and uppercase letters as the appropriate vowel—that is, your program
should count both ’a’ and ’A’ as part of aCnt, and so forth.
## [Exercise 5.11](Chapter05/5.11.cpp)
Modify our vowel-counting program so that it also counts the number
of blank spaces, tabs, and newlines read.
## [Exercise 5.12](Chapter05/5.12.cpp)
Modify our vowel-counting program so that it counts the number of
occurrences of the following two-character sequences: ff, fl, and fi.
## [Exercise 5.13](Chapter05/5.13.txt)
Each of the programs in the highlighted text on page 184 contains a
common programming error. Identify and correct each error.
## [Exercise 5.14](Chapter05/5.14.cpp)
Write a program to read strings from standard input looking for du-
plicated words. The program should find places in the input where one word is fol-
lowed immediately by itself. Keep track of the largest number of times a single repeti-
tion occurs and which word is repeated. Print the maximum number of duplicates, or
else print a message saying that no word was repeated. For example, if the input is
```
how now now now brown cow cow
```
the output should indicate that the word now occurred three times.
## [Exercise 5.15](Chapter05/5.15.txt)
Explain each of the following loops. Correct any problems you detect.
```
(a) for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
    if (ix != sz)
        // . . .
(b) int ix;
    for (ix != sz; ++ix) { /* . . . */ }
(c) for (int ix = 0; ix != sz; ++ix, ++ sz) { /* . . . */ }
```
## [Exercise 5.16](Chapter05/5.16)
The while loop is particularly good at executing while some condition
holds; for example, when we need to read values until end-of-file. The for loop is
generally thought of as a step loop: An index steps through a range of values in a
collection. Write an idiomatic use of each loop and then rewrite each using the other
loop construct. If you could use only one loop, which would you choose? Why?
## [Exercise 5.17](Chapter05/5.17.cpp)
Given two vectors of ints, write a program to determine whether
one vector is a prefix of the other. For vectors of unequal length, compare the num-
ber of elements of the smaller vector. For example, given the vectors containing 0,
1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.
## [Exercise 5.18](Chapter05/5.18.txt)
Explain each of the following loops. Correct any problems you detect.
```
(a) do
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
(b) do {
        // . . .
    } while (int ival = get_response());
(c) do {
        int ival = get_response();
    } while (ival);
```
## [Exercise 5.19](Chapter05/5.19.cpp)
Write a program that uses a do while loop to repetitively request two
strings from the user and report which string is less than the other.
## [Exercise 5.20](Chapter05/5.20.cpp)
Write a program to read a sequence of strings from the standard input
until either the same word occurs twice in succession or all the words have been read.
Use a while loop to read the text one word at a time. Use the break statement to
terminate the loop if a word occurs twice in succession. Print the word if it occurs
twice in succession, or else print a message saying that no word was repeated.
## [Exercise 5.21](Chapter05/5.21)
Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks
only for duplicated words that start with an uppercase letter.
## [Exercise 5.22](Chapter05/5.22.cpp)
The last example in this section that jumped back to begin could be
better written using a loop. Rewrite the code to eliminate the goto.
## [Exercise 5.23](Chapter05/5.23.cpp)
Write a program that reads two integers from the standard input and
prints the result of dividing the first number by the second.
## [Exercise 5.24](Chapter05/5.24.cpp)
Revise your program to throw an exception if the second number is
zero. Test your program with a zero input to see what happens on your system if you
don’t catch an exception.
## [Exercise 5.25](Chapter05/5.25.cpp)
Revise your program from the previous exercise to use a try block to
catch the exception. The catch clause should print a message to the user and ask
them to supply a new number and repeat the code inside the try.
