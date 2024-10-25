/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_with_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:08 by hucherea          #+#    #+#             */
/*   Updated: 2024/10/23 16:59:13 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_state_function	exec_cmds_with_files(t_input_data	*data, char **env)
{
	exec_cmds(data->cmds, env, data->infile, data->outfile);
	free_data(data);
	return (SUCCESS);
}
