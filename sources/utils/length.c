/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:34:20 by pavicent          #+#    #+#             */
/*   Updated: 2025/02/13 13:34:23 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gertru.h"

int	ft_array_length(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_lgth(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s1[i] != '=')
		i++;
	while (s2[j] && s2[j] != '=')
		j++;
	if (i > j)
		return (i);
	else
		return (j);
}
