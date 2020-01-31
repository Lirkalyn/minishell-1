/*
** EPITECH PROJECT, 2020
** mathstick
** File description:
** stick-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char **copy(char *envp[], int add, int *pos)
{
    int i = 0;
    int len = 0;
    char **rsl;

    for (len = 0; envp[len] != NULL; len++);
    rsl = (char **)malloc((len + add) * sizeof(char *));
    if (rsl == NULL)
        return NULL;
    *pos = len;
    rsl[len + (add - 1)] = NULL;
    for (i = 0; envp[i] != NULL; i++) {
        for (len = 0; envp[i][len] != '\0'; len++);
        rsl[i] = (char *)malloc((len + 1) * sizeof(char));
        if (rsl[i] == NULL)
            return NULL;
        rsl[i][len] = '\0';
        for (int j = 0; envp[i][j] != '\0'; rsl[i][j] = envp[i][j], j++);
    }
    return rsl;
}

int main(int argc, char *argv[], char *envp[])
{
    char *li/*ne*/ = NULL;
    size_t si/*ze*/;
    char **split = (char **)malloc(3 * sizeof(char *));

    if (myputstr("$>", 1) || (getline(&li, &si, stdin) == -1) || split == NULL)
        return 84;
    split = spliter(li, split);
    choose(split[0]);
    //cd(split, envp);
    //msetenv(split, &envp, li);
/*    printf("%s\n", split[0]);
    printf("%s\n", split[1]);
    printf("%s\n", split[2]);*/
    //printf("iii = %d\n", choose(split[0]));
//    access(const char *pathname, int mode);
/*    for (int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);*/
}