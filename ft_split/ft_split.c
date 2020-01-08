/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:03:57 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/08 17:03:58 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // for test

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
    word[i] = '\n';
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

int main (int ac, char **av) { //for test
    char   **tab;

    tab = ft_split(av[1]);
    printf("%s\n",tab[0]);
    return (0);
}