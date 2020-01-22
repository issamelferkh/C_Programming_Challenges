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

int main (int ac, char **av) {
	char *p;
	int i = 0, flag = 0;

	if (ac == 2) {
		p = (char*)malloc(sizeof(char) * 2048);
		while (i < 2048)
			p[i++] = '\0';
		i = 0;
		while (av[1][i]) {
			av[1][i] == '>' ? p++ : 0;
			av[1][i] == '<' ? p-- : 0;
			av[1][i] == '+' ? *p = *p+1 : 0;
			av[1][i] == '-' ? *p = *p-1 : 0;
			if (av[1][i] == '.') {
				write(1,&*p,1);
			} else if (av[1][i] == '[' && !*p) {
				flag = 1;
				while (flag) {
					i++;
					av[1][i] == '[' ? flag++ : 0;
					av[1][i] == ']' ? flag-- : 0;
				}
			} else if (av[1][i] == ']' && *p) {
				flag = 1;
				while (flag) {
					i--;
					av[1][i] == '[' ? flag-- : 0;
					av[1][i] == ']' ? flag++ : 0;
				}
			}
			i++;
		}
	} else { 
		write(1,"\n",1);
	}
	return (0);
}