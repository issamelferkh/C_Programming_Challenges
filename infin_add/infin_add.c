/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:40:54 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/02/11 18:40:59 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// error test 5 and 7
// ft_sub not yet

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str) {
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

// void    ft_sub(char *n1, char *n2) { 
// }

void    ft_add(char *n1, char *n2) {
    int l1 = ft_strlen(n1), l2 = ft_strlen(n2), i = 0, tmp = 0, i7 = 0;
    char *r;

    r = (char *)malloc(sizeof(char) * (l1 + l2));
    while (l1 > 0 || l2 > 0) {
        l1--;
        l2--;
        if ((n1[l1] >= '0' && n1[l1] <= '9') && (n2[l2] >= '0' && n2[l2] <= '9')) { // pour evite '-'
            if (l1 < 0 && l2 >= 0) {
                tmp = (n2[l2] - 48) + i7;
            } else if (l1 >= 0 && l2 < 0) {
                tmp = (n1[l1] - 48) + i7;
            } else {
                tmp = (n1[l1] - 48) + (n2[l2] - 48) + i7;
            }
            if (tmp > 9) {
                r[i] = tmp % 10 + 48;
                i7 = tmp / 10;
            } else {
                r[i] = tmp + 48;
                i7 = 0;
            }
            i++;
        }
    }
    if (n1[0] == '-' && n2[0] == '-') {
        r[i] = '-';
        i++;
    }
    r[i] = '\0';
    while (r[--i])
        write(1,&r[i],1);
}

void    ft_inf_add(char *n1, char *n2) {
    if (n1[0] == '-' && n2[0] == '-')
        ft_add(n1, n2);
    // else if (n1[0] == '-' || n2[0] == '-')
    //     ft_sub(n1, n2);
    else
        ft_add(n1, n2);
}

int main(int ac, char **av) {
    if (ac == 3)
        ft_inf_add(av[1], av[2]);
    write(1,"\n",1);
    return (0);
}
