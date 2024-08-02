# Chapter07: Classes
## [Exercise 7.1](7.01.cpp)
Write a version of the transaction-processing program from § 1.6 (p. 24)
using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).
## [Exercise 7.2](7.02)
Add the combine and isbn members to the Sales_data class you
wrote for the exercises in § 2.6.2 (p. 76).
## [Exercise 7.3](7.03)
Revise your transaction-processing program from § 7.1.1 (p. 256) to use
these members.
## [Exercise 7.4](7.04)
Write a class named Person that represents the name and address of
a person. Use a string to hold each of these elements. Subsequent exercises will
incrementally add features to this class.
## [Exercise 7.5](7.05)
Provide operations in your Person class to return the name and ad-
dress. Should these functions be const? Explain your choice.
## [Exercise 7.6](7.06)
Define your own versions of the add, read, and print functions.
## [Exercise 7.7](7.07)
Rewrite the transaction-processing program you wrote for the exercises
in § 7.1.2 (p. 260) to use these new functions.
## [Exercise 7.8](7.08.txt)
Why does read define its Sales_data parameter as a plain reference
and print define its parameter as a reference to const?
## [Exercise 7.9](7.09)
Add operations to read and print Person objects to the code you wrote
for the exercises in § 7.1.2 (p. 260).
## [Exercise 7.10](7.10.txt)
What does the condition in the following if statement do?
```
if (read(read(cin, data1), data2))
```
## [Exercise 7.11](7.11)
Add constructors to your Sales_data class and write a program to
use each of the constructors.
## [Exercise 7.12](7.12)
Move the definition of the Sales_data constructor that takes an
istream into the body of the Sales_data class.
## [Exercise 7.13](7.13)
Rewrite the program from page 255 to use the istream constructor.
## [Exercise 7.14](7.14)
Write a version of the default constructor that explicitly initializes the
members to the values we have provided as in-class initializers.
## [Exercise 7.15](7.15)
Add appropriate constructors to your Person class.
## [Exercise 7.16](7.16.txt)
What, if any, are the constraints on where and how often an access spec-
ifier may appear inside a class definition? What kinds of members should be defined
after a public specifier? What kinds should be private?
## [Exercise 7.17](7.17.txt)
What, if any, are the differences between using class or struct?
## [Exercise 7.18](7.18.txt)
What is encapsulation? Why is it useful?
## [Exercise 7.19](7.19.txt)
Indicate which members of your Person class you would declare as
public and which you would declare as private. Explain your choice.
## [Exercise 7.20](7.20.txt)
When are friends useful? Discuss the pros and cons of using friends.
## [Exercise 7.21](7.21)
Update your Sales_data class to hide its implementation. The pro-
grams you’ve written to use Sales_data operations should still continue to work.
Recompile those programs with your new class definition to verify that they still work.
## [Exercise 7.22](7.22)
Update your Person class to hide its implementation.
## [Exercise 7.23](7.23)
Write your own version of the Screen class.
## [Exercise 7.24](7.24)
Give your Screen class three constructors: a default constructor; a con-
structor that takes values for height and width and initializes the contents to hold the
given number of blanks; and a constructor that takes values for height, width, and a
character to use as the contents of the screen.
## [Exercise 7.25](7.25.txt)
Can Screen safely rely on the default versions of copy and assign-
ment? If so, why? If not, why not?
## [Exercise 7.26](7.26)
Define Sales_data::avg_price as an inline function.
## [Exercise 7.27](7.27)
Add the move, set, and display operations to your version of
Screen. Test your class by executing the following code:
```
Screen myScreen(5, 5, ’X’);
myScreen.move(4,0).set(’#’).display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```
## [Exercise 7.28](7.28.txt)
What would happen in the previous exercise if the return type of move,
set, and display was Screen rather than Screen&?
## [Exercise 7.29](7.29)
Revise your Screen class so that move, set, and display functions
return Screen and check your prediction from the previous exercise.
## [Exercise 7.30](7.30.txt)
It is legal but redundant to refer to members through the this pointer.
Discuss the pros and cons of explicitly using the this pointer to access members.
## [Exercise 7.31](7.31.cpp)
Define a pair of classes X and Y, in which X has a pointer to Y, and Y has
an object of type X.
## [Exercise 7.32](7.32)
Define your own versions of Screen and Window_mgr in which
clear is a member of Window_mgr and a friend of Screen.
## [Exercise 7.33](7.33.txt)
What would happen if we gave Screen a size member defined as
follows? Fix any problems you identify.
```
pos Screen::size() const
{
    return height * width;
}
```
## [Exercise 7.34](7.34.txt)
What would happen if we put the typedef of pos in the Screen class
on page 285 as the last line in the class?
## [Exercise 7.35](7.35.txt)
Explain the following code, indicating which definition of Type or
initVal is used for each use of those names. Say how you would fix any errors.
```
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
## [Exercise 7.36](7.36.txt)
The following initializer is in error. Identify and fix the problem.
```
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
```
## [Exercise 7.37](7.37.txt)
Using the version of Sales_data from this section, determine which
constructor is used to initialize each of the following variables and list the values of the
data members in each object:
```
Sales_data first_item(cin);
int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
}
```
## [Exercise 7.38](7.38)
We might want to supply cin as a default argument to the constructor
that takes an istream&. Write the constructor declaration that uses cin as a default
argument.
## [Exercise 7.39](7.39.txt)
Would it be legal for both the constructor that takes a string and the
one that takes an istream& to have default arguments? If not, why not?
## [Exercise 7.40](7.40)
Choose one of the following abstractions (or an abstraction of your
own choosing). Determine what data are needed in the class. Provide an appropriate
set of constructors. Explain your decisions.
```
(a) Book
(b) Date
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
```
## [Exercise 7.41](7.41)
Rewrite your own version of the Sales_data class to use delegating
constructors. Add a statement to the body of each of the constructors that prints a
message whenever it is executed. Write declarations to construct a Sales_data object
in every way possible. Study the output until you are certain you understand the order
of execution among delegating constructors.
## [Exercise 7.42](7.42)
For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide
whether any of the constructors might use delegation. If so, write the delegating con-
structor(s) for your class. If not, look at the list of abstractions and choose one that you
think would use a delegating constructor. Write the class definition for that abstraction.
## [Exercise 7.43](7.43.cpp)
Assume we have a class named NoDefault that has a constructor that
takes an int, but has no default constructor. Define a class C that has a member of
type NoDefault. Define the default constructor for C.
## [Exercise 7.44](7.44.txt)
Is the following declaration legal? If not, why not?
```
vector<NoDefault> vec(10);
```
## [Exercise 7.45](7.45.txt)
What if we defined the vector in the previous execercise to hold ob-
jects of type C?
## [Exercise 7.46](7.46.txt)
Which, if any, of the following statements are untrue? Why?

(a) A class must provide at least one constructor.
(b) A default constructor is a constructor with an empty parameter list.
(c) If there are no meaningful default values for a class, the class should not pro-
vide a default constructor.
(d) If a class does not define a default constructor, the compiler generates one that
initializes each data member to the default value of its associated type.
## [Exercise 7.47](7.47.txt)
Explain whether the Sales_data constructor that takes a string
should be explicit. What are the benefits of making the constructor explicit?
What are the drawbacks?
## [Exercise 7.48](7.48.txt)
Assuming the Sales_data constructors are not explicit, what op-
erations happen during the following definitions
```
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```
What happens if the Sales_data constructors are explicit?
## [Exercise 7.49](7.49.txt)
For each of the three following declarations of combine, explain what
happens if we call i.combine(s), where i is a Sales_data and s is a string:
```
(a) Sales_data &combine(Sales_data);
(b) Sales_data &combine(Sales_data&);
(c) Sales_data &combine(const Sales_data&) const;
```
## [Exercise 7.50](7.50)
Determine whether any of your Person class constructors should be explicit.
## [Exercise 7.51](7.51.txt)
Why do you think vector defines its single-argument constructor as
explicit, but string does not?
## [Exercise 7.52](7.52.txt)
Using our first version of Sales_data from § 2.6.1 (p. 72), explain the
following initialization. Identify and fix any problems.
```
Sales_data item = {"978-0590353403", 25, 15.99};
```
## [Exercise 7.53](7.53)
Define your own version of Debug.
## [Exercise 7.54](7.54.txt)
Should the members of Debug that begin with set_ be declared as
constexpr? If not, why not?
## [Exercise 7.55](7.55.txt)
Is the Data class from § 7.5.5 (p. 298) a literal class? If not, why not? If
so, explain why it is literal.
## [Exercise 7.56](7.56.txt)
What is a static class member? What are the advantages of static
members? How do they differ from ordinary members?
## [Exercise 7.57](7.57)
Write your own version of the Account class.
## [Exercise 7.58](7.58.txt)
Which, if any, of the following static data member declarations and
definitions are errors? Explain why.
```
// example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
