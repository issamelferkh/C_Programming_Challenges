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
//
// if av[1] => just spaces or tabs ?
// if av[1] => one word
// fix prob => ./a.out "abc" | cat -e -> abcab$ ?!!!
// other tests

#include <unistd.h>
#include <stdio.h>

int	ft_putlast(char *str, int len) {
	int i = 0;

	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	while (i <= len && str[len-i] != ' ' && str[len-i] != '\t')
		i++;
	write (1,str+len-i+1,i);
	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	if (i < len)
		write (1," ",1);
	return (len-1);

}

int main(int ac, char **av) {
	int len = 0;

	if (ac == 2) {
		while (av[1][len])
			len++;
		len--;
		while (len)
			len = ft_putlast(av[1], len);
	}
	write (1,"\n",1);
	return (0);
}
