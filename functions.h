/** @file */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/**Funkcja sprawdza poprawno�� parametr�w programu.
@param argc ilo�� przyjmowanych parametr�w z konsoli
@param argv[] warto�ci parametr�w
@param f1 nazwa pliku wej�ciowego mapy
@param f2 nazwa pliku wej�ciowego zadanych tras
@param f3 nazwa pliku wyj�ciowego znalezionych tras
@result Funkcja zwraca TRUE kiedy kt�ry� z prze��cznik�w jest wadliwy, a FALSE je�li prze��czniki zosta�y podpi�te prawid�owo.*/
bool switches(int argc, char* argv[], string* f1, string* f2, string* f3);

/**Funkcja sk�adowa funkcji dijkstra2, kt�ra wyszukuje pierwszy wierzcho�ek ze zbioru nieprzeszukanych wierzcho�k�w.
@param plhead g�owa kolejki
@result Funkcja zwraca wska�nik na wyszukany element kolejki.*/
list* searchfirstfalse(list* plhead);

/**Funkcja sk�adowa funkcji dijkstra2, kt�ra wyszukuje element o najmniejszym koszcie doj�cia ze zbioru nieprzeszukanych element�w.
@param plpointer wska�nik na pierwszy element ze zbioru nieprzeszukanych element�w w kolejce
@result Funkcja zwraca adres elementu kolejki ze zbioru nieprzeszukanych o najmniejszym koszcie doj�cia.*/
list* searchthelowest(list* plpointer);

/**Funkcja sk��dowa funkcji dijkstra2, kt�ra odpowiada za relaksacje najkr�tszych �cie�ek.
@param plhead g�owa kolejki
@param plpointer wska�nik na w�ze�, z kt�rego b�d� pobierane kolejne kraw�dzie grafu*/
void cnv(list* plhead, list* plpointer);

/**Funkcja odpowiadaj�ca za realizacj� Algorytmu Dijkstry,w tym przenoszenia ze zbioru "do przeszukania" do zbioru "przeszukanych".
@param phead g�owa listy, w kt�rej zwarty jest graf
@param ptail ogon listy
@param plhead g�owa kolejki
@param pltail ogon kolejki
@param arrival w�ze� pocz�tkowy trasy
@param destination w�ze� ko�cowy trasy*/
void dijkstra2(node* phead, node* ptail, list*& plhead, list*& pltail, const string& arrival, const string& destination);

/**Funkcja sprawdzaj�ca najkr�tsz� tras�.
@param plarr wska�nik na w�ze� pocz�tkowy trasy
@param pldest wska�nik na w�ze� ko�cowy trasy
@result Funkcja zwraca TRUE je�li trasa jest niemo�liwa do wyznaczenia, a FALSE je�li uda�o si� wyznaczy� tras�.*/
bool correctroute(list* plarr, list* pldest);

/**Funkcja sk�adowa funkcji printroute, drukuj�ca najkr�tsz� tras� do pliku.
@param file3 plik wyj�ciowy z wyznaczonymi trasami
@param plpointer wska�nik na obecny element najkr�tszej trasy w kolejce
@param plnextp wska�nik na nast�pny element najkr�tszej trasy w kolejce*/
void printroute(ofstream& file3, list* plpointer, list* plnextp);

/**Funkcja drukuj�ca tras� do pliku.
@param file3 plik wyj�ciowy z wyznaczonymi trasami
@param plarr w�ze� pocz�tkowy
@param pldest w�ze� ko�cowy*/
void printsol(ofstream& file3, list* plarr, list* pldest);

/**Funkcja sprawdzaj�ca poprawno�� pliku mapy.
@param file plik wej�ciowy mapy
@param phead g�owa listy w�z��w (grafu)
@param ptail ogon listy w�z��w
@result Funkcja zwraca TRUE je�li plik z mapami zosta� wczytany poprawnie, albo FALSE je�li nie uda�o si� go wczyta�.*/
bool load(ifstream& file, node*& phead, node*& ptail);

/**Funkcja odpowiadaj�ca za odczyt z pliku zadanych tras oraz stwierdzenie jego poprawno�ci, uruchamia te� Algorytm Dijkstry i wpisuje do pliku wyj�ciowego.
@param file2 plik wej�ciowy z zadanymi trasami
@param file3 plik wyj�ciowy z wyznaczonymi trasami
@param phead g�owa listy w�z��w(grafu)
@param ptail ogon listy w�z��w
@param plhead g�owa kolejki
@param pltail ogon kolejki
@result Funkcja zwraca TRUE je�li plik z zadanymi trasami zosta� wczytany poprawnie, albo FALSE je�li nie uda�o si� go wczyta�.*/
bool load2(ifstream& file2, ofstream& file3, node*& phead, node*& ptail, list*& plhead, list*& pltail);
#endif