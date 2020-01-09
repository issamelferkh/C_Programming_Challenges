/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 07:07:49 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/09 07:07:50 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for test
#include <stdlib.h> // for test
#include <limits.h> //for test

int ft_isspace(char c) {
    return ((c > 8 && c < 14) || (c == 32));
}

int ft_isvalid(char c, int base) {
    char tab1[16] = "0123456789abcdef", tab2[16] = "0123456789ABCDEF";

    while(base) {
        if (c == tab1[base] || c == tab2[base])
            return (1);
        base--;
    }
    return (0);
}

int ft_value_of(char c) {
    int r = 0;
    if (c >= '0' && c <= '9')
        return (c - 48);
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int	ft_atoi_base(const char *str, int str_base) {
    int i = 0, sig = 1, r = 0;

    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sig = -1;
        i++;
    }
    while (ft_isvalid(str[i], str_base)) {
        r = r * str_base + ft_value_of(str[i]);
        i++;
    }
    return (r * sig);
}

int main (int ac, char **av) {// for test
    printf("ft_atoi_base ===>%d\n",ft_atoi_base(av[1],atoi(av[2])));
    printf("INT MAX ===> %d\n",INT_MAX);
    printf("INT MIN ===> %d\n",INT_MIN);
    return (0);
}
