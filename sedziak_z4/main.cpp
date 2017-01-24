#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
const int N=8, D=2, G=7;
int liczba, sum=0, iloczyn=0, max;

// a)

  cout << "Program wczyta " << N << " liczb calkowitych i poda srednia liczb zawartych w przedziale <" << D << ", " << G << ">." << endl;
  cout << "Wprowadz liczby: " << endl << endl;

  for(int i=1; i<=N; i++)
  {

    cout << i << ". ";
    cin >> liczba;

    if((liczba>=D) && (liczba<=G))
    {
      sum+=liczba;
      iloczyn++;
    }
  }

  if(iloczyn!=0)
    cout << endl << "Srednia z przedzialu <" << D << ", " << G << "> = " << (double)sum/iloczyn << endl;
  else
    cout << "\nNIE WPROWADZONO liczb z przedziału <" << D << ", " << G << ">." << endl;

    cout << endl;


// b)

int tab[N];

  cout << endl<< "Wprowadz ponownie ciag " << N << " liczb calkowitych. Program obliczy roznice miedzy kazda liczba a najwieksza z wprowadzonych." << endl;
  cout << "Wprowadz liczby: "<< endl;

  for(int i=0; i<N; i++)
  {
    cout << i+1 << ". ";
    cin >> tab[i];

    max = tab[0];
    if(tab[i]>max)
      max=tab[i];
  }

  cout << endl;
  for(int i=0; i<N; i++)
  {
     if(max<0)
      cout << "\t" << tab[i] << " - (" << max << ") = " << tab[i]-max << endl;
     else
      cout << "\t" << tab[i] << " - " << max << " = " << tab[i]-max << endl;
  }

    cout << endl;

// c)

int temp;

  for (int i=0, j=N-1; i<j; i++, j--)
  {
   temp=tab[i];
   tab[i]=tab[j];
   tab[j]=temp;
  }

  cout << endl << "Odwrocona kolejnosc ciagu:" << endl;
  for(int i=0; i<N; i++)
    cout << i+1 << ". " << tab[i] << endl;

  return 0;
}
