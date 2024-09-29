/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:51:16 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	int		i;
	int		j;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	j = count * size;
	while (i < j)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}

/* #include <string.h>
int	main(void)
{
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));

	printf("\n%i\n",memcmp(d1, d2, size * sizeof(int)));
	printf("right?\n");
	free(d1);
	free(d2);
	return 0;
} */
