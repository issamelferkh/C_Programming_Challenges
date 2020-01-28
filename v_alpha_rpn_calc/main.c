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

/*
check nbr of digit vs nbr of op
calcule -> not yet
*/
#include "ft_rpn_calc.h"

int ft_check(char *str) {
    int i = 0;

    while (str[i]) {
        if ( ft_isspace(str[i]) || ft_isdigit(str[i]) || ft_isop(str[i]) )
            i++;
        else
            return(0);
    }
    return (1);
}

int ft_isspace(char c) {
    return (c == ' ' || c == '\t');
}

int ft_isdigit(char c) {
    return (c >= '0' && c <= '9');
}

int ft_isop(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int ft_nbr_word(char *str) {
    int i = 0, flag = 0, nbr = 0;

    while (str[i]) {
        if (ft_isspace(str[i])) {
            i++;
            flag = 0;
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

char *ft_cat_word(char *str, int *id) {
    int i = 0, i_f = 0, i_l = 0;
    char *word;
    
    i = *id;
    while (str[i] && ft_isspace(str[i]))
        i++;
    i_f = i;
    while (str[i] && !(ft_isspace(str[i])))
        i++;
    i_l = i;
    *id = i;
    word = (char * )malloc(sizeof(char) * (i_l - i_f + 1));
    i = 0;
    while (i_l > i_f) {
        word[i] = str[i_f];
        i_f++;
        i++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str) {
    int id = 0, i = 0;
    char **tab;

    tab = (char **)malloc(sizeof(char *) * (ft_nbr_word(str) + 1));
    while(str[id]) {
        tab[i] = ft_cat_word(str,&id);
        i++;
    }
    tab[i] = 0;
    return(tab);
}

int ft_rpn_calc(char *str) {
    char **calc;

    calc = ft_split(str); //test
    return (0);
}

int main(int ac, char **av) {
    if (ac == 2) {
        if (ft_check(av[1]) == 0) {
            printf("Error\n");
            return (0);
        }
        printf("%d",ft_rpn_calc(av[1]));
    } else {
        printf("Error\n");
    }
    return (0);
}

