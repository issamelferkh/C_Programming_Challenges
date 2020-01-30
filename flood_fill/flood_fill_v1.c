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

#include <stdlib.h>
#include <stdio.h>
#include "t_point.h"

void    my_ff(char **tab, char color, int x, int y, int sizex, int sizey) {
    if (x < 0 || y < 0 || x >= sizex || y >= sizey || tab[x][y] != color)
        return ;
    tab[x][y] = 'F';
    my_ff(tab, color, x+1, y, sizex, sizey);
    my_ff(tab, color, x-1, y, sizex, sizey);
    my_ff(tab, color, x, y+1, sizex, sizey);
    my_ff(tab, color, x, y-1, sizex, sizey);
    
}

void    flood_fill(char **tab, t_point size, t_point begin) {
    my_ff(tab, tab[begin.x][begin.y], begin.x, begin.y, size.x, size.y);
}

char **make_area(char **zone, int _x, int _y)
{
	char **area;
	area = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		area[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j)
			area[i][j] = zone[i][2 * j];
	}
	return (area);
}

int main(void)
{
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1"
	};
	t_point size  = {8, 5};
	t_point begin = {2, 2};

	char **area = make_area(zone, size.x, size.y);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", area[y][x]);
		}
		printf("\n");
	}
    printf("\n");
    flood_fill(area, size, begin);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", area[y][x]);
		}
		printf("\n");
	}
	free(area);
	return (0);
}
