/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:53:13 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 33)
			return (0);
		if (base[i] == '/' || base[i] == '*' || base[i] == '%')
			return (0);
		if (base[i] == '.' || base[i] == ',' || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	print_num(long int nbr, char *base, int size)
{
	if (nbr < size)
		write(1, &base[nbr], 1);
	else
	{
		print_num(nbr / size, base, size);
		print_num(nbr % size, base, size);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			size;
	long int	n;

	size = base_check(base);
	if (size == 0)
		return ;
	if (nbr < 0)
	{
		n = nbr;
		n = n * -1;
		write(1, "-", 1);
	}
	else
		n = nbr;
	print_num(n, base, size);
}

/* int main()
{
	char b[] = "0123456789abcdef";
	ft_putnbr_base(-2147483648, b);
	return 0;
}
 */
