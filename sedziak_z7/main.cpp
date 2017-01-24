#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

const int n=6;
const int A=1965, B=1980;
const double P=800;

struct moto
{
    std::string marka;
    int rocznik;
    double cena;
};

int main()
{
moto S[n];
char litera='s';        // ostatnia litera marki
int licznik=0;          // ilosc samochodow, ktorych marka konczy sie na 's'
bool jest_litera=false;
double suma=0;

// wczytaj dane z pliku

std::fstream dane_we;
std::string nazwa_pliku_wejsciowego;

    do
    {
        std::cout << "Podaj nazwe pliku z danymi: ";
        std::cin >> nazwa_pliku_wejsciowego;
        dane_we.open(nazwa_pliku_wejsciowego.c_str(), std::ios::in);
        if(!dane_we.good())
            std::cout << "Problem z wczytaniem danych. Spróbuj ponownie.\n\n";
    }while(!dane_we.good());
    std::cout << "\n";

// sprawdzenie pliku i wczytanie

    for(int i=0; i<n; i++)
    {
        dane_we >> S[i].marka >> S[i].rocznik >> S[i].cena;
    }
    dane_we.close();

// wyszukanie roczników A-B i sprawdzenie marek kończących się na 's'

    for(int i=0; i<n; i++)
    {
        if(S[i].marka[S[i].marka.size()-1] == litera)  // jesli ostatnia litera to 'litera'
            if((S[i].rocznik>=A) && (S[i].rocznik<=B)) // i jesli rocznik jest miedzy <A,B>
            {
                licznik++;
                suma+=S[i].cena;
                jest_litera=true;
            }
    }

// jesli marka nie konczyla sie na s, oblicz srednia ze wszystkich

    if(!jest_litera)
    {
        licznik=n;
        for(int i=0; i<n; i++)
        {
            suma+=S[i].cena;
        }
    }

//  tablica

    std::cout << "\n\n";
    for(int i=0; i<n; i++)
    {
        std::cout << std::setw(22) << std::right << "Marka:\t" << S[i].marka << "\n";
        std::cout << std::setw(22) << std::right << "Rocznik:\t" << S[i].rocznik << " r.\n";
        std::cout << std::setw(22) << std::right << std::fixed << std::setprecision(2) << "Cena:\t" << S[i].cena << " zł\n\n";
    }

//    std::cout << "\n\nSrednia z S: " << std::fixed << std::setprecision(2) << suma/licznik << " zł\n";

    for(int i=0; i<n; i++)
    {
        if((S[i].rocznik==2016) && (S[i].cena > suma/licznik+P))
            S[i].cena=S[i].cena-S[i].cena*0.1;
    }

// wyświetlenie tablicy

    std::cout << "\n\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "- Tablica po ewentualnej obnizce rocznika 2016  -\n";
    std::cout << "-------------------------------------------------\n\n";
    for(int i=0; i<n; i++)
    {
        std::cout << std::setw(22) << std::right << "Marka:\t" << S[i].marka << "\n";
        std::cout << std::setw(22) << std::right << "Rocznik:\t" << S[i].rocznik << " r.\n";
        std::cout << std::setw(22) << std::right << std::fixed << std::setprecision(2) << "Cena:\t" << S[i].cena << " zł\n\n";
    }

// zamiana miejsc najdroższy/najtańszy

int i_max=0, i_min=0;

    for(int i=0; i<n; i++)
    {
        if(S[i].cena<S[i_min].cena)
            i_min=i;
        if(S[i].cena>S[i_max].cena)
            i_max=i;
    }
     std::cout << "najdrozszy: " << S[i_max].marka << std::endl;
     std::cout << "najtanszy: " << S[i_min].marka << std::endl;

// zamiana

moto temp;

    temp=S[i_min];
    S[i_min]=S[i_max];
    S[i_max]=temp;

// wydrukuj tablice

    std::cout << "\n\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "-  Zamiana miejscami najdrozszego z najtanszym  -\n";
    std::cout << "-------------------------------------------------\n\n";
    for(int i=0; i<n; i++)
    {
        std::cout << std::setw(22) << std::right << "Marka:\t" << S[i].marka << "\n";
        std::cout << std::setw(22) << std::right << "Rocznik:\t" << S[i].rocznik << " r.\n";
        std::cout << std::setw(22) << std::right << std::fixed << std::setprecision(2) << "Cena:\t" << S[i].cena << " zł\n\n";
    }

    std::cout << "\n\n";
    return 0;
}
