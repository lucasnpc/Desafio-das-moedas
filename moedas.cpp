#include <iostream>

using namespace std;

int obterFormasPossiveis(int moedas[], int cents, int contadorPossibilidades)
{
    cout << cents << endl;
    int aux = cents;
    while (aux > 0)
    {
        aux -= moedas[0];
    }

    contadorPossibilidades++;
    for (int i = 0; i < 3; i++)
    {
        if (cents == moedas[i] && i > 0)
        {
            contadorPossibilidades++;
        }
        else if (moedas[i] > 1)
        {
            contadorPossibilidades += cents / moedas[i];
        }
    }
    aux = cents;
    for (int i = 3; i < 0; i++)
    {
        if (moedas[i] < aux)
        {
            aux - moedas[i];
            while (aux > 0)
            {
                aux -= moedas[0];
            }
            if (aux == 0)
            {
                contadorPossibilidades++;
            }
        }
    }

    return contadorPossibilidades;
}

int main(int argc, char *argv[])
{
    int moedas[] = {1, 5, 10, 25};
    int cents;
    int contadorPossibilidades = 0;
    cout << "Entre os centavos que voce quer: ";
    cin >> cents;
    if (cents == 0)
    {
        cout << "Existe 0 formas possiveis de representar " << cents;
    }
    else if (cents == 1)
    {
        cout << "Existe 1 forma possivel de representar " << cents;
    }
    else
    {
        cout << "Existem " << obterFormasPossiveis(moedas, cents, contadorPossibilidades) << " formas de representar " << cents;
    }

    return 0;
}