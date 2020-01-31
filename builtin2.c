/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** the sequel-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int msetenv(char **splitted, char **envp[], char *li)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len1 = 0;
    int len2 = 0;
    int pos = -5;
    char **arg = my_str_to_word_array(li);
    char **rsl = copy(*envp, 2, &pos);

    if (rsl == NULL || pos == -5)
        return 84;
    for (; arg[i] != NULL && my_strcmp(arg[i], splitted[2]) != 0; i++);
    for (; splitted[2][len1] != '\0'; len1 += 1);
    for (; arg[(i + 1)] != NULL && arg[(i + 1)][len2] != '\0'; len2 += 1);
    rsl[pos] = (char *)malloc((len1 + len2 + 2) * sizeof(char));
    rsl[pos][(len1 + len2 + 1)] = '\0';
    for (; splitted[2][j] != '\0'; rsl[pos][j] = splitted[2][j], j++);
    rsl[pos][j++] = '=';
    for (; arg[(i + 1)][k] != '\0'; rsl[pos][j++] = arg[(i + 1)][k++]);
    *envp = rsl;
}

int munsetenv(char **splitted, char *envp[])
{
    int i = 0;
    int pos = -5;
    char **rsl = copy(*envp, 1, &pos);

    if (rsl == NULL || pos == -5)
        return 84;
    for (; rsl[i] != NULL && my_strcmp(rsl[i], splitted[2]) != 0; i++);
}

int menv(char **splitted, char *envp[])
{}

int mexit(char **splitted, char *envp[])
{}