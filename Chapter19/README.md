# Chapter19: Specialized Tools and Techniques
## [Exercise 19.1](19.01.cpp)
Write your own operator new(size_t) function using malloc and use free to write the operator delete(void*) function.
## [Exercise 19.2](19.02)
By default, the allocator class uses operator new to obtain storage and operator delete to free it. Recompile and rerun your StrVec programs (§ 13.5, p. 526) using your versions of the functions from the previous exercise.
## [Exercise 19.3](19.03.txt)
Given the following class hierarchy in which each class defines a public default constructor and virtual destructor:
```
class A { /* . . . */ };
class B : public A { /* . . . */ };
class C : public B { /* . . . */ };
class D : public B, public A { /* . . . */ };
```
which, if any, of the following dynamic_casts fail?
```
(a) A *pa = new C;
    B *pb = dynamic_cast< B* >(pa);
(b) B *pb = new B;
    C *pc = dynamic_cast< C* >(pb);
(c) A *pa = new D;
    B *pb = dynamic_cast< B* >(pa);
```
## [Exercise 19.4](19.04.cpp)
Using the classes defined in the first exercise, rewrite the following code to convert the expression *pa to the type C&:
```
if (C *pc = dynamic_cast< C* >(pa))
    // use C’s members
} else {
    // use A’s members
}
```
## [Exercise 19.5](19.05.txt)
When should you use a dynamic_cast instead of a virtual function?
## [Exercise 19.6](19.06)
Write an expression to dynamically cast a pointer to a Query_base to a pointer to an AndQuery (§ 15.9.1, p. 636). Test the cast by using objects of AndQuery and of another query type. Print a statement indicating whether the cast works and be sure that the output matches your expectations.
## [Exercise 19.7](19.07)
Write the same cast, but cast a Query_base object to a reference to AndQuery. Repeat the test to ensure that your cast works correctly.
## [Exercise 19.8](19.08)
Write a typeid expression to see whether two Query_base pointers point to the same type. Now check whether that type is an AndQuery.
## [Exercise 19.9](19.09)
Write a program similar to the last one in this section to print the names your compiler uses for common type names. If your compiler gives output similar to ours, write a function that will translate those strings to more human-friendly form.
## [Exercise 19.10](19.10.txt)
Given the following class hierarchy in which each class defines a
public default constructor and virtual destructor, which type name do the follow-
ing statements print?
```
class A { /* . . . */ };
class B : public A { /* . . . */ };
class C : public B { /* . . . */ };

(a) A *pa = new C;
    cout << typeid(pa).name() << endl;
(b) C cobj;
    A& ra = cobj;
    cout << typeid(&ra).name() << endl;
(c) B *px = new B;
    A& ra = *px;
    cout << typeid(ra).name() << endl;
```
## [Exercise 19.11](19.11.txt)
What is the difference between an ordinary data pointer and a pointer to a data member?
## [Exercise 19.12](19.12)
Define a pointer to member that can point to the cursor member of class Screen. Fetch the value of Screen::cursor through that pointer.
## [Exercise 19.13](19.13)
Define the type that can represent a pointer to the bookNo member of the Sales_data class.
## [Exercise 19.14](19.14.txt)
Is the following code legal? If so, what does it do? If not, why?
```
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```
## [Exercise 19.15](19.15.txt)
What is the difference between an ordinary function pointer and a pointer to a member function?
## [Exercise 19.16](19.16)
Write a type alias that is a synonym for a pointer that can point to the avg_price member of Sales_data.
## [Exercise 19.17](19.17)
Define a type alias for each distinct Screen member function type.
