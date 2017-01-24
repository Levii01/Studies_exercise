#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

    void count_length(int nums)
    {
    if(abs(nums)<10)
        cout<< "jednocyfrowa";
    else if(abs(nums)<100)
         cout<< "dwucyfrowa";
    else
        cout<< "Inna";
    }

int main()
{
    string name;
    char sex;
    int a, b;

    //1.
    cout << "Podaj imie: \t";
    cin >> name;
    cout << "Podane imie to: " << name << endl;

    //2.
    while
        (!(cout << "Podaj plec (K,k,M,m) \t",
        cin >> sex && ( sex == 'K'|| sex == 'k'|| sex == 'M'|| sex == 'm' )));

        cout << "\nPodana plec to: " << sex << endl;

    //3.
    cout << name << ", witam "<< ((sex == 'k' || sex=='K')? "Pania" : "Pana") << endl;

    //4.
    cout << "Podaj dwie liczby calkowite (moga byc ujemne): ";
    while(!(cin >> a >> b))
            {cin.clear();
            cin.ignore( numeric_limits < streamsize >::max(), '\n' );
            cout << "Blad! Prosze podac liczbe calkowita: ";
            }
    //5.
    cout<< "Pierwsza liczba to: " << a << ", dlugosc: ";
    count_length(a);
    cout<< "\nDruga liczba to: " << b << " dlugosc: ";
    count_length(b);

    //6.
    cout << "\na/(2*b) = ";
    if (b != 0)
        cout << a / (2*b);
    else
        cout << "Nie dzielimy przez zero!";


    cout << ", dokladna wartosc a/(2*b) = ";
    if (b != 0)
       cout << (double) a / ((double) 2 * b) << endl;
    else
        cout << "Nie dzielimy przez zero!." << endl;
    return 0;
}
