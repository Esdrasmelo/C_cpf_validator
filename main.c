#include <stdio.h>
#include <string.h>

void moveNumbersToAnotherArray(char *firstArray, char *secondArray);
int doesItContainsSpecialChar(char *firstArray);
int calculateFirstRealVerifyingDigit(char *cpfArray);
int calculateSecondRealVeryfingDigit(char *cpfArray);
int areDigitsValids(int fRealVerifyingDigit, int sRealVerifyingDigit, char firstInputDigit, char secondInputDigit);

int main(void) 
{
    char cpfInput[16], cpfNumbers[12];

    printf("Por favor, digite o CPF que será validado: ");
    fgets(cpfInput, 15, stdin);

    int doesCpfContainsSpecialChars = doesItContainsSpecialChar(cpfInput);
    int firstRealVerifyingDigit = 0, secondRealVerifyingDigit = 0;

    if (doesItContainsSpecialChar)
    {
        moveNumbersToAnotherArray(cpfInput, cpfNumbers);
        firstRealVerifyingDigit = calculateFirstRealVerifyingDigit(cpfNumbers);
        secondRealVerifyingDigit = calculateSecondRealVeryfingDigit(cpfNumbers);
        int areValids = areDigitsValids(firstRealVerifyingDigit, secondRealVerifyingDigit, cpfNumbers[9], cpfNumbers[10]);

        if (!areValids) printf("\nO CPF digitado é inválido!.\n");
        else printf("\nO CPF digitado é válido!.\n");
    }
    else {
        firstRealVerifyingDigit = calculateFirstRealVerifyingDigit(cpfInput);
        secondRealVerifyingDigit = calculateSecondRealVeryfingDigit(cpfInput);
        int areValids = areDigitsValids(firstRealVerifyingDigit, secondRealVerifyingDigit, cpfInput[10], cpfInput[11]);

        if (!areValids) printf("\nO CPF digitado é inválido!.\n");
        else printf("\nO CPF digitado é válido!.\n");
    }
}

void moveNumbersToAnotherArray(char *firstArray, char *secondArray)
{
    int secArrayCounter = 0;

    for (int counter = 0; counter < strlen(firstArray); counter++)
    {
        if (firstArray[counter] != '.' && firstArray[counter] != '-')
        {
            secondArray[secArrayCounter] = firstArray[counter];
            secArrayCounter++;
        }
    }
}

int doesItContainsSpecialChar(char *firstArray)
{
    int isItSpecialChar = 0;

    for (int counter = 0; counter < strlen(firstArray); counter++)
    {
        if (firstArray[counter] == '.' || firstArray[counter] == '-')
            isItSpecialChar = 1;
    }

    return isItSpecialChar;
}

int calculateFirstRealVerifyingDigit(char *cpfArray)
{
    int digitsSum = 0;
    int auxCounter = 10;

    for (int counter = 0; counter < 9; counter++)
    {
        digitsSum += (cpfArray[counter] - '0') * auxCounter;
        auxCounter -= 1;
    }

    int rest = digitsSum % 11;
    int realVerifyingDigit = rest < 2 ? 0 : 11 - rest;

    return realVerifyingDigit;
}

int calculateSecondRealVeryfingDigit(char *cpfArray)
{
    int digitsSum = 0;
    int auxCounter = 11;

    for (int counter = 0; counter < 10; counter++)
    {
        digitsSum += (cpfArray[counter] - '0') * auxCounter;
        auxCounter -= 1;
    }

    int rest = digitsSum % 11;
    int realVerifyingDigit = rest < 2 ? 0 : 11 - rest;
}

int areDigitsValids(int fRealVerifyingDigit, int sRealVerifyingDigit, char firstInputDigit, char secondInputDigit)
{
    int areValids = 0;

    if (fRealVerifyingDigit == firstInputDigit - '0' && sRealVerifyingDigit == secondInputDigit - '0')
        areValids = 1;

    return areValids;
}