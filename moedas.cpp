#include <iostream>

using namespace std;

int obterFormasPossiveis(int moedas[], int cents)
{
    if (cents < 0)
    {
        return 0;
    }
    int contadorPossibilidades[cents + 1] = {};
    contadorPossibilidades[0] = 1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = moedas[i]; j <= cents; ++j)
        {
            contadorPossibilidades[j] += contadorPossibilidades[j - moedas[i]];
        }
    }
    
    return contadorPossibilidades[cents];
}

int main(int argc, char *argv[])
{
    int moedas[] = {1, 5, 10, 25};
    int cents;
    
    cout << "Entre os centavos que voce quer: ";
    cin >> cents;
    if (cents == 0)
    {
        cout << "Existe 0 formas possiveis de representar " << cents;
    }
    else
    {
        cout << "Existem " << obterFormasPossiveis(moedas, cents) << " formas de representar " << cents;
    }

    return 0;
}