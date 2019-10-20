#include "M3UItem.h"



M3UItem::M3UItem()
{
}

void M3UItem::setTime(string param) {
	time = param;
}

void M3UItem::setId(string param) {
	id = param;
}

void M3UItem::setLogo(string param) {
	logo = param;
}
void M3UItem::setTitle(string param) {
	title = param;
}

void M3UItem::setName(string param) {
	name = param;
}

void M3UItem::setUrl(string param) {
	url = param;
}

string M3UItem::getTime() {
	return time;
}

string M3UItem::getId() {
	return id;
}

string M3UItem::getLogo() {
	return logo;
}

string M3UItem::getTitle() {
	return title;
}

string M3UItem::getName() {
	return name;
}

string M3UItem::getUrl() {
	return url;
}
