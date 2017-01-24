#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>

using namespace std;


int main()
{
    char znak_stopu;
    unsigned int litery_male = 0, litery_wielkie = 0;
	char znak, znak_poprzedni;
	unsigned int amp_count = 0;

    //1
    while (!(cout << "\tPodaj znak stopu (cyfry od 0 do 9) :\t", cin.get(znak_stopu) && isdigit(znak_stopu))) {
        if (znak_stopu != 0x0a)
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
        cout << "\tBlad! Prosze podac cyfre 0-9" << endl;
    }
    cout << "\tZnak stopu to " << znak_stopu << endl;

    //2
    cin.clear();
	cin.ignore(1);
	znak_poprzedni = 0x32;
	do {
		while (!(cout << "\tPodaj mala lub wielka litere, " << znak_stopu << " <= koniec programu\t", cin.get(znak) && isprint(znak))) { /* wczytuj tak dlugo az sukces */
			if (znak != 0x0a)
				cin.ignore();
			cin.clear();
			cout << "\tBlad! Tylko znaki drukowalne." << endl;
		}
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (isalpha(znak)) {
			if (islower(znak))
				++litery_male;
			else
				++litery_wielkie;
		}
		if (znak == '&' && znak_poprzedni == '&')
			++amp_count;
		znak_poprzedni = znak;
		cout.flush();
	} while (znak != znak_stopu);

    //3
    cout << "Liter malych " << litery_male <<"\n";
    cout << "Liter wielkich " << litery_wielkie <<"\n";
	if (litery_wielkie > litery_male)
		cout << "Liter wielkich bylo wiecej" << endl;
	else if (litery_wielkie < litery_male)
		cout << "Liter wielkich bylo mniej" << endl;
	else
		cout << "Liter wielkich bylo tyle samo co malych" << endl;
	cout << "Ampersandow przyleglych " << amp_count << endl;
    return 0;
}
