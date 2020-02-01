/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:58:12 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/09 09:58:14 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for test
#include <stdlib.h>

char    *ft_strrev(char *str) {
    int i = 0, j = 0;
    char c;

    while (str[i])
        i++;
    i--;
    while (str[j] && j < i) {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
        i--;
        j++;
    }

    return (str);
}

int     ft_value_of(int tmp) {
    if (tmp >= 0 && tmp <= 9)
        return (48);
    else if (tmp >= 10 && tmp < 16)
        return ('A' - 10);
    return (0);
}

char	*ft_itoa_base(int value, int base) {
    char    *str;
    int i = 0, tmp = 0, flag = 0;
    
    if (value < 0 && base == 10) {
        value = -value;
        flag = 1;
    } else if (value < 0) {
        value = -value;
    }
    str = (char*)malloc(sizeof(char) * 100);
    while(value > 0) {
        tmp = value % base ;
        str[i] = tmp + ft_value_of(tmp);
        value = value / base;
        i++;
    }
    if (flag) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    str = ft_strrev(str);
    return (str);
}

int main () { // for test
    printf("ft_itoa_base => %s\n",ft_itoa_base(-271254,16));
    return (0);
}