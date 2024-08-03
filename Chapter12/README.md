# Chapter12: Dynamic Memory
## [Exercise 12.1](12.01.txt)
How many elements do b1 and b2 have at the end of this code?
```
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```
## [Exercise 12.2](12.02)
Write your own version of the StrBlob class including the const ver-
sions of front and back.
## [Exercise 12.3](12.03.txt)
Does this class need const versions of push_back and pop_back? If
so, add them. If not, why aren’t they needed?
## [Exercise 12.4](12.04.txt)
In our check function we didn’t check whether i was greater than
zero. Why is it okay to omit that check?
## [Exercise 12.5](12.05.txt)
We did not make the constructor that takes an initializer_list
explicit (§ 7.5.4, p. 296). Discuss the pros and cons of this design choice.
## [Exercise 12.6](12.06.cpp)
Write a function that returns a dynamically allocated vector of ints.
Pass that vector to another function that reads the standard input to give values to
the elements. Pass the vector to another function to print the values that were read.
Remember to delete the vector at the appropriate time.
## [Exercise 12.7](12.07.cpp)
Redo the previous exercise, this time using shared_ptr.
## [Exercise 12.8](12.08.txt)
Explain what if anything is wrong with the following function.
```
bool b() {
    int* p = new int;
    // . . .
    return p;
}
```
## [Exercise 12.9](12.09.txt)
Explain what happens in the following code:
```
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
## [Exercise 12.10](12.10.txt)
Explain whether the following call to the process function defined
on page 464 is correct. If not, how would you correct the call?
```
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```
## [Exercise 12.11](12.11.txt)
What would happen if we called process as follows?
```
process(shared_ptr<int>(p.get()));
```
## [Exercise 12.12](12.12.txt)
Using the declarations of p and sp explain each of the following calls
to process. If the call is legal, explain what it does. If the call is illegal, explain why:
```
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```
## [Exercise 12.13](12.13.txt)
What happens if we execute the following code?
```
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```
## [Exercise 12.14](12.14.cpp)
Write your own version of a function that uses a shared_ptr to man-
age a connection.
## [Exercise 12.15](12.15.cpp)
Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place of
the end_connection function.
## [Exercise 12.16](12.16)
Compilers don’t always give easy-to-understand error messages if we
attempt to copy or assign a unique_ptr. Write a program that contains these errors
to see how your compiler diagnoses them.
## [Exercise 12.17](12.17.txt)
Which of the following unique_ptr declarations are illegal or likely
to result in subsequent program error? Explain what the problem is with each one.
```
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());
```
## [Exercise 12.18](12.18.txt)
Why doesn’t shared_ptr have a release member?
## [Exercise 12.19](12.19)
Define your own version of StrBlobPtr and update your StrBlob
class with the appropriate friend declaration and begin and end members.
## [Exercise 12.20](12.20)
Write a program that reads an input file a line at a time into a StrBlob
and uses a StrBlobPtr to print each element in that StrBlob.
## [Exercise 12.21](12.21.txt)
We could have written StrBlobPtr’s deref member as follows:
```
std::string& deref() const
{ return (*check(curr, "dereference past end"))[curr]; }
```
Which version do you think is better and why?
## [Exercise 12.22](12.22)
What changes would need to be made to StrBlobPtr to create a class
that can be used with a const StrBlob? Define a class named ConstStrBlobPtr
that can point to a const StrBlob.
## [Exercise 12.23](12.23)
Write a program to concatenate two string literals, putting the result
in a dynamically allocated array of char. Write a program to concatenate two library
strings that have the same value as the literals used in the first program.
## [Exercise 12.24](12.24.cpp)
Write a program that reads a string from the standard input into a
dynamically allocated character array. Describe how your program handles varying
size inputs. Test your program by giving it a string of data that is longer than the array
size you’ve allocated.
## [Exercise 12.25](12.25.txt)
Given the following new expression, how would you delete pa?
```
int *pa = new int[10];
```
## [Exercise 12.26](12.26.cpp)
Rewrite the program on page 481 using an allocator.
## [Exercise 12.27](12.27)
The TextQuery and QueryResult classes use only capabilities that
we have already covered. Without looking ahead, write your own versions of these
classes.
## [Exercise 12.28](12.28.cpp)
Write a program to implement text queries without defining classes to
manage the data. Your program should take a file and interact with a user to query for
words in that file. Use vector, map, and set containers to hold the data for the file
and to generate the results for the queries.
## [Exercise 12.29](12.29.cpp)
We could have written the loop to manage the interaction with the
user as a do while (§ 5.4.4, p. 189) loop. Rewrite the loop to use a do while. Explain
which version you prefer and why.
## [Exercise 12.30](12.30)
Define your own versions of the TextQuery and QueryResult
classes and execute the runQueries function from § 12.3.1 (p. 486).
## [Exercise 12.31](12.31.txt)
What difference(s) would it make if we used a vector instead of a
set to hold the line numbers? Which approach is better? Why?
## [Exercise 12.32](12.32)
Rewrite the TextQuery and QueryResult classes to use a StrBlob
instead of a vector<string> to hold the input file.
## [Exercise 12.33](12.33)
In Chapter 15 we’ll extend our query system and will need some addi-
tional members in the QueryResult class. Add members named begin and end that
return iterators into the set of line numbers returned by a given query, and a member
named get_file that returns a shared_ptr to the file in the QueryResult object.
