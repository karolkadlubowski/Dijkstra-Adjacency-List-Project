/** @file */
#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <iostream>

using namespace std;

typedef int type;

struct node;
struct list;

/**Struktura reprezentuj�ca list� kraw�dzi danego w�z�a.*/
struct edge 
{
	type edistance; ///< waga kraw�dzi
	node* peback;///< wska�nik do w�z�a na pocz�tku kraw�dzi
	node* peforw;///< wska�nik do w�z�a na ko�cu kraw�dzi
	edge* penext;///< wska�nik na nast�pn� kraw�d� danego w�z�a
};
/**Struktura reprezentuj�ca list� w�z��w grafu.*/
struct node 
{
	string city;///< nazwa w�z�a
	edge* pedge;///< wska�nik na list� kraw�dzi w�z�a
	node* pprev;///< wska�nik na poprzedni w�ze�
	node* pnext;///< wska�nik na nast�pny w�ze�
	list* pl; ///< wska�nik na miejsce w kolejce w�z�a
};

/**Struktura reprezentuj�ca kolejk�, w kt�rej zawarta jest najkr�tsza trasa.*/
struct list 
{
	node* plcity; ///< wska�nik na w�ze� grafu
	type cost; ///< obecny najni�szy koszt doj�cia do w�z�a
	list* prevcity; ///< poprzedni w�ze� w kolejce najkr�tszej drogi
	bool qs; ///< zmienna reprezentuje przenoszenie w�z�a do zbioru ju� przeszukanych
	list* plprev; ///< wska�nik na poprzedni w�ze� w kolejce
	list* plnext; ///< wska�nik na nast�pny w�ze� w kolejce
	list* forwcity; ///< wska�nik na nast�pny w�ze� w kolejce przy wyznaczaniu najkr�tszej drogi
};
#endif