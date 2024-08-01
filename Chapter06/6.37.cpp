#include <string>

using std::string;

typedef string type2[10];
using type1 = string[10];

type1 &func1();
type2 &func2();

auto func3() -> string(&)[10];

string sa[10];

decltype(sa) &func4();

int main(){ return 0; }
