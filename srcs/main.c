/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:39:03 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/25 11:23:01 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_vars	vars;
	t_coord	*map;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		return (0);
	}
	map = parsing_file(fd);
	close(fd);
	print_map(map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF");
	mlx_hook(vars.win, 2, 1L << 0, win_close, &vars);
	mlx_hook(vars.win, 17, 0, win_destroy, &vars);
	mlx_loop(vars.mlx);
}
