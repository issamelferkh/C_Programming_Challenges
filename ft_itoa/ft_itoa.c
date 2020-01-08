/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:39:12 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/08 15:39:13 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // for test
#include <limits.h> // for test 

char	*ft_itoa(int nbr) {
    char *str, c;
    int i = 0, j = 0, flag = 0;

    str = (char*)malloc(sizeof(char) * 100);    
    if (nbr == -2147483648) {
        str = "-2147483648";
        return (str);
    } else if (nbr < 0) {
        str[i] = '-';
        i++;
        nbr = -nbr;
        flag = 1;
    }

    while (nbr > 0) {
        str[i] = nbr % 10 + 48;
        nbr = nbr / 10;
        i++;
    }
    i--;
    if (flag == 1)
        j++;
    while (str[j] && j < i) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i--;
        j++;
    }
    return (str);
}

int main () { // for test
    printf("===>%s\n",ft_itoa(-247483648));
    printf("INT MAX: %d\n",INT_MAX);
    printf("INT MIN: %d\n",INT_MIN);
    return (0);
}