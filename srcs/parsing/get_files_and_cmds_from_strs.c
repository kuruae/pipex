/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files_and_cmds_from_strs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:02:20 by hucherea          #+#    #+#             */
/*   Updated: 2024/10/23 16:59:09 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static	t_input_data	*init_data(void)
{
	t_input_data	*data;

	data = (t_input_data *)malloc(sizeof(t_input_data));
	if (data == NULL)
		return (NULL);
	data->infile = NULL;
	data->outfile = NULL;
	data->cmds = NULL;
	return (data);
}

t_input_data	*get_files_and_cmds_from_strs(int strs_len, const char **strs)
{
	t_input_data	*data;

	data = init_data();
	if (data == NULL)
		return (NULL);
	if (get_files(&data->infile, &data->outfile, strs, strs_len) == FAILURE)
	{
		free_data(data);
		return (NULL);
	}
	data->cmds = build_cmds(strs + 1, strs_len - 1,
			ft_strncmp(strs[0], "here_doc", LEN_HERE_DOC) == 0);
	if (data->cmds == NULL)
	{
		free_data(data);
		return (NULL);
	}
	return (data);
}
