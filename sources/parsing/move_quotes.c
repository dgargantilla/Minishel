/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:35:06 by dgargant          #+#    #+#             */
/*   Updated: 2025/05/19 12:21:35 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gertru.h"

// hacemos una nueva linea del mismo tamaño con calloc
// en la vieja miro comillas caracter por caracter

void	quote_manager(t_pipes *data, char *line)
{
	int		i;
	char	*new_line;
	
	i = 0;
	new_line = ft_calloc(ft_strlen(line), sizeof(char));
	
	while (line[i])
	{
		if ((line[i] == '"' && data->pars->fdb == 0) && data->pars->fs != 1)
			data->pars->fdb = 1;
		else if ((line [i] == '"' && data->pars->fdb == 1)
			&& data->pars->fs != 1)
			data->pars->fdb = 0;
		if ((line[i] == '\'' && data->pars->fs == 0) && data->pars->fdb != 1)
			data->pars->fs = 1;
		else if ((line [i] == '\'' && data->pars->fs == 1)
			&& data->pars->fdb != 1)
			data->pars->fs = 0;
		//printf("comillas dobles: %d\n", data->pars->fdb);
		//printf("comillas simples: %d\n", data->pars->fs);
		//printf("%c\n", line[i]);
		//move_quotes(data, line, new_line, i);
		i++;
	}
	line = new_line;
	printf("\n>>>>>>linea moviendo comillas: %s\n", new_line);
}

/*void	delete_some_quotes(t_pipes *data, char *line, char *new_line , int i)
{
	
	static int		j;

	
	j = 0;
	if ((line[i] == '"' && data->pars->fs == 1)
		|| (data->pars->fdb == 1 && line[i] == '\''))
	{
		new_line[j] = line[i];
		j++;
		printf("1 [%c], ", line[i]);
	}
	else if ((line[i] == '"' || line[i] == '\'' ) 
		&& (line[i + 1] == '"' || line[i + 1] == '\''))
	{
		printf("2 [%c], ", line[i]);
	}
	else if ((line[i] == '"' || line[i] == '\'' ) 
		&& (line[i - 1] == '"' || line[i - 1] == '\''))
	{
		printf("3 [%c], ", line[i]);
	}
	else if (ft_isprint(line[i]))
	{
		new_line[j] = line[i];
		j++;
		printf("4 [%c], ", line[i]);
	}
	
		if (line[i] == '"' && !ft_is_token(line, i + 1) && line[i + 1] != '|'
		&& (line[i + 1] >= '!' && line[i + 1] <= 126))
			i++;
		else
		{
			new_line[j] = line[i];
		}
	//printf("\n>>>>>>linea moviendo comillas: %s\n", new_line);
		
}*/

/*void	move_quotes(t_pipes *data, char *line, char *new_line, int i)
{
	if(line[i] && (line[i] >= '!' && line[i] <= 126) && !ft_is_token(line, i)
	 && line[i] != '|' && (line[i + 1] == '"' || line[i + 1] == '\'')
	 && data->pars->fdb == 0 && data->pars->fs == 0)
	 	move_quote_backward(line, new_line, i);
}*/

/*void	move_quote_backward(char *line, char *new_line, int i)
{
	int		j;
	int		k;
	int		l;
	int		m;
	char	c;

	j = 0; //iterador de new_line
	k = i + 1;	//posicion de la comilla
	l = i; // inicio del argumento
	m = 0; //iterador de line
	c = line[i + 1]; //tipo de comilla
	//printf("HOLAAAAAAA");
	while((k > 0) && (line[k] >= '!' && line[k] <= 126)
		&& !ft_is_token(line, k) && line[k] != '|')
	{
		new_line[]
	}
	printf("AAAA %c\n", line[l]);
	while (line[m])
	{
		printf("moviendo comillas: %c\n", line[m]);
		new_line[j] = line[m];
		if (j == k)
		{
			m++;
		}
		if (j == l)
		{
			printf("j: %d l:%d\n",j,l);
			new_line[j] = c;
			j++;
		}
			new_line[j] = line[m];
		m++;
		j++;
	}
}*/

/*void	*move_quote_forward(t_pipes *data, char *line, char new_line, int i)
{
	char	*new_line;

	new_line = NULL;
	
	return (new_line);
}*/


/*void	check_quotes_to_move(t_pipes *data, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '"' && data->pars->fdb == 0) && data->pars->fs != 1)
			data->pars->fdb = 1;
		else if ((line[i] == '"' && data->pars->fdb == 1)
			&& (line[i + 1] >= '!' && line[i + 1] <= 126)
			&& data->pars->fs != 1)
			line = move_quote_forward(data, line, i);
		else if ((line[i] == '"' && data->pars->fdb == 1)
			&& (line[i - 1] >= '!' && line[i - 1] <= 126)
			&& data->pars->fs != 1)
			line = move_quote_backward(data, line, i);
		else if ((line [i] == '"' && data->pars->fdb == 1)
			&& !(line[i + 1] >= '!' && line[i + 1] <= 126)
			&& data->pars->fs != 1)
			data->pars->fdb = 0;
		if ((line[i] == '\'' && data->pars->fs == 0) && data->pars->fdb != 1)
			data->pars->fs = 1;
		else if ((line [i] == '\'' && data->pars->fs == 1)
			&& data->pars->fdb != 1)
			data->pars->fs = 0;
		if (line[i])
			i++;
	}	
}*/



