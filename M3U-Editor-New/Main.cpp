#include "M3UParse.h"
#include <iostream>

using namespace std;

int main() {

	M3UParse parse = M3UParse();
	parse.parse("channel_list.txt");

	system("pause");

	return 0;

}