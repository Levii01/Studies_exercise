#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>
#include <limits>
#include <sstream>

using namespace std;


/* max ilosc dodatkowych slow */
#define N 3

static void usage(const char *name)
{
    if (name) {
        cout << "\tUsage:\t" << name << endl;
    }
    exit(EXIT_FAILURE);
}

/* zwraca 1 jesli pierwszy i ostatni znak sa takie same, 0 w p.p */
int is_first_last_chars_same(string s)
{
	return s.empty() ? 0 : (s[0] == s[s.size() - 1] ? 1 : 0);
}

void str_process(string s, string::size_type &min_len, size_t &same_chars_count, size_t &str_count)
{
	if (s.size() < min_len)
		min_len = s.size();
	same_chars_count += is_first_last_chars_same(s);
	++str_count;
}

int main()
{
	string line, str;
	string stop = "end";
	string::size_type	str_min_len = numeric_limits<string::size_type>::max();
	size_t	str_count = 0, str_first_last_chars_same_count = 0;

    //1
    cout << "Krok 1\n";
	do {
		while (!(cout << "\t\nPodaj slowo (by zakonczyć => end):\t", getline(cin, line))) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cout << "\tBlad! Prosze podac slowo/a rozdzielone bialym znakiem " << endl;
		}
		istringstream iss(line);
		while (iss >> str) {
			if (str == stop)
				goto step_2;
			/* zliczamy */
			str_process(str, str_min_len, str_first_last_chars_same_count, str_count);
		}
	} while (1);

step_2:
    //2
    cout << "Krok 2\n";
	cout << "Mozesz teraz podac " << N << " slow (" << stop << " <= by zakonczyc)\n";
	for (int i = 0; i < N; ++i) {
		while (!(cout << "\t\nPodaj slowo :\t", getline(cin, line))) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cout << "\tBlad! Podaj slowo/a rozdzielone bialym znakiem" << endl;
		}
		istringstream iss(line);
		while (iss >> str) {
			if (str == stop)
				goto step_3;
			/* zliczamy */
			str_process(str, str_min_len, str_first_last_chars_same_count, str_count);
		}
	}

step_3:
    //3
    cout << "Krok 3\n";
	cout << "Wczytano " << str_count << " slow.\n";
	if (str_count > 0) {
		cout << "Slowa z tymi samymi znakami na poczatku i koncu: " << str_first_last_chars_same_count << "\n";
		cout << "Dlugosc najkrotszego slowa: " << str_min_len << endl;
	} else {
		cout << "Brak danych do wyswietlenia." << endl;
	}
    return 0;
}
