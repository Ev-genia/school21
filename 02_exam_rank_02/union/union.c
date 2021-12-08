#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	str[200];
	int		i;
	int		j;
	int		k;

	if (argc == 3)	
	{
		i = 0;
		while (*argv[1] && argv[1][i] != '\0')
		{
			str[i] = argv[1][i];
			i++;
		}
		j = 0;
		while (*argv[2] && argv[2][j] != '\0')
		{
			str[i] = argv[2][j];
			i++;
			j++;
		}
		str[i] = '\0';
		i = 0;
		while (str[i] && str[i] != '\0')
		{
			j = 0;
			k = 0;
			while (j < i)
			{
				if (str[i] == str[j])
					k++;
				j++;
			}
			if (k == 0)
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}