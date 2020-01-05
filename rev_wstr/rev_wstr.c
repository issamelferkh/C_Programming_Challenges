/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:44:13 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/05 17:44:33 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Write Prog: print string reversed taled as a parameter
// Word => space || tab
// OK			if argc != 2 => print '\n'
// Input => Str with spaces at the beginning and end 
// Output => Str rev with exactly one space
//
// Issue => if space in the beg of the str -> print space !

#include <unistd.h>
#include <stdio.h>

int	ft_putlast(char *str, int len) {
	int i = 0;

	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	//printf("len1 est ===> %d\n",len);
	while (i <= len && str[len-i] != ' ' && str[len-i] != '\t')
		i++;
	//printf("i    est ===> %d\n",i);
	write (1,str+len-i+1,i);
	//write(1,"\n",1);
	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	//printf("len2 est ===> %d\n",len);*/
	if (i < len)
		write (1," ",1);
	return (len-i);

}

int main(int ac, char **av) {
	int len = 0;

	if (ac == 2) {
		while (av[1][len])
			len++;
		len--;
		//printf("len0 est ===> %d\n",len);
		while (len > 0)
			len = ft_putlast(av[1], len);
	}
	write (1,"\n",1);
	return (0);
}
