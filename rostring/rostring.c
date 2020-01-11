/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 06:54:28 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/11 06:54:30 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for test
#include <unistd.h> 
#include <stdlib.h>

void    ft_putstr(char *str) {
    int i = 0;

    while (str[i])
        write (1,str + i++,1);
}

int     ft_isspace(char c) {
    return (c == 32 || (c > 8 && c < 14));
}

int     ft_nbr_word(char *str) {
    int i = 0, flag = 0, nbr = 0;

    while (str[i]) {
        if (ft_isspace(str[i])) {
            flag = 0;
            i++;
        } else {
            if (flag == 0) {
                flag = 1;
                nbr++;
            }
            i++;
        }
    }
    return (nbr);
}

char    *ft_cat_word(char *str, int *index) {
    int i = 0, i_f = 0, i_l = 0;
    char    *word;

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
        i++;
        i_f++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_splite(char *str) {
    char **tab;
    int index = 0, j = 0;

    tab = (char**)malloc(sizeof(char*) * ft_nbr_word(str) + 1);
    while (j < ft_nbr_word(str)) {
        tab[j] = ft_cat_word(str, &index);
        j++;
    }
    tab[j] = 0;
    return (tab);
}

int main(int ac, char **av) {
    int i = 1;
    char    **tab;

    if (ac > 1) {
        tab = ft_splite(av[1]);
        while (i < ft_nbr_word(av[1])) {
            ft_putstr(tab[i]);
            write(1," ",1);
            i++;
        }
        if (tab[0])
            ft_putstr(tab[0]);
        // printf("ft_nbr_word =>%d\n",ft_nbr_word(av[1]));
        // printf("ft_Split =>%s\n",tab[0]);
    }
    write (1,"\n",1);
    return (0);
}
