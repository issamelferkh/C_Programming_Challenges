/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:44:13 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/05 00:05:12 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Write Prog: print string reversed taled as a parameter
// Word => space || tab
// OK			if argc != 2 => print '\n'
// Input => Str with spaces at the beginning and end 
// Output => Str rev with exactly one space

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	 }
}

char**	ft_split(char *str)
{
	int i=0, j=0, k=0;
	char **tab;
	
	while (str[i]) {
		if (str[i] != ' ') {
			tab[j][k] = str[i];
			k++;
		}
		else if ((str[i] == ' ') && (str[i+1] != ' ')) {
			j++;
		}
		i++;
	}
	return (tab);
}

int main(int ac, char **av)
{
	int i=0;
	char **tab;
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	tab = ft_split(av[1]);
	while (tab[i]) {
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr(av[1]);
	ft_putchar('\n');
	return (0);
}
