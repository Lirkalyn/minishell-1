/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** smaller-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int exe_checker(char *pathname)
{
    int test = 0;

    if (access(pathname, F_OK) != 0)
        test += 1;
    else {
        if (access(pathname, R_OK) != 0)
            test += 1;
        if (access(pathname, X_OK) != 0)
            test += 1;
    }
    return test;
}

char **arg_checker(char **arg)
{
    char **tmp = arg;

    if (tmp[0][0] == '\0')
        tmp[0] = NULL;
    if (tmp[1][0] == '\0')
        tmp[1] = NULL;
    if (tmp[2][0] == '\0')
        tmp[2] = NULL;
    return tmp;
}