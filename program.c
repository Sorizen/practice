#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#define MAX 100
int Count_symbols(char *str)
{
    int counter_of_symbols = 0; // счетчик
    while(str[counter_of_symbols]) // пока символ в строке не False(0) - добавляем счетчик
        counter_of_symbols++;
    return counter_of_symbols; // Возвращаем колличество символов
}
void Mix(char *str, int counter)
{
    int j, tmp;
    for (int i = counter - 1; i >= 1; i--) //алгоритм фишера-йетса
    {
        j = rand()%(i + 1);
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
    }
    printf("Conversion string: %s", str);
}
void Delete(char *str)
{
    int exception, counter_of_symbols;
    for(int i = 0; i < MAX; i++)
    {
        if (str[i] == ',' || str[i] == '.' || str[i] == ' ' || str[i] == ':' || str[i] == ';' || str[i] == '?' || str[i] == '!' || str[i] == '-' || str[i] == '(' || str[i] == ')' || str[i] == '"')
        {
            exception = 0;
            for(int j = i; j < MAX; j++ )
            {
                str[j] = str[j+1];
                exception = 1;
            }
            if (exception == 1)
                i--;
        }
    }
    counter_of_symbols = Count_symbols(str);
    Mix(str, counter_of_symbols);
}
int main()
{
int number_of_symbols;
char str[MAX];
printf("Enter the string: ");
fgets(str, MAX, stdin);
Delete(str);
sleep(60);
return 0;  
}
