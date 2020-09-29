/** @file */
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/**Funkcja dodaje w�z�y grafu do kolejki wed�ug kt�rej odczytana zostanie najkr�tsza trasa.
@param plcity g�owa kolejki
@param pltail ogon kolejki*/
void addtolist(node* plcity, list*& plhead, list*& pltail);

/**Funkcja wyszkuje dany element w kolejce.
@param plhead g�owa kolejki
@param plcity dany element grafu
@result Funkcja zwraca adres danego elementu kolejki.*/
list* searchinlist(list* plhead, const string& plcity);

/**Funkcja kasuje kolejk�.
@param plhead g�owa kolejki
@param ptail ogon kolejki*/
void deletelist(list*& plhead, list*& pltail);

/**Funkcja resetuje kolejk� do stanu bezpo�rednio po wpisaniu do niej grafu.
@param plhead g�owa kolejki*/
void resetlist(list* plhead);
#endif