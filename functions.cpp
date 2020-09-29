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

bool switches(int argc, char* argv[], string* f1, string* f2, string* f3)
{
	int i = 1;
	for (; i < argc-1; i++)
	{
		string sign = argv[i];
		if (sign == "-d")
		{
			*f1 = argv[i + 1];
			i++;
		}
		else if (sign == "-t")
		{
			*f2 = argv[i + 1];
			i++;
		}
		else if (sign == "-o")
		{
			*f3 = argv[i + 1];
			i++;
		}
		else
			return true;
	}
	return (i > 5) ? false : true;
}

list* searchfirstfalse(list* plhead)
{
	while (plhead)
	{
		if (!plhead->qs)
			return plhead;
		plhead = plhead->plnext;
	}
	return nullptr;
}

list* searchthelowest(list* plpointer)
{
	if (plpointer)
	{
		auto p = plpointer->plnext;
		while (p)
		{
			if (!p->qs && p->cost < plpointer->cost)
				plpointer = p;
			p = p->plnext;
		}
	}
	return plpointer;
}

void cnv(list* plhead, list* plpointer)
{
	if (plpointer)
		for (auto pw = plpointer->plcity->pedge; pw; pw = pw->penext)
		{
			auto s = searchinlist(plhead, pw->peforw->city);
			if (!s->qs && s->cost > plpointer->cost + pw->edistance)
			{
				s->cost = plpointer->cost + pw->edistance;
				s->prevcity = plpointer;
				plpointer->forwcity = s;
			}
		}
}

void dijkstra2(node* phead, node* ptail, list*& plhead, list*& pltail, const string& arrival, const string& destination)
{
	searchinlist(plhead, arrival)->cost = 0;
	auto p = plhead; list* u;
	while (p)
	{
		u = searchthelowest(searchfirstfalse(plhead));
		u->qs = true;
		cnv(plhead, u);
		p = p->plnext;
	}
}

bool correctroute(list* plarr, list* pldest)
{
	while (pldest && pldest->prevcity)
		pldest = pldest->prevcity;
	if (pldest == plarr) return 0;
	return 1;
}

void printroute(ofstream& file3, list* plpointer, list* plnextp)
{
	if (plpointer)
	{
		if (plpointer->prevcity)
			printroute(file3, plpointer->prevcity, plpointer);
		if (plnextp)
			file3 << "   " << plpointer->plcity->city << " --> " << plnextp->plcity->city << right << setw(30 - plpointer->plcity->city.length() - plnextp->plcity->city.length()) << plnextp->cost - plpointer->cost << endl;
	}
}
void printsol(ofstream& file3, list* plarr, list* pldest)
{
	if (correctroute(plarr, pldest))
	{
		file3 << "trasa: " << plarr->plcity->city << " --> " << pldest->plcity->city << endl << "   TRASA NIEMOZLIWA DO WYZNACZENIA" << endl;
		return;
	}
	file3 << "trasa: " << plarr->plcity->city << " --> " << pldest->plcity->city << " (" << pldest->cost << " km):" << endl;
	printroute(file3, pldest, nullptr);
}

bool load(ifstream& file, node*& phead, node*& ptail)
{
	string line = string(), city1, city2;
	type route;
	int i = 0, j = 0;
	while (getline(file, line))
	{
		i++;
		stringstream ssl(line);
		if (ssl >> city1 >> city2 >> route)
		{	
			if (route > 0)
				addnode(route, city1, city2, phead, ptail);
			else
				j++;
		}
		else
			j++;
	}
	if (i == j) return false;
	return true;
}

bool load2(ifstream& file2, ofstream& file3, node*& phead, node*& ptail, list*& plhead, list*& pltail)
{
	list* plarr, * pldest;
	string line = string(), city1, city2;
	int i = 0, j = 0;
	while (getline(file2, line))
	{
		i++;
		stringstream ssl(line);
		if (ssl >> city1 >> city2)
		{
			if (!(searchinlist(plhead, city1) && searchinlist(plhead, city2)))
			{
				file3 << "trasa: " << city1 << " --> " << city2 << endl << "   NIEPOPRAWNIE ZADANA TRASA\n\n" << endl;
				continue;
			}
			dijkstra2(phead, ptail, plhead, pltail, city1, city2);
			plarr = searchinlist(plhead, city1);
			pldest = searchinlist(plhead, city2);
			printsol(file3, plarr, pldest);
			resetlist(plhead);
			file3 << "\n\n";
		}
		else
			j++;
	}
	if (i == j) return false;
	return true;
}