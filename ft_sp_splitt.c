/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_splitt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:58:19 by dgargant          #+#    #+#             */
/*   Updated: 2025/02/28 11:51:06 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>



typedef struct s_split
{
	size_t	end;
	size_t	start;
}		t_split;

int	ft_isspace(int a)
{
	if (a != ' ' && a != '\f' && a != '\n'
		&& a != '\r' && a != '\t' && a != '\v')
		return (0);
	return (1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len-- > 0)
		*p++ = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr != NULL)
		ft_bzero(ptr, count * size);
	return (ptr);
}

static void	*ft_empty_array(char **array, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	count_words(char *s)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			i++;
		else if(s[i] == 39 || s[i] == '"')
		{
			++i;
			words++;
			while (s[i] && !(s[i] == 39 || s[i] == '"'))
				i++;
			i++;
		}
		else
		{
			words++;
			while ( !ft_isspace(s[i]) && s[i])
				i++;
		}
	}
	return (words);
}

static void	ft_fill_array(char *array, char *buffer, t_split data)
{
	size_t	i;

	i = 0;
	while (data.start < data.end)
	{
		array[i] = buffer[data.start];
		data.start++;
		i++;
	}
}

char	**split(char *s, char **array, t_split data)
{
	int	i;

	i = 0;
	array = ft_calloc((count_words(s) + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (s[data.end])
	{
		if (ft_isspace(s[data.end]))
			data.end++;
		else if(s[data.end] == 39 || s[data.end] == '"')
		{
			data.end++;
			data.start = data.end;
			while (s[data.end] && !(s[data.end] == 39 || s[data.end] == '"'))
				data.end++;
			array[i] = ft_calloc((data.end - data.start + 1), sizeof(char));
			if (array[i] == NULL)
				return (ft_empty_array(array, i));
			ft_fill_array(array[i], s, data);
			i++;
			if (s[data.end])
				data.end++;
		}
		else
		{
			data.start = data.end;
			while (!ft_isspace(s[data.end]) && s[data.end])
				data.end++;
			array[i] = ft_calloc((data.end - data.start + 1),  sizeof(char));
			if (array[i] == NULL)
				return (ft_empty_array(array, i));
			ft_fill_array(array[i], s, data);
			i++;
		}
	}
	return (array);
}

char	**ft_sp_split(char *s)
{
	char	**array;
	static t_split data;

	data.end = 0;
	array = NULL;
	if(!s)
		return (NULL);
	array = split(s, array, data);
	return (array);
}

int main(int argc, char **argv)
{
	(void)argc;
	char **splited = NULL;
	int i;
	int j;

	i = 0;
	j = 0;
	splited = ft_sp_split(argv[1]);
	if (!splited)
		return (0);
	while (argv[j++])
		printf("%s\n", argv[j]);
	printf("%zu\n",  count_words(argv[1]));
	while (splited[i])
	{
		printf("%d-> %s\n",i, splited[i]);
		i++;
	}
	
	return (0);
}