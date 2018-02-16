/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:33:53 by gpoblon           #+#    #+#             */
/*   Updated: 2018/02/04 16:39:58 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t	print_blocks(t_block *block, size_t subtotal)
{
	if (!block->free)
	{
		ft_putstr("\n0x");
		ft_putnbr_base((long)block->ptr, 16);
		ft_putstr(" - 0x");
		ft_putnbr_base((long)(block->ptr + block->size), 16);
		ft_putstr(" : ");
		ft_putnbr_base(block->size, 10);
		ft_putstr(" octets");
		subtotal += block->size;
	}
	if (block->next)
		print_blocks(block->next, subtotal);
	return (subtotal);
}

static size_t	print_maps(t_map *map, size_t subtotal)
{
	subtotal += print_blocks(map->block, 0);
	if (map->next)
		return (print_maps(map->next, subtotal));
	return (subtotal);
}

static t_bool	print_header(t_map *head, char *str_type)
{
	if (!head)
	{
		ft_putstr(str_type);
		ft_putstr(" : NULL\n");
		return (FALSE);
	}
	ft_putstr(str_type);
	ft_putstr(" : 0x");
	ft_putnbr_base((long)head, 16);
	return (TRUE);
}

static size_t	print_alloc_mem_type(int type, char *str_type)
{
	if (!print_header(g_types_tab[type], str_type))
		return (0);
	return (print_maps(g_types_tab[type], 0));
}

void			show_alloc_mem(void)
{
	size_t	total;

	total = 0;
	total += print_alloc_mem_type(TINY, "TINY");
	ft_putstr("\n");
	total += print_alloc_mem_type(SMALL, "SMALL");
	ft_putstr("\n");
	total += print_alloc_mem_type(LARGE, "LARGE");
	ft_putstr("Total : ");
	ft_putnbr_base((long)total, 10);
	ft_putstr(" octets\n");
}
