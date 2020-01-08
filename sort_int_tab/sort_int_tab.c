/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:11:08 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/08 16:11:10 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for test

void sort_int_tab(int *tab, unsigned int size) {
    int i = 0, j, x;
    while (i < size) {
        j = i + 1;
        while (j < size) {
            if (tab[i] > tab[j]) {
                x = tab[i];
                tab[i] = tab[j];
                tab[j] = x;
            }
            j++;
        }
        i++;
    }
}

int main () { // for test
    int i = 0, tab[15] = {48,47,42,9,15,12,14,54,12,3,-1,0,-15487,2,-454548};

    while (i < 15) {
        printf("%d\t",tab[i]);
        i++;
    }
    i = 0;
    printf("\n");
    sort_int_tab(tab, 15);
    while (i < 15) {
        printf("%d\t",tab[i]);
        i++;
    }
}