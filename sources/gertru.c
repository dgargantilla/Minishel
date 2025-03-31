/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gertru.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:34:28 by dgargant          #+#    #+#             */
/*   Updated: 2025/03/27 12:27:53 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gertru.h"

/* Funcion que recive la linea de readline()
y llama al resto de funciones principales*/
void	read_imput(t_pipes *data)
{
	char *line = NULL;
	//int i = 0;
	
	while (1)
	{
		line = readline(PURPLE"Gertru$ "RESET);
		if (line == NULL)
			break;
		if (ft_strcmp(line, "exit") == 0)
			break;
		if (line != NULL)
		{
			parsing_init(data, line);
			/*printf(" > %s" ,data->envps[i]);
			//printf(" > %s\n", line);
			i++;*/
			/*AL FINAL TENDREMOS QUE LIBERAR LA MEMORIA
				DE TODAS LAS VARIABLES QUE QUE SE TENGAN
				QUE RESETEAR Y RESETEARLAS A 0/NULL*/
			data->num_cmds = 0;
		}
		add_history(line);
	}
}

int main(int argc, char **argv, char **envp)
{
	t_pipes *data;

	data = ft_calloc(1, sizeof(t_pipes));
	data->pars = ft_calloc(1, sizeof(t_pars));
	data->env = envp;

	if (argc == 1)
		read_imput(data);
	else if(argc == 2)
		printf("%s\n", argv[1]);
	data->nhrd = 0;
	data->npipes = 0;
	return (0);
}

