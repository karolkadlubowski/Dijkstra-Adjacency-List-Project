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

void addtolist(node* plcity, list*& plhead, list*& pltail)
{
	plhead = pltail = new list{ plcity,INT_MAX,nullptr,false,nullptr,nullptr };
	plcity->pl = plhead;
	plcity = plcity->pnext;
	while (plcity)
	{
		pltail->plnext = new list{ plcity,INT_MAX,nullptr,false,pltail,nullptr };
		pltail = pltail->plnext;
		plcity->pl = pltail;
		plcity = plcity->pnext;
	}
}

list* searchinlist(list* plhead, const string& plcity)
{
	if (plhead)
	{
		if (plhead->plcity->city == plcity)
			return plhead;
		else return searchinlist(plhead->plnext, plcity);
	}
	else
		return nullptr;
}

void deletelist(list*& plhead, list*& pltail)
{
	if (plhead)
	{
		deletelist(plhead->plnext, pltail);
		delete plhead;
		plhead = pltail = nullptr;
	}
}

void resetlist(list* plhead)
{
	while (plhead)
	{
		plhead->cost = INT_MAX;
		plhead->forwcity = plhead->prevcity = nullptr;
		plhead->qs = false;
		plhead = plhead->plnext;
	}
}