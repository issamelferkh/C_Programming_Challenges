/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:44:13 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/06 08:38:03 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char*	ft_strrev(char *str) {
	char *tmp1;
	int i = 0, j = 0;

	while (str[i])
		i++;
	i--;
	tmp1 = (char*)malloc(sizeof(char) * i + 1);
	while (str[i]) {
		tmp1[j] = str[i];
		i--;
		j++;
	}
	tmp1[j] = '\0';
	return (tmp1);
}

char*	ft_strtrim(char *str) {
	char *tmp2;
	int i = 0, j = 0;

	while (str[i])
		i++;
	tmp2 = (char*)malloc(sizeof(char) * i);
	i = 0;
	while (str[i]) {
		if ((str[i]== ' ' || str[i] == '\t') && j == 0) {
			i++;
		}
		else {
			tmp2[j] = str[i];
			i++;
			j++;
		}
	}
	tmp2[j] = '\0';
	return (tmp2);
}

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
	return (len-i);

}

int main(int ac, char **av) {
	int len = 0;

	if (ac == 2) {
		av[1] = ft_strtrim(av[1]);
		av[1] = ft_strrev(av[1]);
		av[1] = ft_strtrim(av[1]);
		av[1] = ft_strrev(av[1]);
		while (av[1][len])
			len++;
		len--;
		while (len > 0)
			len = ft_putlast(av[1], len);
	}
	write (1,"\n",1);
	return (0);
}
