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
#include <stdio.h> // for test

void	ft_putchar(char c) {
	write (1,&c,1);
}

void    ft_putnbr(int n) {
	if (n == -2147483648) {
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	} else if (n < 0) {
		ft_putchar('-');
		ft_putnbr(-n);
	} else if(n > 9) {
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	} else {
		ft_putchar(n + 48);
	}
	return ;
}

int main() // for test 
{
	ft_putnbr(-2147483648);
	return (0);
}