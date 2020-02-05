/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_v3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:58:12 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/09 09:58:14 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // for test

char    *ft_strrev(char *str) {
    int i = -1, j = 0;
    char c;

    while (str[++j]) {}
    while (++i < --j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return(str);
}

int     ft_value_of(int n) {
    if (n > -1 && n < 10)
        return (48);
    else if (n > 9 && n < 16)
        return (-10 + 'A');
    return (0);
}

char	*ft_itoa_base(int value, int base) {
    char *str;
    int i = 0, flag = 0;
 
    str = (char *)malloc(sizeof(char) * 100);
    if (value < 0) {
        value = -value;
        if (base == 10)
            flag = 1;
    }
    while (value > 0) {
        str[i] = value % base + ft_value_of(value % base);
        value = value / base;
        i++;
    }
    if (flag)
        str[i++] = '-';    
    str[i] = '\0';
    return (ft_strrev(str));
}

int main () { // for test
    printf("itoa=>%s\n",ft_itoa_base(-251549,16));
    return (0);
}