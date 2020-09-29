/** @file */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/**Funkcja sprawdza poprawnoœæ parametrów programu.
@param argc iloœæ przyjmowanych parametrów z konsoli
@param argv[] wartoœci parametrów
@param f1 nazwa pliku wejœciowego mapy
@param f2 nazwa pliku wejœciowego zadanych tras
@param f3 nazwa pliku wyjœciowego znalezionych tras
@result Funkcja zwraca TRUE kiedy któryœ z prze³¹czników jest wadliwy, a FALSE jeœli prze³¹czniki zosta³y podpiête prawid³owo.*/
bool switches(int argc, char* argv[], string* f1, string* f2, string* f3);

/**Funkcja sk³adowa funkcji dijkstra2, która wyszukuje pierwszy wierzcho³ek ze zbioru nieprzeszukanych wierzcho³ków.
@param plhead g³owa kolejki
@result Funkcja zwraca wskaŸnik na wyszukany element kolejki.*/
list* searchfirstfalse(list* plhead);

/**Funkcja sk³adowa funkcji dijkstra2, która wyszukuje element o najmniejszym koszcie dojœcia ze zbioru nieprzeszukanych elementów.
@param plpointer wskaŸnik na pierwszy element ze zbioru nieprzeszukanych elementów w kolejce
@result Funkcja zwraca adres elementu kolejki ze zbioru nieprzeszukanych o najmniejszym koszcie dojœcia.*/
list* searchthelowest(list* plpointer);

/**Funkcja sk³¹dowa funkcji dijkstra2, która odpowiada za relaksacje najkrótszych œcie¿ek.
@param plhead g³owa kolejki
@param plpointer wskaŸnik na wêze³, z którego bêd¹ pobierane kolejne krawêdzie grafu*/
void cnv(list* plhead, list* plpointer);

/**Funkcja odpowiadaj¹ca za realizacjê Algorytmu Dijkstry,w tym przenoszenia ze zbioru "do przeszukania" do zbioru "przeszukanych".
@param phead g³owa listy, w której zwarty jest graf
@param ptail ogon listy
@param plhead g³owa kolejki
@param pltail ogon kolejki
@param arrival wêze³ pocz¹tkowy trasy
@param destination wêze³ koñcowy trasy*/
void dijkstra2(node* phead, node* ptail, list*& plhead, list*& pltail, const string& arrival, const string& destination);

/**Funkcja sprawdzaj¹ca najkrótsz¹ trasê.
@param plarr wskaŸnik na wêze³ pocz¹tkowy trasy
@param pldest wskaŸnik na wêze³ koñcowy trasy
@result Funkcja zwraca TRUE jeœli trasa jest niemo¿liwa do wyznaczenia, a FALSE jeœli uda³o siê wyznaczyæ trasê.*/
bool correctroute(list* plarr, list* pldest);

/**Funkcja sk³adowa funkcji printroute, drukuj¹ca najkrótsz¹ trasê do pliku.
@param file3 plik wyjœciowy z wyznaczonymi trasami
@param plpointer wskaŸnik na obecny element najkrótszej trasy w kolejce
@param plnextp wskaŸnik na nastêpny element najkrótszej trasy w kolejce*/
void printroute(ofstream& file3, list* plpointer, list* plnextp);

/**Funkcja drukuj¹ca trasê do pliku.
@param file3 plik wyjœciowy z wyznaczonymi trasami
@param plarr wêze³ pocz¹tkowy
@param pldest wêze³ koñcowy*/
void printsol(ofstream& file3, list* plarr, list* pldest);

/**Funkcja sprawdzaj¹ca poprawnoœæ pliku mapy.
@param file plik wejœciowy mapy
@param phead g³owa listy wêz³ów (grafu)
@param ptail ogon listy wêz³ów
@result Funkcja zwraca TRUE jeœli plik z mapami zosta³ wczytany poprawnie, albo FALSE jeœli nie uda³o siê go wczytaæ.*/
bool load(ifstream& file, node*& phead, node*& ptail);

/**Funkcja odpowiadaj¹ca za odczyt z pliku zadanych tras oraz stwierdzenie jego poprawnoœci, uruchamia te¿ Algorytm Dijkstry i wpisuje do pliku wyjœciowego.
@param file2 plik wejœciowy z zadanymi trasami
@param file3 plik wyjœciowy z wyznaczonymi trasami
@param phead g³owa listy wêz³ów(grafu)
@param ptail ogon listy wêz³ów
@param plhead g³owa kolejki
@param pltail ogon kolejki
@result Funkcja zwraca TRUE jeœli plik z zadanymi trasami zosta³ wczytany poprawnie, albo FALSE jeœli nie uda³o siê go wczytaæ.*/
bool load2(ifstream& file2, ofstream& file3, node*& phead, node*& ptail, list*& plhead, list*& pltail);
#endif