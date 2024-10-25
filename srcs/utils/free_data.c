/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:00:15 by emagnani          #+#    #+#             */
/*   Updated: 2024/10/23 17:00:18 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data(t_input_data *data)
{
	if (data->cmds != NULL)
		free_cmds(data->cmds);
	if (data->infile != NULL)
		free(data->infile);
	if (data->outfile != NULL)
		free(data->outfile);
	free(data);
}
