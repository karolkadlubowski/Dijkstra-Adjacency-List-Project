/** @file */
#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <iostream>

using namespace std;

typedef int type;

struct node;
struct list;

/**Struktura reprezentuj¹ca listê krawêdzi danego wêz³a.*/
struct edge 
{
	type edistance; ///< waga krawêdzi
	node* peback;///< wskaŸnik do wêz³a na pocz¹tku krawêdzi
	node* peforw;///< wskaŸnik do wêz³a na koñcu krawêdzi
	edge* penext;///< wskaŸnik na nastêpn¹ krawêdŸ danego wêz³a
};
/**Struktura reprezentuj¹ca listê wêz³ów grafu.*/
struct node 
{
	string city;///< nazwa wêz³a
	edge* pedge;///< wskaŸnik na listê krawêdzi wêz³a
	node* pprev;///< wskaŸnik na poprzedni wêze³
	node* pnext;///< wskaŸnik na nastêpny wêze³
	list* pl; ///< wskaŸnik na miejsce w kolejce wêz³a
};

/**Struktura reprezentuj¹ca kolejkê, w której zawarta jest najkrótsza trasa.*/
struct list 
{
	node* plcity; ///< wskaŸnik na wêze³ grafu
	type cost; ///< obecny najni¿szy koszt dojœcia do wêz³a
	list* prevcity; ///< poprzedni wêze³ w kolejce najkrótszej drogi
	bool qs; ///< zmienna reprezentuje przenoszenie wêz³a do zbioru ju¿ przeszukanych
	list* plprev; ///< wskaŸnik na poprzedni wêze³ w kolejce
	list* plnext; ///< wskaŸnik na nastêpny wêze³ w kolejce
	list* forwcity; ///< wskaŸnik na nastêpny wêze³ w kolejce przy wyznaczaniu najkrótszej drogi
};
#endif