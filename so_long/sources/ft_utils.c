/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:36:39 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 18:20:21 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i ++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strdup(char *str)
{
	unsigned long int	i;
	char				*result;

	i = ft_strlen(str) + 1;
	result = malloc(sizeof(char) * (i + 1));
	ft_strcpy(result, str);
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((s1[i] != '\0' || s2[i] != '\0')
			&& (s1[i] == s2[i]) && (i < n - 1)))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_itoa(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_itoa(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_write_moves(unsigned int n)
{
	ft_itoa(n);
	write (1, " moves", 6);
	write(1, "\n", 1);
}
