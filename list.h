/** @file */
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/**Funkcja dodaje wêz³y grafu do kolejki wed³ug której odczytana zostanie najkrótsza trasa.
@param plcity g³owa kolejki
@param pltail ogon kolejki*/
void addtolist(node* plcity, list*& plhead, list*& pltail);

/**Funkcja wyszkuje dany element w kolejce.
@param plhead g³owa kolejki
@param plcity dany element grafu
@result Funkcja zwraca adres danego elementu kolejki.*/
list* searchinlist(list* plhead, const string& plcity);

/**Funkcja kasuje kolejkê.
@param plhead g³owa kolejki
@param ptail ogon kolejki*/
void deletelist(list*& plhead, list*& pltail);

/**Funkcja resetuje kolejkê do stanu bezpoœrednio po wpisaniu do niej grafu.
@param plhead g³owa kolejki*/
void resetlist(list* plhead);
#endif