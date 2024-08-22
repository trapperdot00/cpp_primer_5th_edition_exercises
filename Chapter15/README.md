# Chapter15: Object-Oriented Programming
## [Exercise 15.1](15.01.txt)
What is a virtual member?
## [Exercise 15.2](15.02.txt)
How does the protected access specifier differ from private?
## [Exercise 15.3](15.03)
Define your own versions of the Quote class and the print_total function.
## [Exercise 15.4](15.04.txt)
Which of the following declarations, if any, are incorrect? Explain why.
```
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```
## [Exercise 15.5](15.05)
Define your own version of the Bulk_quote class.
## [Exercise 15.6](15.06)
Test your print_total function from the exercises in § 15.2.1 (p. 595) by passing both Quote and Bulk_quote objects o that function.
## [Exercise 15.7](15.07)
Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.
## [Exercise 15.8](15.08.txt)
Define static type and dynamic type.
## [Exercise 15.9](15.09.txt)
When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.
## [Exercise 15.10](15.10.txt)
Recalling the discussion from § 8.1 (p. 311), explain how the program on page 317 that passed an ifstream to the Sales_data read function works.
## [Exercise 15.11](15.11)
Add a virtual debug function to your Quote class hierarchy that displays the data members of the respective classes.
## [Exercise 15.12](15.12.txt)
Is it ever useful to declare a member function as both override and final? Why or why not?
## [Exercise 15.13](15.13.txt)
Given the following classes, explain each print function:
```
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) { print(os); os << " " << i; }
private:
    int i;
};
```
If there is a problem in this code, how would you fix it?
## [Exercise 15.14](15.14.txt)
Given the classes from the previous exercise and the following objects, determine which function is called at run time:
```
base bobj;
base *bp1 = &bobj;
base &br1 = bobj;
derived dobj;
base *bp2 = &dobj;
base &br2 = dobj;

(a) bobj.print();
(b) dobj.print();
(c) bp1->name();
(d) bp2->name();
(e) br1.print();
(f) br2.print();
```
## [Exercise 15.15](15.15)
Define your own versions of Disk_quote and Bulk_quote.
## [Exercise 15.16](15.16)
Rewrite the class representing a limited discount strategy, which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.
## [Exercise 15.17](15.17)
Try to define an object of type Disc_quote and see what errors you get from the compiler.
## [Exercise 15.18](15.18.txt)
Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:
```
Base *p = &d1;  //  d1 has type Pub_Derv
p = &d2;        //  d2 has type Priv_Derv
p = &d3;        //  d3 has type Prot_Derv
p = &dd1;       //  dd1 has type Derived_from_Public
p = &dd2;       //  dd2 has type Derived_from_Private
p = &dd3;       //  dd3 has type Derived_from_Protected
```
## [Exercise 15.19](15.19.txt)
Assume that each of the classes from page 612 and page 613 has a member function of the form:
```
void memfcn(Base &b) { b = *this; }
```
For each class, determine whether this function would be legal.
## [Exercise 15.20](15.20)
Write code to test your answers to the previous two exercises.
## [Exercise 15.21](15.21)
Choose one of the following general abstractions containing a family of types (or choose one of your own). Organize the types into an inheritance hierarchy:
(a) Graphical file formats (such as gif, tiff, jpeg, bmp)
(b) Geometric primitives (such as box, circle, sphere, cone)
(c) C++ language types (such as class, function, member function)
## [Exercise 15.22](15.22.txt)
For the class you chose in the previous exercise, identify some of the likely virtual functions as well as public and protected members.
## [Exercise 15.23](15.23.txt)
Assuming class D1 on page 620 had intended to override its inherited fcn function, how would you fix that class? Assuming you fixed the class so that fcn matched the definition in Base, how would the calls in that section be resolved?
## [Exercise 15.24](15.24.txt)
What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?
## [Exercise 15.25](15.25.txt)
Why did we define a default constructor for Disc_quote? What effect, if any, would removing that constructor have on the behavior of Bulk_quote?