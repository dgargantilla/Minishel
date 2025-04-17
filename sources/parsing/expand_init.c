/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:39:05 by dgargant          #+#    #+#             */
/*   Updated: 2025/04/17 11:48:10 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gertru.h"

char	*expand_init(t_pipes *data, char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = NULL;
	//reccorrer la string buscando el '$' teniendo en cuenta las comillas
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
		if (line[i] == '<' && line[i + 1] == '<')
		{
			// crear funcion para ignorar delimitador
			i += 2;
			while (!(line[i] >= '!' && line[i] <= 126))
				i++;
			while(line[i])
			{
			 	if (line[i] == '<' || line[i] == '>' || line[i] == '|')
					break;
				if (!(line[i] >= '!' && line[i] <= 126))
					break;
				i++;
			}
		}
		// si estoy en comillas simples ignoro la variable	
		if (line[i] == '$' && (data->pars->fs == 1))
		{
			while (line[i] && line[i] >= '!' && line[i] <= 126))
				i++;
		}
		//else if (line[i] == '$')
				
		i++;
	}
	
	//buscar esa variable en el enviroment y reservar lo que devuelva 
	//contar cuanto ocupa y crear una reserva de memoria de la nueva linea
	//insertar la variable expandida
	// hacerlo repetidamente hasta el final de linea


	return (new_line);
}

/*void	*move_quotes(t_pipes *data, char *line)
{
	char	*new_line;

	//

	return (new_line);
}*/