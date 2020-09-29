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

/**Funkcja dodaje wierzcho�ek grafu.
@param distance waga kraw�dzi
@param city1 w�ze� pocz�tkowy kraw�dzi
@param city2 w�ze� pocz�tkowy kraw�dzi
@param phead pocz�tek listy mieszcz�cej graf
@param ptail koniec listy mieszcz�cej graf*/
void addnode(const type distance, const string& city1, const string& city2, node*& phead, node*& ptail);

/**Funkcja sk�adowa funkcji addnode, kt�ra dodaje wierzcho�ek grafu na koniec listy.
@param city w�ze� grafu
@param ptail ogon listy*/
void addendnode(const string& city, node*& ptail);

/**Funkcja dodaje kraw�d� grafu, po��czon� z odpowiednimi w�z�ami.
@param distance waga kraw�dzi
@param peback w�ze� pocz�tkowy kraw�dzi
@param peforw w�ze� ko�cowy kraw�dzi
@param pehead pocz�tek listy kraw�dzi danego w�z�a*/
void addedge(const type distance, node*& peback, node*& peforw, edge*& pehead);

/**Funkcja wyszukuje wierzcho�ek w grafie.
@param phead pierwszy element listy
@param city szukany element listy
@result Funkcja zwraca adres danego elementu w li�cie.*/
node* searchnode(node* phead, const string& city);

/**Funkcja usuwa list� kraw�dzi danego w�z�a.
@param pehead pocz�tek listy kraw�dzi*/
void deletealledges(edge*& pehead);

/**Funkcja usuwa list� w�z��w.
@param phead g�owa listy w�z��w
@param ptail ogon listy w�z��w*/
void deleteallnodes(node*& phead, node*& ptail);
#endif