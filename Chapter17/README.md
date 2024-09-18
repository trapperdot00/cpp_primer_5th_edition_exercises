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
