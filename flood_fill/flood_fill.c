/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:42:09 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/23 15:42:11 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void    my_ff(char **tab, char color, t_point size, int x, int y) {
    if (x < 0 || y < 0)
        return ;
    if (x >= size.x || y >= size.y)
        return ;
    if (color != tab[x][y])
        return ;
    tab[x][y] = 'F';
    my_ff(tab, color, size, x + 1, y);
    my_ff(tab, color, size, x - 1, y);
    my_ff(tab, color, size, x, y + 1);
    my_ff(tab, color, size, x, y - 1);
}

void    flood_fill(char **tab, t_point size, t_point begin) {
    my_ff(tab, tab[begin.x][begin.y], size, begin.x, begin.y);
}
