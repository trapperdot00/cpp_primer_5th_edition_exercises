# Chapter16: Templates and Generic Programming
## [Exercise 16.1](16.01.txt)
Define instantiation.
## [Exercise 16.2](16.02)
Write and test your own versions of the compare functions.
## [Exercise 16.3](16.03)
Call your compare function on two Sales_data objects to see how your compiler handles errors during instantiation.
## [Exercise 16.4](16.04)
Write a template that acts like the library find algorithm. The function will need two template type parameters, one to represent the function’s iterator parameters and the other for the type of the value. Use your function to find a given value in a vector<int> and in a list<string>.
## [Exercise 16.5](16.05)
Write a template version of the print function from § 6.2.4 (p. 217) that takes a reference to an array and can handle arrays of any size and any element type.
## [Exercise 16.6](16.06)
How do you think the library begin and end functions that take an array argument work? Define your own versions of these functions.
## [Exercise 16.7](16.07)
Write a constexpr template that returns the size of a given array.
## [Exercise 16.8](16.08.txt)
In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers prefer using != to using <. Explain the rationale for this habit.
## [Exercise 16.9](16.09.txt)
What is a function template? What is a class template?
## [Exercise 16.10](16.10.txt)
What happens when a class template is instantiated?
## [Exercise 16.11](16.11.txt)
The following definition of List is incorrect. How would you fix it?
```
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem *front, *end;
};
```
## [Exercise 16.12](16.12)
Write your own version of the Blob and BlobPtr templates. including the various const members that were not shown in the text.
## [Exercise 16.13](16.13.txt)
Explain which kind of friendship you chose for the equality and relational operators for BlobPtr.
## [Exercise 16.14](16.14)
Write a Screen class template that uses nontype parameters to define the height and width of the Screen.
## [Exercise 16.15](16.15)
Implement input and output operators for your Screen template. Which, if any, friends are necessary in class Screen to make the input and output operators work? Explain why each friend declaration, if any, was needed.
## [Exercise 16.16](16.16)
Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec.
## [Exercise 16.17](16.17.txt)
What, if any, are the differences between a type parameter that is declared as a typename and one that is declared as a class? When must typename be used?
## [Exercise 16.18](16.18.txt)
Explain each of the following function template declarations and identify whether any are illegal. Correct each error that you find.
```
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int*);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
    template <typename Ctype> Ctype f5(Ctype a);
```
## [Exercise 16.19](16.19.cpp)
Write a function that takes a reference to a container and prints the elements in that container. Use the container’s size_type and size members to control the loop that prints the elements.
## [Exercise 16.20](16.20.cpp)
Rewrite the function from the previous exercise to use iterators returned from begin and end to control the loop.
## [Exercise 16.21](16.21)
Write your own version of DebugDelete.
## [Exercise 16.22](16.22)
Revise your TextQuery programs from § 12.3 (p. 484) so that the shared_ptr members use a DebugDelete as their deleter (§ 12.1.4, p. 468).
## [Exercise 16.23](16.23.txt)
Predict when the call operator will be executed in your main query program. If your expectations and what happens differ, be sure you understand why.
## [Exercise 16.24](16.24)
Add a constructor that takes two iterators to your Blob template.
## [Exercise 16.25](16.25.txt)
Explain the meaning of these declarations:
```
extern template class vector<string>;
template class vector<Sales_data>;
```
## [Exercise 16.26](16.26.txt)
Assuming NoDefault is a class that does not have a default constructor, can we explicitly instantiate vector<NoDefault>? If not, why not?
## [Exercise 16.27](16.27.txt)
For each labeled statement explain what, if any, instantiations happen.
If a template is instantiated, explain why; if not, explain why not.
```
template <typename T> class Stack { };
void f1(Stack<char>);   // (a)
class Exercise {
    Stack<double> &rsd; // (b)
    Stack<int>  si;     // (c)
};
int main() {
    Stack<char> *sc;    // (d)
    f1(*sc);            // (e)
    int iObj = sizeof(Stack< string >); // (f)
}
```
## [Exercise 16.28](16.28)
Write your own versions of shared_ptr and unique_ptr.
