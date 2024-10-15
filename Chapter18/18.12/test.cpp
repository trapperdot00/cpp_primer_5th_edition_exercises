#include "chapter01.h"
#include "chapter02.h"
#include "chapter03.h"
#include "chapter06.h"
#include "chapter07.h"
#include "chapter09.h"
#include "chapter10.h"
#include "chapter11.h"
#include "chapter12.h"
#include "chapter13.h"
#include "chapter14.h"
#include "chapter15.h"
#include "chapter16.h"
#include "chapter17.h"
#include "chapter18.h"

#include <iostream>
#include <string>

int main() {
	cplusplus_primer::chapter12::StrBlob sb({"a", "b"});
	cplusplus_primer::chapter13::_50::String s;
	cplusplus_primer::chapter14::_40::PrintString prints(std::cout, '\n');
	prints("wow");
	cplusplus_primer::chapter15::_42::StrBlob sb2({"aaa", "bbb"});
	cplusplus_primer::chapter16::_62::Sales_data sd1("book1");
	cplusplus_primer::chapter17::_06::Sales_data sd2("book2");
	cplusplus_primer::chapter18::_10::Sales_data sd3("book3");
	return 0;
}
