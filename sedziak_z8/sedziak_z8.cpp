#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>
#include <limits>
#include <fstream>
#include <iomanip>

using namespace std;

#define W 2
#define K 2
#define plik1 "file1.txt"
#define plik2 "file2.txt"

static int A[W][K];
static int B[W][K];


int wczytaj(string nazwaPliku, int (*tab)[K], int w)
{
	ifstream in(nazwaPliku.c_str());
	if (nazwaPliku.empty() || !in)
		return -1;

	int i = 0;
	while (i < w) {
		int j = 0;
		while (j < K) {
			if (!(in >> tab[i][j]))
				return -2;
			++j;
		}
		++i;
	}
	in.close();
	return 0;
}

void wypisz(int (*tab)[K], int w, string naglowek)
{
	cout << naglowek << endl;
	int i = 0;
	while (i < w) {
		int j = 0;
		cout << "\t";
		while (j < K) {
			cout << "[" << tab[i][j] << "]";
			++j;
		}
		cout << endl;
		++i;
	}
}

int iloscPodzNaObwodzie(int dzielnik, int (*tab)[K], int w)
{
	int ilosc = 0;
	int i = 0, j = 0;
	while (j < K) {
		if (tab[0][j] % dzielnik == 0)
			++ilosc;
		++j;
	}
	j = 0;
	if (w > 1) {
		while (j < K) {
			if (tab[w - 1][j] % dzielnik == 0)
				++ilosc;
			++j;
		}
	}
	i = 1;
	if (w > 2) {
		while (i < w - 1) {
			if (tab[i][0] % dzielnik == 0)
				++ilosc;
			if (K > 1 && (tab[i][K - 1] % dzielnik == 0))
				++ilosc;
		++i;
		}
	}
	return ilosc;
}


int main(int argc, char* argv[])
{
	int ret;
	int a2, a3, b2, b3;

	//1
    cout << endl;
	ret = wczytaj(plik1, A, W);
	if (ret != 0) {
		cout << "\tBlad wczytywania pliku " << plik1 << endl;
		exit(EXIT_FAILURE);
	}
	ret = wczytaj(plik2, B, W);
	if (ret != 0) {
		cout << "\tBlad wczytywania pliku " << plik2 << endl;
		exit(EXIT_FAILURE);
	}

	//2
    cout << endl;
	wypisz(A, W, "\tTablica A");
	wypisz(B, W, "\tTablica B");

	//3
    cout << endl;
	a2 = iloscPodzNaObwodzie(2, A, W);
	b2 = iloscPodzNaObwodzie(2, B, W);
	a3 = iloscPodzNaObwodzie(3, A, W);
	b3 = iloscPodzNaObwodzie(3, B, W);
	if (a2 > b2)
		cout << "\tWiecej liczb podzielnych przez 2 na obwodzie ma tablica A (" << a2 << ")";
	else if (b2 > a2)
		cout << "\tWiecej liczb podzielnych przez 2 na obwodzie ma tablica B (" << b2 << ")";
	else
		cout << "\tObie tablice maja po rowno (" << a2 << ") liczb podzielnych przez 2 na obwodzie";
	cout << endl;
	if (a3 > b3)
		cout << "\tWiecej liczb podzielnych przez 3 na obwodzie ma tablica A (" << a3 << ")";
	else if (b3 > a3)
		cout << "\tWiecej liczb podzielnych przez 3 na obwodzie ma tablica B (" << b3 << ")";
	else
		cout << "\tObie tablice maja po rowno (" << a3 << ") liczb podzielnych przez 3 na obwodzie";

    return 0;
}
