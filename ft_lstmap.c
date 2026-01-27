/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:10:28 by rhrandri          #+#    #+#             */
/*   Updated: 2026/01/27 10:38:12 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlis;
	t_list	*nobj;

	if (!lst || !del || !f)
		return (NULL);
	nlis = NULL;
	while (lst)
	{
		nobj = ft_lstnew(f(lst->content));
		if (!nobj)
		{
			ft_lstclear(&nlis, del);
			return (NULL);
		}
		ft_lstadd_back(&nlis, nobj);
		lst = lst->next;
	}
	return (nlis);
}
