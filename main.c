#include <stdio.h>
#include <string.h>

void moveNumbersToAnotherArray(char *firstArray, char *secondArray);
unsigned short int doesItContainsSpecialChar(char *firstArray);
unsigned short int calculateFirstRealVerifyingDigit(char *cpfArray);
unsigned short int calculateSecondRealVeryfingDigit(char *cpfArray);
unsigned short int areDigitsValids(unsigned short int fRealVerifyingDigit, unsigned short int sRealVerifyingDigit, unsigned char firstInputDigit, unsigned char secondInputDigit);

int main(void) 
{
    char cpfInput[16], cpfNumbers[12];

    printf("Por favor, digite o CPF que será validado: ");
    fgets(cpfInput, 15, stdin);

    unsigned short int doesCpfContainsSpecialChars = doesItContainsSpecialChar(cpfInput);
    unsigned short int firstRealVerifyingDigit = 0, secondRealVerifyingDigit = 0;
    unsigned short int areValids = 0, fInputDigit = 0, sInputDigit = 0;

    if (doesItContainsSpecialChar)
    {
        moveNumbersToAnotherArray(cpfInput, cpfNumbers);
        firstRealVerifyingDigit = calculateFirstRealVerifyingDigit(cpfNumbers);
        secondRealVerifyingDigit = calculateSecondRealVeryfingDigit(cpfNumbers);
        fInputDigit = cpfNumbers[9];
        sInputDigit = cpfNumbers[10];
        areValids = areDigitsValids(firstRealVerifyingDigit, secondRealVerifyingDigit, fInputDigit, sInputDigit);
    }
    else {
        firstRealVerifyingDigit = calculateFirstRealVerifyingDigit(cpfInput);
        secondRealVerifyingDigit = calculateSecondRealVeryfingDigit(cpfInput);
        fInputDigit = cpfNumbers[10];
        sInputDigit = cpfNumbers[11];
        areValids = areDigitsValids(firstRealVerifyingDigit, secondRealVerifyingDigit, fInputDigit, sInputDigit);
    }

    if (!areValids)
    {
        printf("\nO CPF digitado é inválido!.\n");
        printf("\t=> Dígito esperado pelos cálculos realizados: %d%d\n\t=> Dígito que foi encontrado no CPF digitado: %d%d\n", firstRealVerifyingDigit, secondRealVerifyingDigit, fInputDigit - '0', sInputDigit - '0');
    }
    else 
        printf("\nO CPF digitado é válido!.\n");


}

void moveNumbersToAnotherArray(char *firstArray, char *secondArray)
{
    unsigned short int secArrayCounter = 0;

    for (unsigned short int counter = 0; counter < strlen(firstArray); counter++)
    {
        if (firstArray[counter] != '.' && firstArray[counter] != '-')
        {
            secondArray[secArrayCounter] = firstArray[counter];
            secArrayCounter++;
        }
    }
}

unsigned short int doesItContainsSpecialChar(char *firstArray)
{
    unsigned int isItSpecialChar = 0;

    for (unsigned int counter = 0; counter < strlen(firstArray); counter++)
    {
        if (firstArray[counter] == '.' || firstArray[counter] == '-')
            isItSpecialChar = 1;
    }

    return isItSpecialChar;
}

unsigned short int calculateFirstRealVerifyingDigit(char *cpfArray)
{
    unsigned short int digitsSum = 0;
    unsigned short int auxCounter = 10;

    for (unsigned short int counter = 0; counter < 9; counter++)
    {
        digitsSum += (cpfArray[counter] - '0') * auxCounter;
        auxCounter -= 1;
    }

    unsigned short int rest = digitsSum % 11;
    unsigned short int realVerifyingDigit = rest < 2 ? 0 : 11 - rest;

    return realVerifyingDigit;
}

unsigned short int calculateSecondRealVeryfingDigit(char *cpfArray)
{
    unsigned short int digitsSum = 0;
    unsigned short int auxCounter = 11;

    for (unsigned short int counter = 0; counter < 10; counter++)
    {
        digitsSum += (cpfArray[counter] - '0') * auxCounter;
        auxCounter -= 1;
    }

    unsigned short int rest = digitsSum % 11;
    unsigned short int realVerifyingDigit = rest < 2 ? 0 : 11 - rest;
}

unsigned short int areDigitsValids(unsigned short int fRealVerifyingDigit, unsigned short int sRealVerifyingDigit, unsigned char firstInputDigit, unsigned char secondInputDigit)
{
    unsigned short int areValids = 0;

    if (fRealVerifyingDigit == firstInputDigit - '0' && sRealVerifyingDigit == secondInputDigit - '0')
        areValids = 1;

    return areValids;
}