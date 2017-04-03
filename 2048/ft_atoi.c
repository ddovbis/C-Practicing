int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		semn;

	i = 0;
	num = 0;
	semn = 1;
	while (str[i] >= 1 && str[i] <= 32)
		i++;
	if (str[i] == '-')
		semn = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (int)str[i] - 48;
		if ((num * semn) > 2147483647)
			return (-1);
		else if ((num * semn) < -2147483648)
			return (0);
		i++;
	}
	return (num * semn);
}
