# Chapter18: Tools for Large Programs
## [Exercise 18.1](18.01.txt)
What is the type of the exception object in the following throws?
```
(a) range_error r("error");
    throw r;
(b) exception *p = &r;
    throw *p;
```
What would happen if the throw in (b) were written as throw p?
## [Exercise 18.2](18.02.txt)
Explain what happens if an exception occurs at the indicated point:
```
void exercise(int *b, int *e)
{
    vector<int> v(b, e);
    int *p = new int[v.size()];
    ifstream in("ints");
    // exception occurs here
}
```
## [Exercise 18.3](18.03)
There are two ways to make the previous code work correctly if an exception is thrown. Describe them and implement them.
## [Exercise 18.4](18.04.txt)
Looking ahead to the inheritance hierarchy in Figure 18.1 (p. 783), explain what’s wrong with the following try block. Correct it.
```
try {
    // use of the C++ standard library
} catch(exception) {
    // ...
} catch(const runtime_error &re) {
    // ...
} catch(overflow_error eobj) { /* ... */ }
```
## [Exercise 18.5](18.05.cpp)
Modify the following main function to catch any of the exception types shown in Figure 18.1 (p. 783):
```
int main() {
// use of the C++ standard library
}
```
The handlers should print the error message associated with the exception before calling abort (defined in the header cstdlib) to terminate main.
## [Exercise 18.6](18.06.txt)
Given the following exception types and catch clauses, write a throw expression that creates an exception object that can be caught by each catch clause:
```
(a) class exceptionType { };
    catch(exceptionType *pet) { }
(b) catch(...) { }
(c) typedef int EXCPTYPE;
    catch(EXCPTYPE) { }
```
## [Exercise 18.7](18.07)
Define your Blob and BlobPtr classes from Chapter 16 to use function try blocks for their constructors.
## [Exercise 18.8](18.08)
Review the classes you’ve written and add appropriate exception specifications to their constructors and destructors. If you think one of your destructors might throw, change the code so that it cannot throw.
## [Exercise 18.9](18.09)
Define the bookstore exception classes described in this section and rewrite your Sales_data compound assigment operator to throw an exception.
## [Exercise 18.10](18.10)
Write a program that uses the Sales_data addition operator on objects that have differing ISBN s. Write two versions of the program: one that handles the exception and one that does not. Compare the behavior of the programs so that you become familiar with what happens when an uncaught exception occurs.
## [Exercise 18.11](18.11.txt)
Why is it important that the what function doesn’t throw?
## [Exercise 18.12](18.12)
Organize the programs you have written to answer the questions in each chapter into their own namespaces. That is, namespace chapter15 would contain code for the Query programs and chapter10 would contain the TextQuery code. Using this structure, compile the Query code examples.
## [Exercise 18.13](18.13.txt)
When might you use an unnamed namespace?
## [Exercise 18.14](18.14.txt)
Suppose we have the following declaration of the operator* that is
a member of the nested namespace mathLib::MatrixLib:
```
    namespace mathLib {
        namespace MatrixLib {
            class matrix { /* ... */ };
            matrix operator*
                    (const matrix &, const matrix &);
            // ...
        }
    }
```
How would you declare this operator in global scope?
## [Exercise 18.15](18.15.txt)
Explain the differences between using declarations and directives.
## [Exercise 18.16](18.16.txt)
Explain the following code assuming using declarations for all the
members of namespace Exercise are located at the location labeled position 1. What
if they appear at position 2 instead? Now answer the same question but replace the
using declarations with a using directive for namespace Exercise.
```
    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;
    }
    int ivar = 0;
    // position 1
    void manip() {
        // position 2
        double dvar = 3.1416;
        int iobj = limit + 1;
        ++ivar;
        ++::ivar;
    }
```
## [Exercise 18.17](18.17)
Write code to test your answers to the previous question.
