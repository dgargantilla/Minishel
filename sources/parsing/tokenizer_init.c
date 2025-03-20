/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:13:37 by dgargant          #+#    #+#             */
/*   Updated: 2025/03/20 09:59:05 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gertru.h"


/* Esto sera una funcion que recorrera la linea
y la tokenizara llamando a otras funciones*/
void	tokenizer_init(t_pipes *data, char *line)
{
	int i;

	i = take_fist_token(data, line);
	while (line[i])
	{
		/*if (line[i] == '"' || line[i] == '\'')
		{
			i++;
			while (line[i] != '"' || line[i] != '\'')
				i++;
			i++;
		}*/
		if (line[i] == '<' && line[i + 1] == '<')
		{
			i++;
			take_hdelimiter(data, line,(i + 1));
		} else if (line[i] == '>' && line[i + 1] == '>')
		{
			i++;
			take_tfile(data, line, N_AOUTF, i + 1);
		}else if (line[i] == '<')
			take_tfile(data, line, N_INF, i + 1);
		else if (line[i] == '>')
			take_tfile(data, line, N_OUTF, i + 1);
		else if (line[i] == '|')
			take_pipes(data, line, i + 1);
		i++;
	}
}

