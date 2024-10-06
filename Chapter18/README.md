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
