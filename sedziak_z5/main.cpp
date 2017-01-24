#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <stdlib.h>


using namespace std;

const int w=5, k=12, D=11, G=72;
int A[w][k], tab_parz[k];
int ilosc_parzystych;
int i, j, r, i_min;

void wypelnij_tablice()
{
    cout << "\t\t\t  Kolumn: " << k << ", wierszy: "<< w << ". Przedzial wylosowanych liczb <" << D << "," << G << ">"<< endl;

    srand (time(NULL));
    for(i=0; i<w; i++)
    {
        for(j=0; j<k; j++)
        A[i][j]=D+rand()%(G+1-D);
    }
}

void policz_parzyste_w_kolumnach()
{
    for(i=0; i<k; i++)
    {
        ilosc_parzystych=0;
        for(j=0; j<w; j++)
        {
            if(A[j][i]%2==0)
                ilosc_parzystych++;
        }
        tab_parz[i]=ilosc_parzystych;
    }
}

void kolumny_najmniej_parzystych()
{
// znajdz indeks, pod ktorym jest najmniejsza wartosc
    i_min=tab_parz[0];
    for(i=0; i<k; i++)
        if(tab_parz[i]<tab_parz[i_min])
            i_min=i;
}

void wyswietl_wynik()
{
//wydrukuj tabele

    for(i=0; i<w; i++)
    {
        cout << endl << endl << "\t\t\t";
        for(j=0; j<k; j++)
            cout << setw(4) << A[i][j];
    }

//wydrukuj tabele z iloscia liczb parzystych

    cout << endl << endl << "Ilosc liczb parzystych: ";
    for(i=0; i<k; i++)
        cout << setw(4) << tab_parz[i];


// sprawdz, w ktorych komorkach tabeli z iloscia liczb parzystych sa wartosci rowne minimalnej i wydrukuj

    cout << endl << endl << "\nNajmniej liczb parzystych jest w kolumnach o indeksie: ";

    for(i=0; i<k; i++)
    {
        if(tab_parz[i]==tab_parz[i_min])
        cout << "[ " << i << " ]" ;
    }
}


int main()
{
    cout << "Program wypelnia liczbami losowymi z przedzialu <D, G> tablice A[w][k]." << endl;
    cout << "Drukuje ja wierszami ze stala szerokoscia." << endl;
    cout << "Pod kazda kolumna wyswietla ile jest w niej liczb parzystych." << endl;
    cout << "Drukuje indeksy kolumn, ktore maja najmniej liczb parzystych." << endl << endl;


    wypelnij_tablice();
    policz_parzyste_w_kolumnach();
    kolumny_najmniej_parzystych();
    wyswietl_wynik();

    return 0;
}

