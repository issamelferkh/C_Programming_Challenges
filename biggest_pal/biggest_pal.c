#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*(str + strlen) != '\0')
		strlen++;
	return (strlen);
}

int		isnext(char *str, int start)
{
	int	i;
	int	strlen;

	strlen = ft_strlen(str);
	i = strlen - 1;
	while (i > start)
		if (str[start] == str[i--])
			return (i + 1);
	return (0);
}

int		getpal(char *str, int i, int j, int pallen)
{
	int	k;

	k = 0;
	while (j - k > i + k)
	{
		if (str[i + k] == str[j - k])
			k++;
		else
		{
			k = 0;
			j--;
		}
	}
	if (k > 0 && str[i + k] == str[j - k])
	{
		if (j - i + 1 >= pallen)
			return (j - i + 1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int	i;
	int	j;
	int strlen;
	int	pallen;
	int	palstart;

	if (argc == 2 && !(pallen = 0))
	{
		if ((strlen = ft_strlen(argv[1])))
			ft_putchar(argv[1][0]);
		i = 0;
		while (i < strlen - 1 && pallen < strlen - i + 1)
		{
			if ((j = isnext(argv[1], i)))
			{
				if (getpal(argv[1], i, j, pallen) >= pallen && (palstart = i))
					pallen = getpal(argv[1], i, j, pallen);
			}
			i++;
		}
		if (pallen > 0)
			write(1, argv[1] + palstart, pallen);
	}
	ft_putchar('\n');
	return (0);
}