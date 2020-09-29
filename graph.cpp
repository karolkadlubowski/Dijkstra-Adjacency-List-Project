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


void addnode(const type distance, const string& city1, const string& city2, node*& phead, node*& ptail)
{
	if (not phead)
	{
		phead = new node{ city1,nullptr,nullptr,ptail };
		ptail = new node{ city2,nullptr,phead,nullptr };
		phead->pnext = ptail;
		addedge(distance, phead, ptail, phead->pedge);
	}
	else
	{
		node* isyet1 = (searchnode(phead, city1));
		node* isyet2 = (searchnode(phead, city2));
		if (not isyet2)
		{
			addendnode(city2, ptail);
			isyet2 = ptail;
		}
		if (isyet1)
			addedge(distance, isyet1, isyet2, isyet1->pedge);
		else
		{
			addendnode(city1, ptail);
			isyet1 = ptail;
			addedge(distance, isyet1, isyet2, isyet1->pedge);
		}
	}
}

void addendnode(const string& city, node*& ptail)
{
	node* pnew = new node{ city, nullptr, ptail, nullptr };
	pnew->pprev->pnext = pnew;
	ptail = pnew;
}

void addedge(const type distance, node*& peback, node*& peforw, edge*& pehead)
{
	if (not pehead)
		pehead = new edge{ distance,peback,peforw,nullptr };
	else
	{
		auto p = pehead;
		while (p->penext)
			p = p->penext;
		p->penext = new edge{ distance, peback,peforw,nullptr };
	}
}


node* searchnode(node* phead, const string& city)
{
	if (phead)
	{
		if (phead->city == city)
			return phead;
		else
			return searchnode(phead->pnext, city);
	}
	else
		return nullptr;
}

void deletealledges(edge*& pehead) 
{
	if (pehead)
	{
		auto pe = pehead->penext;
		delete pehead;
		pehead = nullptr;
		deletealledges(pe);
	}
}
void deleteallnodes(node*& phead, node*& ptail)
{
	if (phead)
	{
		if (phead->pedge)
			deletealledges(phead->pedge);
		deleteallnodes(phead->pnext, ptail);
		delete phead;
		phead = ptail = nullptr;
	}
}