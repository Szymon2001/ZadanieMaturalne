#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void ile_parzystych(fstream & plik, fstream & plik2)
{
    plik.open("Liczby.txt",ios::in);
    plik2.open("zadanie6.txt",ios::out);
    int ile_parzystych=0;
    while(!plik.eof())
    {
        string linia;
        getline(plik,linia);
        if(linia[linia.size()-1]=='0')
            ile_parzystych++;
    }
    plik2<<"a) Liczb parzystych: "<<ile_parzystych<<endl;
    plik.close();
    plik2.close();
}

void najwieksza_liczba(fstream & plik, fstream & plik2)
{
    plik.open("Liczby.txt",ios::in);
    plik2.open("zadanie6.txt",ios::out | ios::app);
    long long najwieksza_dec=0;
    string najwieksza_bin;
    long long zamieniona=0;
    long long tymczasowa;
    long long podstawa = 1;
    while(!plik.eof())
    {
        string linia;
        getline(plik,linia);
        tymczasowa = stoll(linia);
        while(tymczasowa)
        {
            int koncowa_cyfra = tymczasowa%10;
            tymczasowa/=10;
            zamieniona+=koncowa_cyfra*podstawa;
            podstawa*=2;
        }
        if(zamieniona>najwieksza_dec)
        {
            najwieksza_dec = zamieniona;
            najwieksza_bin = linia;
        }
        zamieniona=0;
        podstawa=1;
    }
    plik2<<"b) najwieksza liczba w pliku: ";
    plik2<<"binarnie: "<<najwieksza_bin<<" dziesietnie: "<<najwieksza_dec<<endl;

    plik.close();
    plik2.close();
}

void ile_liczb_ma9cyfr(fstream & plik, fstream & plik2)
{
    plik.open("Liczby.txt",ios::in);
    plik2.open("zadanie6.txt",ios::out | ios::app);
    int ile_liczb_ma9cyfr=0;
    long long suma=0;
    long long tymczasowa;
    long podstawa=1;
    long long zamieniona=0;
    while(!plik.eof())
    {
        string linia;
        getline(plik,linia);
        if(linia.size()==9)
        {
            ile_liczb_ma9cyfr++;
            tymczasowa = stoll(linia);
            while(tymczasowa)
            {
                int koncowa_cyfra = tymczasowa%10;
                tymczasowa/=10;
                zamieniona+=koncowa_cyfra*podstawa;
                podstawa*=2;
            }
                suma+=zamieniona;
                zamieniona=0;
                podstawa=1;
        }
    }
    short wynik[20];
    int i=0;
    while(suma>0)
    {
        wynik[i] = suma%2;
        suma/=2; i++;
    }
    int maks = i;
    plik2<<"c) Ilosc liczb, ktora ma 9 cyfr: "<<ile_liczb_ma9cyfr<<" Ich suma binarnie: ";
    for(int i=maks-1; i>=0; i--)
        plik2<<wynik[i];
    plik.close();
    plik2.close();
}


int main()
{
    fstream plik,plik2;

    ile_parzystych(plik,plik2);
    najwieksza_liczba(plik,plik2);
    ile_liczb_ma9cyfr(plik,plik2);

    plik.close();
    return 0;
}

