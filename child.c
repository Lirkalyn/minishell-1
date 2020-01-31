/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** small-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return ((s1[i] - s2[i]));
    return (0);
}

char **lister(char *str)
{
    int len = 0;
    int nb = 0;
    char **rsl;

    for (int i = 0; str[i] != '\0'; i++)
        nb += (str[i] == ':') ? 1 : 0;
    rsl = (char **)malloc((nb + 2) * sizeof(char *));
    rsl[(nb + 1)] = NULL;
    for (int i = 0; i < (nb + 1); i++) {
        for (len = 0; str[len] != '\0' && str[len] != ':'; len++);
        rsl[i] = (char *)malloc((len + 1) * sizeof(char));
        rsl[i][len] = '\0';
        for (int pos = 0; str[pos] != '\0' && str[pos] != ':'; pos++)
            rsl[i][pos] = str[pos];
        str = (str + len + 1);
    }
    return rsl;
}

int cmd_finder(char **dirs, char **splitted)
{
    DIR *dir;
    struct dirent *dp;
    int len = 0;

    for (; splitted[0][len] != '\0'; len++);
    len++;
    for (int i = 0; dirs[i] != NULL; i++) {
        dir = opendir(dirs[i]);
        while ((dp = readdir(dir)) != NULL)
            if (my_strncmp(dp->d_name, splitted[0], len) == 0) {
                closedir(dir);
                return i;
            }
        closedir(dir);
    }
    return -1;
}

int prefork(char *envp[], char **splitted, char **arg)
{
    int pos = 0;
    char *tmp = NULL;
    char **dirs = NULL;
    char *path;

    for (; envp[pos] != NULL && my_strcmp(envp[pos], "PATH=\0") != 0; pos++);
    if (my_strcmp(envp[pos], "PATH=\0") == 0)
        tmp = (envp[pos] + 5);
    dirs = lister(tmp);
    pos = cmd_finder(dirs, splitted);
    if (pos >= 0) {
        path = pathmaker(dirs[pos], splitted[0]);
        return forking(splitted, arg_checker(splitted), path, envp);
    }
    else {
        myputstr(splitted[0], 2);
        myputstr(": Command not found.", 0);
        return 1;
    }
}

int forking(char **splitted, char **arg, char *path, char *envp[])
{
    char *const argv[] = {path, splitted[1], splitted[2], NULL};
    int c_pid;
    int pid;
    int status;

    if (exe_checker(path) != 0)
        return 1;
    c_pid = fork();
    if (c_pid == 0)
        execve(path, argv, envp);
    else if (c_pid > 0) {
        if ((pid = wait(&status)) < 0) {
            perror("wait");
            exit(1);
        }
    }
    else {
        perror("fork failed");
        exit(2);
    }
}