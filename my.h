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
int cd(char **splitted);

#endif
