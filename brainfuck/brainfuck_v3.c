/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:35:30 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/29 19:35:32 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    brainfuck(char *av) {
    int i = 0, j = 0, flag;
    int *pointer;

    pointer = (int*)malloc(sizeof(int) * 4097);

    while (i < 4096) {
        pointer[i] = 0;
        i++;
    }
    i = 0;
    while (av[i]) {
        av[i] == '>' ? j++ : 0;
        av[i] == '<' ? j-- : 0;
        av[i] == '+' ? pointer[j]++ : 0;
        av[i] == '-' ? pointer[j]-- : 0;
        av[i] == '.' ? write(1,&pointer[j],1) : 0;
        if (av[i] == '[' && !pointer[j]) {
            i++;
            flag = 1;
            while (flag) {
                av[i] == '[' ? flag++ : 0;
                av[i] == ']' ? flag-- : 0;
                i++;
            }
        }
        if (av[i] == ']' && pointer[j]) {
            i--;
            flag = 1;
            while (flag) {
                av[i] == ']' ? flag++ : 0;
                av[i] == '[' ? flag-- : 0;
                i--;
            }
        }
        i++;
    }

}
int main (int ac, char **av) {
    if (ac > 1) {
        brainfuck(av[1]);
    } else {
        write(1,"\n",1);
    }
    return (0);
}