/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:36:27 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/28 21:36:28 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // test

void    ft_puthex(int n) {
    char *c;
    int tmp, i = 0;

    c[i] = '\0';
    while (n > 0) {
        tmp = n % 16;
        if (tmp >= 0 && tmp <= 9)
            c[++i] = tmp + 48;
        else if (tmp >= 10 && tmp <= 15)
            c[++i] = tmp + 'a' - 10;
        n = n / 16;
    }
    while (c[i])
        write(1,&c[i--],1);
}

void	print_memory(const void *addr, size_t size) {
    unsigned int i = 0, j = 0;
    char *p;

    p = (char *)addr;
    while (p[i]) {
        ft_puthex(p[i]);
        i++;
        j++;
        if (j%2 == 0)
            write(1," ",1);
    }

}

int	main(void) // for test
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
    // ft_puthex(23);
	return (0);
}