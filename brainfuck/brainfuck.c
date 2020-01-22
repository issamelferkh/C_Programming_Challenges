/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:54:54 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/22 17:54:55 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

int main (int ac, char **av) {
    char *pointer;
    int i = 0, flag = 0;

    if (ac == 2) {
        pointer = (char*)malloc(sizeof(char) * 4097);
        while (pointer[i])
            pointer[i++] = 0; 
        i = 0;
        while (av[1][i]) {
            av[1][i] == '>' ? pointer++:0;
            av[1][i] == '<' ? pointer--:0;
            av[1][i] == '+' ? *pointer = *pointer + 1:0;
            av[1][i] == '-' ? *pointer = *pointer - 1:0;
            if (av[1][i] == '.')
                write(1,&*pointer,1);
            else if (av[1][i] == '[' && !*pointer) {
                i++;
                flag = 1;
                while (flag != 0) {
                    if (av[1][i] == '[')
                        flag++;
                    else if (av[1][i] == ']')
                        flag--;
                    i++;
                }
            }
            else if (av[1][i] == ']' && *pointer) {
                i--;
                flag = 1;
                while (flag != 0) {
                    if (av[1][i] == '[')
                        flag--;
                    else if (av[1][i] == ']')
                        flag++;
                    i--;
                }
            }
            i++;
        }
    } else
        write(1,"\n",1);
    return (0);
}