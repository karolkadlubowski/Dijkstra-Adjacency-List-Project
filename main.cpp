#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip> 
#include <sstream>

#include "graph.h"
#include "structures.h"
#include "list.h"
#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{
	string* filename1 = new string, * filename2 = new string, * filename3 = new string;
	if (switches(argc, argv, filename1, filename2, filename3))
	{
		cout << "Niepoprawne parametry programu" << endl;
		return 0;
	}
	ifstream file(*filename1);
	node* phead = nullptr, * ptail = nullptr;
	if (file)
	{
		if (!load(file, phead, ptail))
		{
			file.close();
			cout << "Niepoprawny plik mapy" << endl;
			return 0;
		}
	}
	else
	{
		file.close();
		cout << "Brak pliku mapy" << endl;
		return 0;
	}
	list* plhead = nullptr, * pltail = nullptr;
	addtolist(phead, plhead, pltail);
	ifstream file2(*filename2);
	ofstream file3(*filename3);
	if (file2)
	{
		if (!load2(file2, file3, phead, ptail, plhead, pltail))
		{
			file2.close();
			file3.close();
			cout << "Niepoprawny plik tras do wyszukania" << endl;
			return 0;
		}
	}
	else
	{
		file2.close();
		file3.close();
		cout << "Brak pliku z zadanymi trasami" << endl;
		return 0;
	}
	file.close();
	file2.close();
	file3.close();
	deleteallnodes(phead, ptail);
	deletelist(plhead, pltail);
	delete filename1;
	delete filename2;
	delete filename3;
	return 0;
}