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
int ft_piece(char c){
    return (c == 'P' || c == 'R' || c == 'B' || c == 'Q');
}

int ft_pawn(char **av, int y, int x) {
    return((av[y-1][x-1] && av[y-1][x-1] == 'K') || (av[y-1][x+1] && av[y-1][x+1] == 'K'));
}

int ft_Rook(char **av, int y, int x) {
    int j, i;

    j = y;
    i = 0;
    while (av[j][i]) {
        if (av[j][i] && av[j][i] == 'K')
            return (1);
        i++;
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
            if (av[j][i] == 'R' && ft_Rook(av, j, i) && (!ft_piece(av[j][i])))
                return (1);
            // if (av[j][i] == 'B' && ft_Bishop(av, j, i))
            //     return (1);
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