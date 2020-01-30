/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 11:50:10 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/19 11:50:11 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rpn_calc.h"

int     ft_isspace(char c) {
    return (c == ' ' || c == '\t');
}

int     ft_cntword(char *str) {
    int nbr = 0, i = 0, flag = 0;

    while (str[i]) {
        if (ft_isspace(str[i])) {
            flag = 0;
            i++;
        } else {
            if (flag == 0)
                nbr++;
            flag = 1;
            i++;
        }
    }
    return (nbr);
}

char    *ft_catword(char *str, int *index) {
    char *word;
    int i = 0, i_f = 0, i_l = 0;

    i = *index;
    while (str[i] && ft_isspace(str[i]))
        i++;
    i_f = i;
    while (str[i] && !(ft_isspace(str[i])))
        i++;
    i_l = i;
    *index = i;
    word = (char*)malloc(sizeof(char) * (i_l - i_f + 1));
    i = 0;
    while (i_f < i_l) {
        word[i] = str[i_f];
        i_f++;
        i++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str) {
    char **tab;
    int index = 0, j = 0;

    tab = (char**)malloc(sizeof(char*) * (ft_cntword(str) + 1));
    while (j < ft_cntword(str)) {
        tab[j] = ft_catword(str, &index);
        j++;
    }
    
    tab[j] = 0;
    return (tab);
}

int	ft_isop(char *c)
{
	return (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/' || c[0] == '%');
}

int	ft_isnbr(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void ft_rpn_calc(char *str) {
    int nbr[1024], i = 0, j = 0, x = 0;
    char **rpn;

    rpn = ft_split(str);
    while (rpn[i]) {
        if (ft_isnbr(rpn[i])) {
            nbr[j] = atoi(rpn[i]);
            j++;
        } else if (ft_isop(rpn[i])) {
            printf("nbr[%d - 1] = %d",j,nbr[j -1]);
            printf("nbr[%d - 2] = %d",j,nbr[j -2]);    
            if (j > 1) {
                rpn[i][0] == '+' ? x = nbr[j-2] + nbr[j-1] : 0;
                rpn[i][0] == '-' ? x = nbr[j-2] - nbr[j-1] : 0;
                rpn[i][0] == '*' ? x = nbr[j-2] * nbr[j-1] : 0;
                rpn[i][0] == '/' ? x = nbr[j-2] / nbr[j-1] : 0;
                rpn[i][0] == '%' ? x = nbr[j-2] % nbr[j-1] : 0;
                j = j-2;
                nbr[j] = x;
                j++;
            } else {
                printf("Error\n");
                return ;
            }
        }
        i++;
    }
    if (!rpn[i] && j != 1) {
        printf("Error\n");
    } else {
        printf("%d\n",x);
    }
}

int main (int ac, char **av) {
    if (ac == 2) {
        ft_rpn_calc(av[1]);
    } else {
        printf("Error\n");
    }
    return (0);
}