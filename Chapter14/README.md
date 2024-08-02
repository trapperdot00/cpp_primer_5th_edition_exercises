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
