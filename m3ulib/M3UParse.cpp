#include "M3UParse.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


M3UParse::M3UParse()
{
}

vector <vector <string>> M3UParse::parse(string source) {

	using namespace std;

	int line = 1;
	char str[255];
	M3UItem item;
	vector <string> outputLine;
	vector <vector <string>> output;
	string s1 = "#EXTM3U";



	//output.push_back("qwe");


	// ###################### */

	// Create a String[2]
	//jobjectArray arr = jobjectArray();

	// Add items
	// ###################### */


	printf("GET STARTED!\n");

	ifstream in(source);

	if (!in) {
		cout << source << endl;
		cout << "Cannot open input file.\n";
	}

	while (in) {

		if (line % 2 == 0) {
			//item = M3UItem();
			//outputLine.clear();
		}

		in.getline(str, 255);

		int comparisonItem = s1.compare(str);

		if (line == 1 && comparisonItem == 0) {
			printf("Valid M3U File\n");
		}
		else if (line == 1 && comparisonItem != 0) {
			printf("No valid M3U File\n");
			exit(EXIT_FAILURE);
		}

		std::string s(str);

		if (line > 0) {

			if (line % 2 == 0 && s != "") {

				//cout << "EVEN" << endl;
				item = M3UItem();
				item = this->load(s);

				//item.setUrl(this->load(s).getUrl());


			}
			else if (line % 2 != 0 && s != "" && s != "#EXTM3U") {

				//cout << "ODD" << endl;
				item.setUrl(this->load(s).getUrl());

				cout << "----------------" << endl;

				//cout << "Entry:" << line << endl;
				cout << item.getTime() << endl;
				cout << item.getId() << endl;
				cout << item.getLogo() << endl;
				cout << item.getTitle() << endl;
				cout << item.getName() << endl;
				cout << item.getUrl() << endl;

				cout << "----------------" << endl;

				outputLine.push_back(item.getTime());
				outputLine.push_back(item.getId());
				outputLine.push_back(item.getLogo());
				outputLine.push_back(item.getTitle());
				outputLine.push_back(item.getName());
				outputLine.push_back(item.getUrl());
				output.push_back(outputLine);
				outputLine.clear();


			}

		}

		if (s != "") {
			line++;
		}

		/*if (lines == 4) {
		break;
		}*/

	}

	in.close();

	return output;

}

M3UItem M3UParse::load(string line) {
	//printf(line.c_str());

	string s1 = line.c_str();
	string::size_type position1;
	string::size_type position2;
	int summe;
	M3UItem item = M3UItem();

	//cout << line << endl;


	if (s1 != "") {
		string r = s1.substr(0, 8);

		if (r == "#EXTINF:") {

			//cout << static_cast<int>(s1.find(",", 8)) << endl;

			//cout << "COOL: " << static_cast<int>(s1.find(",", 8)) << endl;

			if (static_cast<int>(s1.find(",", 8)) < 20) {
				position2 = s1.find(",", 8);

				summe = static_cast<int>(position2) - 8;
				//cout << "TIME: " << s1.substr(8, summe) << endl;

				item.setTime(s1.substr(8, summe));

				//printf("\n");

			}
			else {
				//cout << "JOOOO";
				//cout << "-1";
				item.setTime("-1");
				//printf("\n");
			}

			if (static_cast<int>(s1.find("tvg-id=")) > 0) {
				position1 = s1.find("tvg-id=");
				position2 = s1.find("\"", position1 + 8);

				summe = static_cast<int>(position2) - static_cast<int>(position1 + 8);
				//cout << "ID: " << s1.substr(position1 + 8, summe) << endl;

				item.setId(s1.substr(position1 + 8, summe));

				//printf("\n");
			}

			if (static_cast<int>(s1.find("tvg-logo=")) > 0) {
				position1 = s1.find("tvg-logo=");
				position2 = s1.find("\"", position1 + 10);

				summe = static_cast<int>(position2) - static_cast<int>(position1 + 10);
				//cout << "Logo: " << s1.substr(position1 + 10, summe) << endl;

				item.setLogo(s1.substr(position1 + 10, summe));

				//printf("\n");
			}

			if (static_cast<int>(s1.find("group-title=")) > 0) {
				position1 = s1.find("group-title=");
				position2 = s1.find("\"", position1 + 13);

				summe = static_cast<int>(position2) - static_cast<int>(position1 + 13);
				//cout << "Group: " << s1.substr(position1 + 13, summe) << endl;

				item.setTitle(s1.substr(position1 + 13, summe));

				//printf("\n");

			}

			position2 = s1.find(",", 8);
			//cout << "Stoner" << position2 << endl;

			if (static_cast<int>(s1.find(",", position2)) > 0) {
				position1 = s1.find(",", position2);

				//cout << "Description: " << s1.substr(position1 + 1, 255) << endl;

				item.setName(s1.substr(position1 + 1, 255));
				//cout << item.getName() << endl;
			}

		}

		if (r != "#EXTINF:" && r != "#EXTM3U") {
			//cout << "URL: " << s1 << endl;
			item.setUrl(s1);
		}

		//cout << item.getName() << endl;

		//printf("\n");
	}

	return item;
}