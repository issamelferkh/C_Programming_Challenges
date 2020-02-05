/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:32:59 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/22 18:33:00 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // for test

int     ft_valueof(int nbr) {
    if (nbr >= 0 && nbr <= 9)
        return (48);
    else if(nbr >= 10 && nbr < 16)
        return ('A' - 10);
    else
        return (0);
}

char	*ft_itoa_base(int value, int base) {
    char *str, c;
    int i = 0, j = 0, tmp = 0, flag = 0;

    str = (char*)malloc(sizeof(char) * 100);
    if (value < 0 && base == 10) {
        value = -value;
        flag = 1;
        i++;
    } else if (value < 0){
        value = -value;
    }

    while (value > 0) {
        tmp = value % base;
        str[i] = tmp + ft_valueof(tmp);
        value = value / base;
        i++;
    }
    str[i] = '\0';
    i--;
    if (flag) {
        str[j] = '-';
        j++;
    }

    while (str[i] && j < i) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i--;
        j++;
    }
    return (str);
}

int main(int ac, char **av) // for test 
{
    printf("=>%s\n",ft_itoa_base(-271254,10));
    return (0);
}
