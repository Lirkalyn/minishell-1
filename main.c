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

char **copy(char *envp[])
{
    int i = 0;
    int len = 0;
    char **rsl;

    for (len = 0; envp[len] != NULL; len++);
    rsl = (char **)malloc((len + 1) * sizeof(char *));
    if (rsl == NULL)
        return NULL;
    rsl[len] = NULL;
    for (i = 0; envp[i] != NULL; i++) {
        for (len = 0; envp[i][len] != '\0'; len++);
        rsl[i] = (char *)malloc((len + 1) * sizeof(char));
        if (rsl == NULL)
            return NULL;
        rsl[i][len] = '\0';
        for (int j = 0; envp[i][j] != '\0'; rsl[i][j] = envp[i][j], j++);
    }
    return rsl;
}

int main(int argc, char *argv[], char *envp[])
{
    //char **env2 = copy(envp);
    char *li/*ne*/ = NULL;
    size_t si/*ze*/;
    char **splited = (char **)malloc(3 * sizeof(char *));

    if (/*env2 == NULL || */myputstr("$>", 1) || (getline(&li, &si, stdin) == -1) || splited == NULL)
        return 84;
    splited = spliter(li, splited);
    choose(splited[0]);
    cd(splited);
/*    printf("%s\n", splited[0]);
    printf("%s\n", splited[1]);
    printf("%s\n", splited[2]);*/
    //printf("iii = %d\n", choose(splited[0]));
//    access(const char *pathname, int mode);
/*    for (int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);*/
}