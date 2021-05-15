/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:42:04 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/10 14:34:07 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*fst;
	t_list	*lstcount;

	if (*lst)
	{
		fst = *lst;
		lstcount = *lst;
		while (lstcount != NULL)
		{
			(*del)(fst->content);
			lstcount = fst->next;
			free(fst);
			fst = lstcount;
		}
		*lst = NULL;
	}
}
