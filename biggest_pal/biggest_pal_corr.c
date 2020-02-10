#include <unistd.h>

int		ft_try(int i, int j, char *str, int *pal)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	while (i >= 0 && j <= len && str[i] == str[j])
	{
		i--;
		j++;
	}
	if (j - i >= *pal)
	{
		*pal = j - i;
		return (i);
	}
	return (0);
}

void	ft_bpal(char *str)
{
	int		i;
	int		k;
	int		pal;
	int		start;

	k = 0;
	pal = 0;
	i = 0;
	while (str[k])
	{
		if ((i = ft_try(k, k + 1, str, &pal)))
			start = i + 1;
		if ((i = ft_try(k - 1, k + 1, str, &pal)))
			start = i + 1;
		k++;
	}
	pal = pal - 1;
	while (pal-- > 0)
		write(1, &str[start++], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_bpal(argv[1]);
	write(1, "\n", 1);
	return (0);
}