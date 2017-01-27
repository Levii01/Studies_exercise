#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>
#include <limits>
#include <fstream>
#include <iomanip>

using namespace std;

#define N 5
#define D 1
#define G 20
#define X 0
#define Y 100


static int A[N][N];	/* tablica A */
static int B[N][N];	/* tablica B */


int wczytajLosowe(int (*tab)[N], int w, int d, int g)
{
	int i = 0;

	if (g < d)
		return -1;
	else if (g == d) {
		while (i < w) {
			int j = 0;
			while (j < N) {
				tab[i][j] = 0;
				++j;
			}
		}
		++i;
	} else {
		while (i < w) {
			int j = 0;
			while (j < N) {
				tab[i][j] = d + rand() % (g - d + 1);
				++j;
			}
			++i;
		}
	}
	return 0;
}

void wypisz(int (*tab)[N], int w, string naglowek)
{
	if (!naglowek.empty())
		cout << naglowek << endl;
	int i = 0;
	while (i < w) {
		int j = 0;
		cout << "\t";
		while (j < N) {
			cout << setw(20) << tab[i][j];
			++j;
		}
		cout << endl;
		++i;
	}
}

int manipuluj(int (*tab)[N], int w, int kolumna)
{
	int min = numeric_limits<int>::max();
	int w_min = 0;
	int ilosc = 0;
	int i = 0, j = 0;
	if (kolumna > N - 1)
		return -1;
	//znajdz najmniejszy
	i = 0;
	while(i < N) {
		if (tab[i][kolumna] < min) {
			min = tab[i][kolumna];
			w_min = i;
		}
		++i;
	}

	ilosc = 0;
	i = 0;
	while(i < N) {
		if (tab[i][i] > -10 && tab[i][i] < 10) {
			++ilosc;
		}
		++i;
	}
	j = 0;
	while(j < N) {
		if (tab[w_min][j] > -10 && tab[w_min][j] < 10) {
			++ilosc;
		}
		++j;
	}

	tab[w_min][kolumna] = ilosc;
	return 0;
}


int main(int argc, char* argv[])
{
	int ret;
	int a2, a3, b2, b3;

	//1
    cout << "Krok 1\n";
	srand(time(0));
	ret = wczytajLosowe(A, N, D, G);
	if (ret != 0) {
		cout << "\tBlad wczytywania liczb losowych do tablicy A " << endl;
		exit(EXIT_FAILURE);
	}
	ret = wczytajLosowe(B, N, X, Y);
	if (ret != 0) {
		cout << "\tBlad wczytywania liczb losowych do tablicy B" << endl;
		exit(EXIT_FAILURE);
	}

	//2
    cout << "Krok 2\n";
	wypisz(A, N, "\tTablica A");
	wypisz(B, N, "\tTablica B");

	//3
    cout << "Krok 3\n";
	ret = manipuluj(A, N, 2);
	if (ret != 0) {
		cout << "\tBlad manipulacji tablicy A" << endl;
		exit(EXIT_FAILURE);
	}
	wypisz(A, N, "\tTablica A (zmieniona)");

	ret = manipuluj(B, N, N - 1);
	if (ret != 0) {
		cout << "\tBlad manipulacji tablicy B" << endl;
		exit(EXIT_FAILURE);
	}
	wypisz(B, N, "\tTablica B (zmieniona)");

    return 0;
}
