/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:16:55 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/21 23:16:56 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE 2048
int			main(int argc, const char *argv[])
{
    int		i;
    int		loop;
    char	*pointer;
    if (argc == 2)
    {
        pointer = malloc(sizeof(char) * 2048);
        i = 0;
        while(i <= 2048)
            pointer[i++]= '\0';
        i = 0;
        while(argv[1][i])
        {
            argv[1][i] == '>' ? pointer++ : 0;
            argv[1][i] == '<' ? pointer-- : 0;
            argv[1][i] == '+' ? *pointer +=1 : 0;
            argv[1][i] == '-' ? *pointer -=1 : 0;
            if (argv[1][i] == '.')
            {
                write(1, &*pointer, 1);
            }
            if (argv[1][i] == '[' && !*pointer)
            {
                loop = 1;
                while(loop)
                {
                    i++;
                    argv[1][i] == '[' ? loop+=1 : 0;
                    argv[1][i] == ']' ? loop-=1 : 0;
                }
            }
            if (argv[1][i] == ']' && *pointer)
            {
                loop = 1;
                while(loop)
                {
                    i--;
                    argv[1][i] == ']' ? loop+=1 : 0;
                    argv[1][i] == '[' ? loop-=1 : 0;
                }
            }
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}