#include <iostream> //Entrada y salida en consola

using namespace std;

bool hasLetter(char letter, char *array1, char *array2, int sizeArray);
void printArray(char *array, int sizeArray);
bool compareArrays(char *array1, char *array2, int sizeArray);

int main(void)
{
    int size = 0;
    char *word;
    char *aux;
    char saveLetter;

    cout << "Tamaño de la palabra: ";
    cin >> size;

    word = new char[size];
    aux = new char[size];

    cout << "Digite la palabra: ";
    for (int i = 0; i < size; i++)
    {
        cin >> saveLetter;
        word[i] = saveLetter;
    }

    for (int i = 0; i < 9; i++)
    {
        aux[i] = '_';
    }

    char letter;
    int attempts = size + 3;

    cout << "La palabra contiene" << size << " letras" << endl;

    do
    {
        cout << "Digite una letra: ";
        cin >> letter;
        cout << endl;

        cout << "Turnos restantes: " << attempts << "\t";

        if (hasLetter(letter, word, aux, size) == true)
        {
            cout << "La palabra si contiene la letra " << endl;
        }
        else
        {
            attempts--;
            cout << "La palabra no contiene la letra" << endl;
        }

        printArray(aux, size);
        if (compareArrays(word, aux, size) == true)
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

bool hasLetter(char letter, char *array1, char *array2, int sizeArray)
{
    bool flag = false;
    for (int i = 0; i < sizeArray; i++)
    {
        if (array1[i] == letter)
        {
            flag = true;
            array2[i] = letter;
        }
    }
    return flag;
}

void printArray(char *array, int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        cout << array[i] << "\t";
    }
}

bool compareArrays(char *array1, char *array2, int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }

    return true;
}