/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:39:46 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/05 16:47:14 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	(void)ac;
	char	*line = NULL;
	int		ret;
	int		fd;

	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) && ret != -1)
	{
		printf("%s\n", line);
	}
	free(line);
	close(fd);
	return (0);
}

