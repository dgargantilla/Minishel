/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:54:59 by pavicent          #+#    #+#             */
/*   Updated: 2025/02/26 12:55:06 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gertru.h"

void	open_tmp_file(t_pipes *data, int i)
{
	static int	count = 0;
	char		*nbr;

	data->cmds->s_files->file[i] = ft_strdup("/tmp/heredoc");
	nbr = ft_itoa(count);
	data->cmds->s_files->file[i] = ft_strjoin_free(
			data->cmds->s_files->file[i], nbr);
	free(nbr);
	if (access(data->cmds->s_files->file[i], F_OK) == 0)
	{
		free(data->cmds->s_files->file[i]);
		count++;
		open_tmp_file(data, i);
	}
	data->cmds->s_files->fd[i] = open(data->cmds->s_files->file[i],
			O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->cmds->s_files->fd[i] < 0)
	{
		write_error("minishell: No such file or directory: ",
			data->cmds->s_files->file[i]);
		unlink(data->cmds->s_files->file[i]);
	}
	count++;
}

void	close_files(t_cmds *list)
{
	int		i;
	t_cmds	*tmp;

	tmp = list;
	while (list)
	{
		i = 0;
		while (list->s_files && list->s_files->file && list->s_files->file[i])
		{
			if (list->s_files->fd[i] > 0)
			{
				close(list->s_files->fd[i]);
				list->s_files->fd[i] = -1;
			}
			i++;
		}
		list = list->next;
	}
	list = tmp;
}
