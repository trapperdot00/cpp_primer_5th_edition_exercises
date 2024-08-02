# Chapter04: Expressions
## [Exercise 4.1](Chapter04/4.01.txt)
What is the value returned by 5 + 10 * 20/2?
## [Exercise 4.2](Chapter04/4.02.txt)
Using Table 4.12 (p. 166), parenthesize the following expressions to indi-
cate the order in which the operands are grouped:
```
(a) * vec.begin()
(b) * vec.begin() + 1
```
## [Exercise 4.3](Chapter04/4.03.txt)
Order of evaluation for most of the binary operators is left undefined
to give the compiler opportunities for optimization. This strategy presents a trade-off
between efficient code generation and potential pitfalls in the use of the language by
the programmer. Do you consider that an acceptable trade-off? Why or why not?
## [Exercise 4.4](Chapter04/4.04.cpp)
Parenthesize the following expression to show how it is evaluated. Test
your answer by compiling the expression (without parentheses) and printing its result.
```
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```
## [Exercise 4.5](Chapter04/4.05.txt)
Determine the result of the following expressions.
```
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5
(d) -30 / 3 * 21 % 4
```
## [Exercise 4.6](Chapter04/4.06.txt)
Write an expression to determine whether an int value is even or odd.
## [Exercise 4.7](Chapter04/4.07.txt)
What does overflow mean? Show three expressions that will overflow.
## [Exercise 4.8](Chapter04/4.08.txt)
Explain when operands are evaluated in the logical AND, logical OR, and
equality operators.
## [Exercise 4.9](Chapter04/4.09.txt)
Explain the behavior of the condition in the following if:
```
const char *cp = "Hello World";
if (cp && *cp)
```
## [Exercise 4.10](Chapter04/4.10.cpp)
Write the condition for a while loop that would read ints from the
standard input and stop when the value read is equal to 42.
## [Exercise 4.11](Chapter04/4.11.cpp)
Write an expression that tests four values, a, b, c, and d, and ensures
that a is greater than b, which is greater than c, which is greater than d.
## [Exercise 4.12](Chapter04/4.12.txt)
Assuming i, j, and k are all ints, explain what i != j < k means.
## [Exercise 4.13](Chapter04/4.13.txt)
What are the values of i and d after each assignment?
```
int i;
double d;
(a) d = i = 3.5;
(b) i = d = 3.5;
```
## [Exercise 4.14](Chapter04/4.14.txt)
Explain what happens in each of the if tests:
```
if (42 = i) // ...
if (i = 42) // ...
```
## [Exercise 4.15](Chapter04/4.15.txt)
The following assignment is illegal. Why? How would you correct it?
```
double dval; int ival; int *pi;
dval = ival = pi = 0;
```
## [Exercise 4.16](Chapter04/4.16.txt)
Although the following are legal, they probably do not behave as the
programmer expects. Why? Rewrite the expressions as you think they should be.
```
(a) if (p = getPtr() != 0)
(b) if (i = 1024)
```
## [Exercise 4.17](Chapter04/4.17.txt)
Explain the difference between prefix and postfix increment.
## [Exercise 4.18](Chapter04/4.18.txt)
What would happen if the while loop on page 148 that prints the ele-
ments from a vector used the prefix increment operator?
## [Exercise 4.19](Chapter04/4.19.txt)
Given that ptr points to an int, that vec is a vector<int>, and that
ival is an int, explain the behavior of each of these expressions. Which, if any, are
likely to be incorrect? Why? How might each be corrected?
```
(a) ptr != 0 && *ptr++
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]
```
## [Exercise 4.20](Chapter04/4.20.txt)
Assuming that iter is a vector<string>::iterator, indicate
which, if any, of the following expressions are legal. Explain the behavior of the le-
gal expressions and why those that aren’t legal are in error.
```
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty()
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();
```
## [Exercise 4.21](Chapter04/4.21.cpp)
Write a program to use a conditional operator to find the elements in a
vector<int> that have odd value and double the value of each such element.
## [Exercise 4.22](Chapter04/4.22)
Extend the program that assigned high pass, pass, and fail grades to
also assign low pass for grades between 60 and 75 inclusive. Write two versions: One
version that uses only conditional operators; the other should use one or more if
statements. Which version do you think is easier to understand and why?
## [Exercise 4.23](Chapter04/4.23.txt)
The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```
string s = "word";
string pl = s + s[s.size() - 1] == ’s’ ? "" : "s" ;
```
## [Exercise 4.24](Chapter04/4.24.txt)
Our program that distinguished between high pass, pass, and fail de-
pended on the fact that the conditional operator is right associative. Describe how that
operator would be evaluated if the operator were left associative.
## [Exercise 4.25](Chapter04/4.25.txt)
What is the value of ~’q’ << 6 on a machine with 32-bit ints and 8 bit
chars, that uses Latin-1 character set in which ’q’ has the bit pattern 01110001?
## [Exercise 4.26](Chapter04/4.26.txt)
In our grading example in this section, what would happen if we used
unsigned int as the type for quiz1?
## [Exercise 4.27](Chapter04/4.27.txt)
What is the result of each of these expressions?
```
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2
(b) ul1 | ul2
(c) ul1 && ul2
(d) ul1 || ul2
```
## [Exercise 4.28](Chapter04/4.28.cpp)
Write a program to print the size of each of the built-in types.
## [Exercise 4.29](Chapter04/4.29.cpp)
Predict the output of the following code and explain your reasoning.
Now run the program. Is the output what you expected? If not, figure out why.
```
int x[10];
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```
## [Exercise 4.30](Chapter04/4.30.txt)
Using Table 4.12 (p. 166), parenthesize the following expressions to
match the default evaluation:
```
(a) sizeof x + y
(b) sizeof p->mem[i]
(c) sizeof a < b
(d) sizeof f()
```
## [Exercise 4.31](Chapter04/4.31.cpp)
The program in this section used the prefix increment and decrement
operators. Explain why we used prefix and not postfix. What changes would have to
be made to use the postfix versions? Rewrite the program using postfix operators.
## [Exercise 4.32](Chapter04/4.32.txt)
Explain the following loop.
```
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr)
  { /* . . . */ }
```
## [Exercise 4.33](Chapter04/4.33)
Using Table 4.12 (p. 166) explain what the following expression does:
```
someValue ? ++x, ++y : --x, --y
```
## [Exercise 4.34](Chapter04/4.34.txt)
Given the variable definitions in this section, explain what conversions
take place in the following expressions:
```
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
```
Remember that you may need to consider the associativity of the operators.
## [Exercise 4.35](Chapter04/4.35.txt)
Given the following definitions,
```
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
```
identify the implicit type conversions, if any, taking place:
```
(a) cval = ’a’ + 3;
(b) fval = ui - ival * 1.0;
(c) dval = ui * fval;
(d) cval = ival + fval + dval;
```
## [Exercise 4.36](Chapter04/4.36.txt)
Assuming i is an int and d is a double write the expression i *= d so
that it does integral, rather than floating-point, multiplication.
## [Exercise 4.37](Chapter04/4.37.txt)
Rewrite each of the following old-style casts to use a named cast:
```
int i;
double d;
const string *ps;
char *pc;
void *pv;
(a) pv = (void*)ps;
(b) i = int(*pc);
(c) pv = &d;
(d) pc = (char*) pv;
```
## [Exercise 4.38](Chapter04/4.38.txt)
Explain the following expression:
```
double slope = static_cast<double>(j/i);
```
