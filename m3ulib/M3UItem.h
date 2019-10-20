#include <string>

using namespace std;

#pragma once
class M3UItem
{
private:
	string time;
	string id;
	string logo;
	string title;
	string name;
	string url;
public:
	M3UItem();
	void setTime(string param);
	void setId(string param);
	void setLogo(string param);
	void setTitle(string param);
	void setName(string param);
	void setUrl(string param);

	string getTime();
	string getId();
	string getLogo();
	string getTitle();
	string getName();
	string getUrl();
};

