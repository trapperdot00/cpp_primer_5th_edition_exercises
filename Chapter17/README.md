# Chapter17: Specialized Library Facilities
## [Exercise 17.1](17.01.cpp)
Define a tuple that holds three int values and initialize the members to 10, 20, and 30.
## [Exercise 17.2](17.02.cpp)
Define a tuple that holds a string, a vector<string>, and a pair<string, int>.
## [Exercise 17.3](17.03)
Rewrite the TextQuery programs from § 12.3 (p. 484) to use a tuple instead of the QueryResult class. Explain which design you think is better and why.
## [Exercise 17.4](17.04)
Write and test your own version of the findBook function.
## [Exercise 17.5](17.05)
Rewrite findBook to return a pair that holds an index and a pair of iterators.
## [Exercise 17.6](17.06)
Rewrite findBook so that it does not use tuple or pair.
## [Exercise 17.7](17.07.txt)
Explain which version of findBook you prefer and why.
## [Exercise 17.8](17.08.txt)
What would happen if we passed Sales_data() as the third parameter to accumulate in the last code example in this section?
## [Exercise 17.9](17.09.txt)
Explain the bit pattern each of the following bitset objects contains:
```
(a) bitset<64> bitvec(32);
(b) bitset<32> bv(1010101);
(c) string bstr; cin >> bstr; bitset<8>bv(bstr);
```
## [Exercise 17.10](17.10.cpp)
Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a bitset that has a 1 bit in each position corresponding to a number in this sequence. Default initialize another bitset and write a small program to turn on each of the appropriate bits.
## [Exercise 17.11](17.11.cpp)
Define a data structure that contains an integral object to track responses to a true/false quiz containing 10 questions. What changes, if any, would you need to make in your data structure if the quiz had 100 questions?
## [Exercise 17.12](17.12.cpp)
Using the data structure from the previous question, write a function that takes a question number and a value to indicate a true/false answer and updates the quiz results accordingly.
## [Exercise 17.13](17.13.cpp)
Write an integral object that contains the correct answers for the true/false quiz. Use it to generate grades on the quiz for the data structure from the previous two exercises.
## [Exercise 17.14](17.14)
Write several regular expressions designed to trigger various errors. Run your program to see what output your compiler generates for each error.
## [Exercise 17.15](17.15.cpp)
Write a program using the pattern that finds words that violate the “i before e except after c” rule. Have your program prompt the user to supply a word and indicate whether the word is okay or not. Test your program with words that do and do not violate the rule.
## [Exercise 17.16](17.16.cpp)
What would happen if your regex object in the previous program were initialized with "[^c]ei"? Test your program using that pattern to see whether your expectations were correct.
## [Exercise 17.17](17.17)
Update your program so that it finds all the words in an input sequence that violiate the “ei” grammar rule.
## [Exercise 17.18](17.18)
Revise your program to ignore words that contain “ei” but are not misspellings, such as “albeit” and “neighbor.”
## [Exercise 17.19](17.19.txt)
Why is it okay to call m[4].str() without first checking whether m[4] was matched?
## [Exercise 17.20](17.20)
Write your own version of the program to validate phone numbers.
## [Exercise 17.21](17.21)
Rewrite your phone number program from § 8.3.2 (p. 323) to use the valid function defined in this section.
## [Exercise 17.22](17.22)
Rewrite your phone program so that it allows any number of whitespace characters to separate the three parts of a phone number.
## [Exercise 17.23](17.23)
Write a regular expression to find zip codes. A zip code can have five or nine digits. The first five digits can be separated from the remaining four by a dash.
## [Exercise 17.24](17.24)
Write your own version of the program to reformat phone numbers.
## [Exercise 17.25](17.25)
Rewrite your phone program so that it writes only the ﬁrst phone number for each person.
## [Exercise 17.26](17.26)
Rewrite your phone program so that it writes only the second and subsequent phone numbers for people with more than one phone number.
## [Exercise 17.27](17.27)
Write a program that reformats a nine-digit zip code as ddddd-dddd.
## [Exercise 17.28](17.28.cpp)
Write a function that generates and returns a uniformly distributed random unsigned int each time it is called.
## [Exercise 17.29](17.29.cpp)
Allow the user to supply a seed as an optional argument to the function you wrote in the previous exercise.
## [Exercise 17.30](17.30.cpp)
Revise your function again this time to take a minimum and maximum value for the numbers that the function should return.
