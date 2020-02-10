/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:31:46 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/02/10 16:31:46 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     ft_check(char *str, int i, int j) { // check if palindrome
    while (str[i] && i <= j) {
        if (str[i] != str[j])
            return (0);
        i++;
        j--;
    }
    return (1);
}

int     ft_same(char *str) { // check if all chars of the str is the same.
    int i = 0, j = 0;

    while (str[j]) {
        i = 0;
        while (str[i]) {
            if (str[i] != str[j])
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}
void    ft_pal(char *str) {
    int j = 0, i = 0, max = 0, len = 0, start = 0;

    if (ft_same(str)) { // to avoid timeout 
        while (str[i]) {
            write(1,&str[i],1);
            i++;
        }
        return ;
    }
    while (str[j])
        j++;
    while (str[--j]) {
        i = 0;
        while (str[i]) {
            if (ft_check(str,i,j)) { // check if palindrome
                len = j - i + 1;
                if (len > max) {
                    start = i; 
                    max  = len;
                }
            }
            i++;
        }
    }
    i = 0;
    while (str[start] && i < max) {
        write(1,&str[start],1);
        start++;
        i++;
    }
}

int main (int ac, char **av) {
    if (ac == 2)
        ft_pal(av[1]);
    write(1,"\n",1);
    return (0);
}