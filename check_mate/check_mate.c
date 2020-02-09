/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:33:48 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/25 17:33:50 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int	ft_strlen(char *str) {
	int i = 0;
	while (str[++i]) {}
	return (i);
}

int	ft_piece(char c) {
	return (c == 'Q' || c == 'R' || c == 'B' || c == 'P');
}

int	ft_pawn(char **av, int j, int i) {
	if ((av[j-1][i-1] == 'K' && av[j-1][i-1]) || (av[j-1][i+1] == 'K' && av[j-1][i+1]))
		return (1);
	return (0);
}

int	ft_rook(char **av, int j, int i) {
	int y = j, x = i, len = ft_strlen(av[1]);
	while (++i < len && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	j = y;
	i = x;
	while (--i >= 0 && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	j = y;
	i = x;
	while (++j <= len && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	j = y;
	i = x;
	while (--j > 0 && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	return (0);
}

int	ft_bishop(char **av, int j, int i) {
	int y = j, x = i, len = ft_strlen(av[1]);
	while (++i < len && ++j <= len && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	j = y;
	i = x;
	while (++i < len && --j > 0 && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	j = y;
	i = x;
	while (--i >= 0 && ++j <= len && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	j = y;
	i = x;
	while (--i >= 0 && --j > 0 && !ft_piece(av[j][i])) {
		if (av[j][i] == 'K')
			return (1);
	}
	return (0);
}

int	ft_check_mate(char **av) {
	int j = 1, i;

	while (av[j]) {
		i = 0;
		while (av[j][i]) {
			if (av[j][i] == 'P' && ft_pawn(av,j,i))
				return (1);
			if (av[j][i] == 'R' && ft_rook(av,j,i))
				return (1);
			if (av[j][i] == 'B' && ft_bishop(av,j,i))
				return (1);
			if (av[j][i] == 'Q' && (ft_rook(av,j,i) || ft_bishop(av,j,i)))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int main (int ac, char **av) {
	if (ac > 1) {
		if (ft_check_mate(av))
			write(1,"Success",7);
		else
			write(1,"Fail",4);
	}
	write(1,"\n",1);
	return (0);
}