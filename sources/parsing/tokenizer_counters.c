/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_counters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:40:00 by dgargant          #+#    #+#             */
/*   Updated: 2025/03/05 10:26:28 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gertru.h"

// Funcion que cuenta el numero de heredocks
void	count_heredocs(t_pipes *data, char *line)
{
	int	i;
	int	hdoc;

	i = 0;
	hdoc = 0;
	while (line[i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
		{
			data->nhrd = ++hdoc;
			i++;
		}
		i++;
	}
}

// funcion para contar numero de pipes
void	count_pipes(t_pipes *data, char *line)
{
	int	i;
	int	npipe;

	i = 0;
	npipe = 0;
	while (line[i])
	{
		if (line[i] == '|' )
		{
			data->npipes = ++npipe;
			i++;
		}
		i++;
	}
}

/* Funcion que cuenta el numero de comandos en la pipe
	para la reserva de memoria del doble puntero*/

int	ft_is_token(char *line, int i)
{
	return(line[i] == '<' || line[i] == '>');
}

/*void	count_cmds(t_pipes *data, char *line, int i)
{
	int	ncmds;

	ncmds;
	while (line[i])
	{
		if ()
	}
			
}*/
/*Cuenta los ficheros de cada nodo, incluido los heredocs
	y reserba memoria para guardarlos despues*/
void	count_node_files(t_pipes *data, char *line, int i)
{
	t_cmds *nd;

	nd = ft_lstlast(data->cmds);
	while (line[i] && line[i] != '|')
	{
		if (line[i] == '<' && line[i + 1] == '<')
			{
				nd->s_files->nfiles++;
				i+= 2;
			}	
		else if (line[i] == '>' && line[i + 1] == '>')
		{
			nd->s_files->nfiles++;
			i+=2;
		}
		else if (line[i] == '<' || line[i] == '>')
			nd->s_files->nfiles++;
		i++;
	}
	if (nd->s_files->nfiles > 0)
	{
		nd->s_files->file = ft_calloc(nd->s_files->nfiles + 1, sizeof(char *));
		nd->s_files->flagfd = ft_calloc(nd->s_files->nfiles + 1, sizeof(int));
	}
}
