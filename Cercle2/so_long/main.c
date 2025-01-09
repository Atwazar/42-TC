/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:36:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/28 13:58:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int ac, char **av, char **envp)
{
	t_var	var;

	var.garbage_collector = 0;
	var.map_unsplit = 0;
	var.map = 0;
	check_args(ac, av, envp);
	var.path = av[1];
	read_file(&var);
	check_map(&var);
	check_map_doable(&var);
	game_init(&var);
}
