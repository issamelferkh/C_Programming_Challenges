/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:29:05 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/23 18:29:07 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av) {
    int i = 1, j, x = 0;
    char tab[32] = {"00000000000000000000000000000000"};

    if (ac > 1) {
        while (av[i]) {
            j = 1;
            if (av[i][0] == '-' && av[i][1] == 'h') {
                write(1,"options: abcdefghijklmnopqrstuvwxyz\n",36);
                return (0);
            }
            if (av[i][0] == '-') {
                while (av[i][j]) {
                    if (av[i][j] >= 'a' && av[i][j] <= 'z') {
                        tab['z' - av[i][j] + 6] = '1';
                    } else {
                        write(1,"Invalid Option\n",15);
                        return (0);
                    }
                    j++;
                }
            }
            i++;
        }
        i = 0;
        while (i < 32) {
            if (i == 8 || i == 16 || i == 24)
                write(1," ",1);
            write(1,&tab[i],1);
            i++;
        }
        write(1,"\n",1);
    } else {
        write(1,"options: abcdefghijklmnopqrstuvwxyz\n",36);
    }
    return (0);
}

