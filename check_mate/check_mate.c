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

#include <unistd.h>
#include <stdlib.h>
int     ft_strlen(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_piece(char c){
    return (c == 'P' || c == 'R' || c == 'B' || c == 'Q');
}

int ft_pawn(char **av, int y, int x) {
    return((av[y-1][x-1] && av[y-1][x-1] == 'K') || (av[y-1][x+1] && av[y-1][x+1] == 'K'));
}

int	ft_rook(char **board, int y, int x)
{
	int	len;
	int	j;

	len = (int)ft_strlen(board[y]);
	j = x;
	while (++j < len && ft_piece(board[y][j]) != 1) //Horizontal++
	{
		if (board[y][j] == 'K')
			return (1);
	}
	j = x;
	while (--j >= 0 && ft_piece(board[y][j]) != 1) //Horizontal--
	{
		if (board[y][j] == 'K')
			return (1);
	}
	j = y;
	while (++j <= len && ft_piece(board[j][x]) != 1) //Vertical--
	{
		if (board[j][x] == 'K')
			return (1);
	}
	j = y;
	while (--j >= 1 && ft_piece(board[j][x]) != 1) //Vertical++
	{
		if (board[j][x] == 'K')
			return (1);
	}
	return (0);
}

int	ft_bishop(char **board, int y, int x)
{
	int	len;
	int	i;
	int	j;

	len = (int)ft_strlen(board[1]);
	i = y;
	j = x;
	while (++i <= len && ++j < len && ft_piece(board[i][j]) != 1) //Down Right
	{
		if (board[i][j] == 'K')
			return (1);
	}
	i = y;
	j = x;
	while (--i >= 1 && --j >= 0 && ft_piece(board[i][j]) != 1) //Down Left
	{
		if (board[i][j] == 'K')
			return (1);
	}
	i = y;
	j = x;
	while (--i >= 1 && ++j < len && ft_piece(board[i][j]) != 1) //Up Right
	{
		if (board[i][j] == 'K')
			return (1);
	}
	i = y;
	j = x;
	while (--i >= 1 && --j >= 0 && ft_piece(board[i][j]) != 1) //Up Left
	{
		if (board[i][j] == 'K')
			return (1);
	}
	return (0);
}

int ft_check_mate(char **av) {
    int i = 0, j = 0;

    while (av[j]) {
        i = 0;
        while (av[j][i]) {
            if (av[j][i] == 'P' && ft_pawn(av, j, i))
                return (1);
            if (av[j][i] == 'R' && ft_rook(av, j, i))
                return (1);
            if (av[j][i] == 'B' && ft_bishop(av, j, i))
                return (1);
            if (av[j][i] == 'Q' && (ft_bishop(av, j, i) || ft_rook(av, j, i)))
                return (1);
            i++;
        }
        j++;
    }
    return (0);
}

int main (int ac, char **av) {
    if(ac > 1) {
        ft_check_mate(av)?write(1,"Success",7):write(1,"Fail",4);
    }
    write(1,"\n",1);
    return (0);
}