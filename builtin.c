/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** built-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int cd_checker(char *pathname)
{
    int test = 0;

    if (access(pathname, F_OK) != 0)
        test += 1;
    else {
/*        if (access(pathname, R_OK) != 0)
            test += 1;
        if (access(pathname, W_OK) != 0)
            test += 1;*/
        if (access(pathname, X_OK) != 0)
            test += 1;
    }
    return test;
}

char *pathmaker(char *start, char *end)
{
    int len1 = 0;
    int len2 = 0;
    char *rsl;
    int i = 0;
    int j = 0;
    int nb[3] = {[0 ... 2] = 0};

    for (; start[i] != '\0' && nb[1] >= 0; i++)
        nb[0] += (start[i] == '/') ? 1 : 0;
    for (; end[len2] != '\0'; len2 += 1)
        nb[1] += (end[len2] == '.' && end[(len2 + 1)] == '.'
                    && end[(len2 + 1)] == '/') ? 1 : 0;
    for (; start[len1] != '\0' && nb[2] != (nb[0] - nb[1]); len1 += 1)
        nb[2] += (start[(len1 + 1)] == '/') ? 1 : 0;
    rsl = (char *)malloc((len1 + len2 + 2) * sizeof(char));
    rsl[(len1 + len2 + 1)] = '\0';
    for (i = 0; i < len1; rsl[i] = start[i], i++);
    rsl[i++] = '/';
    for (j += (3 * nb[1]); end[j] != '\0'; rsl[i] = end[j], i++, j++);
    return rsl;
}

int cd(char **splitted)
{
    int ok = 0;
    char *start = NULL;
    char *path = NULL;

//    start = getcwd(NULL, 0);
//    printf("1 = %s\n", start);
    if (splitted[2][0] != '/') {
        start = getcwd(NULL, 0);
        path = pathmaker(start, splitted[2]);
        splitted[2] = path;
    }
    if (cd_checker(splitted[2]) == 0)
        chdir(splitted[2]);
    else if (cd_checker(splitted[2]) != 0) {
        myputstr(splitted[2], 2);
        myputstr(": Permission denied", 0);
    }
//    start = getcwd(NULL, 0);
//    printf("2 = %s\n", start);
}