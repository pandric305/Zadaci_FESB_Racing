#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int KriviBroj (char broj[200], int duzina1) {
    int tocan=0, krivi=0, i;
    for (i = 0; broj[i] != '\0'; i++) {
        duzina1--;
        if (broj[i] >= '0' && broj[i] <= '9')
            tocan += 1;
        else if (broj[i] >= 'a' && broj[i] <= 'f')
            tocan += 1;
        else if (broj[i] >= 'A' && broj[i] <= 'F')
            tocan += 1;
        else
            krivi += 1;
    }
    if (krivi >= 1)
        cout << "Pogresan unos!\n";
    return krivi;
}

int RacunanjeBroja (char broj1[200], int duzina2) {
    int c, i, rezultat=0;
    for (i = 0; broj1[i] != '\0'; i++)
    {
        duzina2--;

        if (broj1[i] >= '0' && broj1[i] <= '9')
            c = broj1[i] - 48;
        else if (broj1[i] >= 'a' && broj1[i] <= 'f')
            c = broj1[i] - 87;
        else if (broj1[i] >= 'A' && broj1[i] <= 'F')
            c = broj1[i] - 55;

        rezultat = rezultat + c * pow(16, duzina2);
    }
    return rezultat;
}

int main()
{
    while (true)
    {
        int duzina, rezultat = 0;
        int KrivoSlovo;
        char b[200];
        cout << "Unesite broj u heksadecimalnom zapisu:\n";
        cin >> b;
        duzina = strlen(b);
        KrivoSlovo = KriviBroj(b,duzina);
           
        if (KrivoSlovo == 0) {
            rezultat = RacunanjeBroja(b, duzina);
            cout << "Decimalni broj broja: " << b << " je: " << rezultat << "\n";
        }
    }
    return 1;
}
