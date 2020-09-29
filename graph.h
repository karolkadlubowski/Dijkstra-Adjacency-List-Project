/** @file */
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <fstream>

#include "structures.h"
#include "list.h"
#include "functions.h"

using namespace std;

/**Funkcja dodaje wierzcho³ek grafu.
@param distance waga krawêdzi
@param city1 wêze³ pocz¹tkowy krawêdzi
@param city2 wêze³ pocz¹tkowy krawêdzi
@param phead pocz¹tek listy mieszcz¹cej graf
@param ptail koniec listy mieszcz¹cej graf*/
void addnode(const type distance, const string& city1, const string& city2, node*& phead, node*& ptail);

/**Funkcja sk³adowa funkcji addnode, która dodaje wierzcho³ek grafu na koniec listy.
@param city wêze³ grafu
@param ptail ogon listy*/
void addendnode(const string& city, node*& ptail);

/**Funkcja dodaje krawêdŸ grafu, po³¹czon¹ z odpowiednimi wêz³ami.
@param distance waga krawêdzi
@param peback wêze³ pocz¹tkowy krawêdzi
@param peforw wêze³ koñcowy krawêdzi
@param pehead pocz¹tek listy krawêdzi danego wêz³a*/
void addedge(const type distance, node*& peback, node*& peforw, edge*& pehead);

/**Funkcja wyszukuje wierzcho³ek w grafie.
@param phead pierwszy element listy
@param city szukany element listy
@result Funkcja zwraca adres danego elementu w liœcie.*/
node* searchnode(node* phead, const string& city);

/**Funkcja usuwa listê krawêdzi danego wêz³a.
@param pehead pocz¹tek listy krawêdzi*/
void deletealledges(edge*& pehead);

/**Funkcja usuwa listê wêz³ów.
@param phead g³owa listy wêz³ów
@param ptail ogon listy wêz³ów*/
void deleteallnodes(node*& phead, node*& ptail);
#endif