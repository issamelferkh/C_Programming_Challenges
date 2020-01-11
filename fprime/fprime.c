/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:25:52 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/11 08:25:53 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for test
#include <unistd.h>
#include <stdlib.h> // for test

int     ft_atoi(char *str) {
    int i = 0, n = 0;

    while (str[i]) {
        n = n * 10 + str[i] - 48;
        i++;
    }
    return (n);
}

void    ft_putnbr(int n) {
    char c;

    if (n > 9) {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    if (n >= 0 && n <= 9) {
        c = n % 10 + 48;
        write (1,&c,1);
    }
}

int main (int ac, char **av) {
    int nbr, i = 2, flag = 0;
    
    if (ac == 2) {
        nbr = ft_atoi(av[1]);
        while (nbr > 0 && i <= nbr) {
            while (nbr % i == 0){
                flag = 1;
                ft_putnbr(i);
                nbr = nbr / i;
                if (i <= nbr)
                    write (1,"*",1);
            }
            i++;
        }
        if (flag == 0)
            ft_putnbr(nbr);
    }
    write (1,"\n",1);
    return (0);
}
