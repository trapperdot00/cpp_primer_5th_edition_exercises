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
class D : public B, public A { /* . . .
*/ };
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
