/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:03:46 by dgargant          #+#    #+#             */
/*   Updated: 2025/01/23 12:50:16 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_substr(const char *s, unsigned int start, size_t len);

void	*ft_free_array(char **array);

void	ft_free_void_array(void **array);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strjoin_free(const char *s1, const char *s2);

char	*ft_strjoin_free2(const char *s1, const char *s2);

char	*ft_superjoin(const char *s1, char c, const char *s2);

char	**ft_split(char const *s, char c);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isprint(char c);

char	*ft_strchr(const char *s, int c);

int		ft_atoi(const char *str);

char	*ft_itoa(int n);

int		ft_isspace(int c);

void	ft_putendl_fd(char *s, int fd);

void	ft_putstr_fd(char *s, int fd);

int64_t	ft_atoll(const char *str);

#endif