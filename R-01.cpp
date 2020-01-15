#include <iostream> //Entrada y salida en consola

using namespace std;

bool hasLetter(char letter, char array1[9], char array2[9]);
void printArray(char array[9]);
bool compareArrays(char array1[9], char array2[9]);

int main(void)
{
    char word[9] = {'c', 'o', 'd', 'i', 'f', 'i', 'c', 'a', 'r'};
    char aux[9];

    for (int i = 0; i < 9; i++)
    {
        aux[i] = '_';
    }

    char letter;
    int attempts = 13;

    cout << "La palabra contiene nueve letras" << endl;

    do
    {
        cout << "Digite una letra: ";
        cin >> letter;
        cout << endl;

        cout << "Turnos restantes: " << attempts << "\t";

        if (hasLetter(letter, word, aux) == true)
        {
            cout << "La palabra si contiene la letra " << endl;
        }
        else
        {
            attempts--;
            cout << "La palabra no contiene la letra" << endl;
        }

        printArray(aux);
        if (compareArrays(word, aux) == true)
        {
            cout << "Has adivinado la palabra" << endl;
            return 0;
        }

        cout << endl;
        cout << endl;

    } while (attempts > 0);

    cout << "Lo siento, has perdido";

    return 0;
}

bool hasLetter(char letter, char array1[9], char array2[9])
{
    bool flag = false;
    for (int i = 0; i < 9; i++)
    {
        if (array1[i] == letter)
        {
            flag = true;
            array2[i] = letter;
        }
    }
    return flag;
}

void printArray(char array[9])
{
    for (int i = 0; i < 9; i++)
    {
        cout << array[i] << "\t";
    }
}

bool compareArrays(char array1[9], char array2[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }

    return true;
}