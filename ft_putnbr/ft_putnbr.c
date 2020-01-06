/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:57:57 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/06 20:13:45 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c) {
	write (1,&c,1);
}

void    ft_putnbr(int n) {
	char c;
	
	while (n) {
		c = n % 10 + 48;
		ft_putchar(c);
		n = n / 10;
		if (n > 9)
			ft_putnbr(n);
	}
	write(1,"\n",1);
}

int main() {
	ft_putnbr(4512);
	return (0);
}
