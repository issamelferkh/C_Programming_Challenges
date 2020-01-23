/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:15:50 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/23 16:15:52 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // for test

int ft_isbrack(char c) {
    return (c == '(' || c == '[' || c == '{');
}

int ft_is_not_brack(char c) {
    return (c == ')' || c == ']' || c == '}');
}

int ft_match(char a, char b) {
    if (a == '(' && b == ')')
        return (1);
    if (a == '[' && b == ']')
        return (1);
    if (a == '{' && b == '}')
        return (1);
    return (0);
}

int ft_brack(char *str) {
    int i = 0, b = 0;
    char tab[4096] = {0};

    while (str[i]) {
        if (ft_isbrack(str[i])) {
            tab[b] = str[i];
            b++;
        }
        if (ft_is_not_brack(str[i])) {
            b--;
            if (!ft_match(tab[b],str[i])) {
                return (0);
            }
        }
        i++;
    }
    return (1);
}

int main(int ac, char **av) {
    int i = 0;

    if (ac > 1)
    while (av[++i]) {
        ft_brack(av[i]) == 1 ? write(1,"OK",2):write(1,"Error",5);
        write(1,"\n",1);    
    } else {
        write(1,"\n",1);
    }
    return (0);
}
