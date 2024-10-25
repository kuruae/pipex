/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:53:38 by hucherea          #+#    #+#             */
/*   Updated: 2024/10/23 17:16:56 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmds(t_cmd *cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i].tokens != NULL)
	{
		ft_free_str_array(&cmds[i].tokens);
		++i;
	}
	free(cmds);
}
