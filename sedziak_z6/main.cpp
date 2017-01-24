#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

int main()
{

const int n=5;
int k=0;            //indeks kolumny do zamiany z przekatna
int i, j;
double A[n][n];

// wczytaj dane z pliku do tablicy A

    std::fstream plik_we;
    std::string nazwa_pliku_we;

    do
    {
        std::cout << "Podaj nazwe pliku: ";
        std::cin >> nazwa_pliku_we;

        plik_we.open(nazwa_pliku_we.c_str(), std::ios::in);
        if(!plik_we)
            std::cerr << "Blad pliku. Sprobuj ponownie.\n\n";
    }while(!plik_we);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            plik_we >> A[i][j];
    plik_we.close();

// drukuj tablice wierszami

    for(i=0; i<n; i++)
    {
        std::cout << "\n\n\n";
        for(j=0; j<n; j++)
            std::cout << std::setw(12) << std::fixed << std::setprecision(2) << A[i][j];
    }
    std::cout << "\n\n";

// zamien miejscami glowna przekatna z kolumna k

    double temp;
    for(i=0; i<n; i++)
    {
        temp=A[i][k];
        A[i][k]=A[i][i];
        A[i][i]=temp;
    }

// przesun komorki nad glowna przekatna cyklicznie o 1 w prawo

    for(i=0; i<n-1; i++)
    {
        temp=A[i][n-1];             // zapamietaj ostatnia komorke
        for(j=n-1; j>i+1 ;j--)
            A[i][j]=A[i][j-1];      // zamieniaj od konca
        A[i][i+1]=temp;             // pierwsza nad przekatna = zapamietana ostatnia
    }

// zapisz tablice do pliku

    std::fstream plik_wy;

    plik_wy.open("wynik.txt", std::ios::out);
    if(!plik_wy.good())
    {
        std::cerr << "Blad zapisu do pliku.\n\n";
        return 1;
    }

    for(i=0; i<n; i++)
    {
        plik_wy << "\n\n\n";
        for(j=0; j<n; j++)
            plik_wy << std::setw(12) << std::fixed << std::setprecision(2) << A[i][j];
    }
    plik_wy.close();

    std::cout << "\n\n";

    return 0;
}

