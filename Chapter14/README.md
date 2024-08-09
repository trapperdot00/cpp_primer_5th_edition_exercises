# Chapter14: Overloaded Operations and Conversions
## [Exercise 14.1](14.01.txt)
In what ways does an overloaded operator differ from a built-in opera-
tor? In what ways are overloaded operators the same as the built-in operators?
## [Exercise 14.2](14.02)
Write declarations for the overloaded input, output, addition, and
compound-assignment operators for Sales_data.
## [Exercise 14.3](14.03.txt)
Both string and vector define an overloaded == that can be used to
compare objects of those types. Assuming svec1 and svec2 are vectors that hold
strings, identify which version of == is applied in each of the following expressions:
```
(a) "cobble" == "stone"
(b) svec1[0] == svec2[0]
(c) svec1 == svec2
(d) "svec1[0] == "stone"
```
## [Exercise 14.4](14.04.txt)
Explain how to decide whether the following should be class members:
```
(a) %
(b) %=
(c) ++
(d) ->
(e) <<
(f) &&
(g) ==
(h) ()
```
## [Exercise 14.5](14.05)
In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the
following classes. Decide what, if any, overloaded operators your class should provide.
```
(a) Book
(b) Date
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
```
## [Exercise 14.6](14.06)
Define an output operator for your Sales_data class.
## [Exercise 14.7](14.07)
Define an output operator for you String class you wrote for the ex-
ercises in § 13.5 (p. 531).
## [Exercise 14.8](14.08)
Define an output operator for the class you chose in exercise 7.40 from
§ 7.5.1 (p. 291).
## [Exercise 14.9](14.09)
Define an input operator for your Sales_data class.
## [Exercise 14.10](14.10.txt)
Describe the behavior of the Sales_data input operator if given the
following input:
```
(a) 0-201-99999-9 10 24.95
(b) 10 24.95 0-210-99999-9
```
## [Exercise 14.11](14.11.txt)
What, if anything, is wrong with the following Sales_data input op-
erator? What would happen if we gave this operator the data in the previous exercise?
```
istream& operator>>(istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```
## [Exercise 14.12](14.12)
Define an input operator for the class you used in exercise 7.40 from
§ 7.5.1 (p. 291). Be sure the operator handles input errors.
## [Exercise 14.13](14.13)
Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? Define any you think the class should include.
## [Exercise 14.14](14.14.txt)
Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?
## [Exercise 14.15](14.15)
Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not. 
## [Exercise 14.16](14.16)
Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531) classes.
## [Exercise 14.17](14.17)
Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the equality operators? If so, implement them. If not, explain why not.
## [Exercise 14.18](14.18)
Define relational operators for your StrBlob, StrBlobPtr, StrVec, and String classes.
## [Exercise 14.19](14.19.txt)
Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the relational operators? If so, implement them. If not, explain why not.
## [Exercise 14.20](14.20)
Define the addition and compound-assignment operators for your Sales_data class.
## [Exercise 14.21](14.21)
Write the Sales_data operators so that + does the actual addition and += calls +. Discuss the disadvantages of this approach compared to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p. 564).
## [Exercise 14.22](14.22)
Define a version of the assignment operator that can assign a string representing an ISBN to a Sales_data.
## [Exercise 14.23](14.23)
Define an initializer_list assignment operator for your version of the StrVec class.
## [Exercise 14.24](14.24)
Decide whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.
## [Exercise 14.25](14.25)
Implement any other assignment operators your class should define. Explain which types should be used as operands and why.
## [Exercise 14.26](14.26)
Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.
## [Exercise 14.27](14.27)
Add increment and decrement operators to your StrBlobPtr class.
## [Exercise 14.28](14.28)
Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic (§ 3.5.3, p. 119).
## [Exercise 14.29](14.29.txt)
We did not define a const version of the increment and decrement operators. Why not?
## [Exercise 14.30](14.30)
Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must return const references because the data member in constStrBlobPtr points to a const vector.
## [Exercise 14.31](14.31.txt)
Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?
## [Exercise 14.32](14.32)
Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that class.
## [Exercise 14.33](14.33.txt)
How many operands may an overloaded function-call operator take?
## [Exercise 14.34](14.34)
Define a function-object class to perform an if-then-else operation: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.
## [Exercise 14.35](14.35)
Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read. If the read fails, return the empty string.
## [Exercise 14.36](14.36)
Use the class from the previous exercise to read the standard input, storing each line as an element in a vector.
## [Exercise 14.37](14.37)
Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.
## [Exercise 14.38](14.38)
Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.
## [Exercise 14.39](14.39)
Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.
## [Exercise 14.40](14.40)
Rewrite the biggies function from § 10.3.2 (p. 391) to use function-object classes in place of lambdas.
## [Exercise 14.41](14.41.txt)
Why do you suppose the new standard added lambdas? Explain when you would use a lambda and when you would write a class instead.
## [Exercise 14.42](14.42)
Using library function objects and adaptors, deﬁne an expression to
```
(a) Count the number of values that are greater than 1024
(b) Find the ﬁrst string that is not equal to pooh
(c) Multiply all values by 2
```
## [Exercise 14.43](14.43.cpp)
Using library function objects, determine whether a given int value is divisible by any element in a container of ints.
## [Exercise 14.44](14.44.cpp)
Write your own version of a simple desk calculator that can handle binary operations.
## [Exercise 14.45](14.45)
Write conversion operators to convert a Sales_data to string and to double. What values do you think these operators should return?
## [Exercise 14.46](14.46.txt)
Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.
## [Exercise 14.47](14.47.txt)
Explain the difference between these two conversion operators:
```
struct Integral {
    operator const int();
    operator int() const;
};
```
## [Exercise 14.48](14.48.txt)
Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) should have a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.
## [Exercise 14.49](14.49)
Regardless of whether it is a good idea to do so, define a conversion to bool for the class from the previous exercise.
## [Exercise 14.50](14.50.txt)
Show the possible class-type conversion sequences for the initializations of ex1 and ex2. Explain whether the initializations are legal or not.
```
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;
float ex2 = ldObj;
```
## [Exercise 14.51](14.51.txt)
Show the conversion sequences (if any) needed to call each version of calc and explain why the best viable function is selected.
```
void calc(int);
void calc(LongDouble);
double dval;
calc(dval); // which calc?
```
## [Exercise 14.52](14.52.txt)
Which operator+, if any, is selected for each of the addition expressions? List the candidate functions, the viable functions, and the type conversions onthe arguments for each viable function:
```
struct LongDouble {
    // member operator+ for illustration purposes; + is usually a nonmember
    LongDouble operator+(const SmallInt&);
    // other members as in § 14.9.2 (p. 587)
};
LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```
## [Exercise 14.53](14.53.txt)
Given the definition of SmallInt on page 588, determine whether the following addition expression is legal. If so, what addition operator is used? If not, how might you change the code to make it legal?
```
SmallInt s1;
double d = s1 + 3.14;
```
