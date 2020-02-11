#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int		ft_strcmp(char *num1, char *num2)
{
	int		i;

	i = 0;
	while (num1[i] && num2[i] && num1[i] == num2[i])
		i++;
	if (num1[i] == '\0')
		return (3);
	else if ((num1[i] - '0') - (num2[i] - '0') < 0)
		return (1);
	return (0);
}

void	sub(char *num1, char *num2)
{
	int		i7, n1, n2, n, sign_1, sign_2, s, res, i, check;
	char	*swap;

	n = 0;
	sign_1 = 0;
	sign_2 = 0;
	if (num1[0] == '-')
	{
		sign_1 = 1;
		num1++;
	}
	if (num2[0] == '-')
	{
		sign_2 = 1;
		num2++;
	}
	check = 0;
	n1 = ft_strlen(num1);
	n2 = ft_strlen(num2);
	i = n1 - n2;
	if (i == 0)
	{
		check = ft_strcmp(num1, num2);
		if (check == 3)
		{
			write(1, "0", 1);
			return ;
		}
	}
	if (check == 1 || i < 0)
	{
		swap = num1;
		num1 = num2;
		num2 = swap;
		s = n1;
		n1 = n2;
		n2 = s;
		n = 1;
	}
	i7 = 0;
	while (n1 >= 0)
	{
		if (n2 >= 0)
		{
			if (((num1[n1] - '0') - (num2[n2] - '0' - i7)) < 0)
			{
				res = ((num1[n1] - '0') + 10) - ((num2[n2] - '0') + i7);
				num1[n1] = (res % 10) + '0';
				i7 = 1;
			}
			else
			{
				res = (num1[n1] - '0') - ((num2[n2] - '0') + i7);
				num1[n1] = (res % 10) + '0';
				i7 = 0;
			}
		}
		else
		{
			if (((num1[n1] - '0') - i7) < 0)
			{
				res = ((num1[n1] - '0') + 10) - i7;
				num1[n1] = (res % 10) + '0';
				i7 = 1;
			}
			else
			{
				res = (num1[n1] - '0') - i7;
				num1[n1] = (res % 10) + '0';
				i7 = 0;
			}
		}
		n1--;
		n2--;
	}
	if ((sign_1 == 1 && n == 0) || (sign_2 == 1 && n == 1))
		write(1, "-", 1);
	i = 0;
	while (num1[i] == '0')
		i++;
	while(num1[i])
		write(1, &num1[i++], 1);
}

void	add(char *num1, char *num2)
{
	int		sign, n1, n2, i, i7, res, s;
	char	*swap;
	char	c;

	sign = 0;
	if (num1[0] == '-')
	{
		sign = 1;
		num1++;
		num2++;
	}
	n1 = ft_strlen(num1);
	n2 = ft_strlen(num2);
	i = n1 - n2;
	if (i < 0)
	{
		swap = num1;
		num1 = num2;
		num2 = swap;
		s = n1;
		n1 = n2;
		n2 = s;
	}
	i7= 0;
	while (n1 >= 0)
	{
		if (n2 >= 0)
		{
			res = (num1[n1] - '0') + (num2[n2] - '0') + i7;
			if (res > 9)
			{
				num1[n1] = (res % 10) + '0';
				i7 = res /10;
			}
			else
			{
				num1[n1] = (res % 10) + '0';
				i7 = 0;
			}
		}
		else
		{
			res = (num1[n1] - '0') + i7;
			if (res > 9)
			{
				num1[n1] = (res % 10) + '0';
				i7 = res /10;
			}
			else
			{
				num1[n1] = (res % 10) + '0';
				i7 = 0;
			}
		}
		n1--;
		n2--;
	}
	if (sign == 1)
		write(1, "-", 1);
	if (i7 > 0)
	{
		c = i7 + '0';
		write(1, &c, 1);
	}
	i = 0;
	while (num1[i])
		write(1, &num1[i++], 1);
}

void	infinit_add(char *num1, char *num2)
{
	if ((num1[0] == '-' && num2[0] == '-') || (num1[0] != '-' && num2[0] != '-'))
		add(num1, num2);
	else
		sub(num1, num2);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		infinit_add(argv[1], argv[2]);
	write(1, "\n", 1);
}
