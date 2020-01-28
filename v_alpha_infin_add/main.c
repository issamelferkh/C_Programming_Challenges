/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:31:16 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/28 15:31:18 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // for test
#include <stdlib.h>

// char    *ft_itoa(int n) {
//     char *str;
//     int i = 0;

//     str = (char *)malloc(100);
//     while (n > 0) {
//         str[]
//     }
// }

int ft_strlen(char *str) {
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void    inf_add(char *n1, char *n2) {
    int i = 0, r = 0, max;
    int ln1 = ft_strlen(n1), ln2 = ft_strlen(n2);
    char c, *str;

    if (ln1 > ln2)
        max = ln1;
    else
        max = ln2;
    str = (char *)malloc(max+10);

    while (i < max) {
        if (n1[i] == '\0'){
            n1[i] = '0';
        }
        i++;
    }
    n1[i] = '\0';
    i = 0;
    while (i < max) {
        if (n2[i] == '\0') {
            n2[i] = '0';
        }
        i++;
    }
    n2[i] = '\0';
    printf("%s | %s",n1,n2);
    // while (n1[i] && n2[i]) {
    //     r = (n1[i]-48) + (n2[i]-48) + r;
        
    //     str[i] = r % 10 + 48;
    //     printf("n1[i] => %d\n",n1[i]-48);
    //     printf("n2[i] => %d\n",n2[i]-48);
    //     printf("str[i] => %c\n",str[i]);
    //     r = r / 10;
    //     i++;
    //     printf("rest => %d\n",r);
    //     write (1,&str[i],1);
    // }
    // str[i] = r + 48;
    // str[++i] = '\0';
    // // while (str[--i])
    // //     write (1,&str[i],1);
    // write (1,"\n",1);
}

int main(int ac, char **av) {
    inf_add(av[1], av[2]);
    return (0);
}