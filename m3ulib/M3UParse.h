#include <string>
#include <vector>
#include "M3UItem.h"

using namespace std;

#pragma once
class M3UParse
{
private:
	M3UItem load(string line);
public:
	M3UParse();
	vector <vector <string>> parse(string source);
};