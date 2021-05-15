/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:23:05 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/10 15:02:09 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *count;

	if (!(*lst))
		*lst = new;
	else
	{
		count = *lst;
		while (count->next != NULL)
			count = count->next;
		count->next = new;
		new->next = NULL;
	}
}
