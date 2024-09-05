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
