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

int choice(char **envp[], char **splitted, char **arg)
{
    switch (choose(splitted[0]))
    {
        case 0:
            return cd(splitted, *envp);
        case 1:
            if (splitted[2][0] == '\0')
                return menv(splitted, *envp);
            else
                return msetenv(splitted, envp, arg);
        case 2:
            return munsetenv(splitted, envp);
        case 3:
            return menv(splitted, *envp);
        case 4:
            return mexit(splitted, *envp);
        default:
        break;
    }
}

int main(int argc, char *argv[], char *envp[])
{
    char *line = NULL;
    size_t size;
    char **arg = NULL;
    char **splitted = (char **)malloc(3 * sizeof(char *));

    while (1) {
        myputstr("$>", 1);
        if ((getline(&line, &size, stdin) == -1) || splitted == NULL)
            return 84;
        arg = my_str_to_word_array(line);
        splitted = spliter(line, splitted);
        choice(&envp, splitted, arg);
//        test = choose(split[0]);
/*        if (test == 0)
            cd(split, envp);
        else if (test == 1)
            if (split[2][0] == '\0')
                menv(split, envp);
            else
                msetenv(split, &envp, arg);
        else if (test == 2)
            munsetenv(split, &envp);
        else if (test == 3)
            menv(split, envp);
        else if (test == 4)
            mexit(split, envp);*/
    /*    printf("%s\n", split[0]);
        printf("%s\n", split[1]);
        printf("%s\n", split[2]);*/
        //printf("iii = %d\n", choose(split[0]));
    //    access(const char *pathname, int mode);
    /*    for (int i = 0; envp[i] != NULL; i++)
            printf("%s\n", envp[i]);*/
    }
}