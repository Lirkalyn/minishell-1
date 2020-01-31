/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** h-desu
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char c);
int myputstr(char *str, int opt);
int my_puterror(char *str, int opt);
int my_put_nbr(int nb);
int cd_checker(char *pathname);
int choose(char *line);
int lenght(char *str);
char **spliter(char *str, char **splitterd);
int cd(char **splitted, char *envp[]);
int msetenv(char **splitted, char **envp[], char **arg);
int munsetenv(char **splitted, char **envp[]);
int menv(char **splitted, char *envp[]);
int mexit(char **splitted, char *envp[]);
char **copy(char *envp[], int add, int *pos);
char **my_str_to_word_array(char const *str);
int my_strcmp(char const *s1, char const *s2);
int prefork(char *envp[], char **splitted, char **arg);
int forking(char **splitted, char **arg, char *path, char *envp[]);
char *pathmaker(char *start, char *end);
int exe_checker(char *pathname);
char **arg_checker(char **arg);

#endif
