/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:30:05 by prolling          #+#    #+#             */
/*   Updated: 2021/07/24 19:51:46 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

/* create an int buffer */
t_ibuff	*ibuff_create(void)
{
	t_ibuff	*new;
	new = (t_ibuff *)malloc(sizeof(t_ibuff *));
	if (!new)
		return (NULL);
	return (new);
}

/* push to the end of the int buffer */
void ibuff_push(t_ibuff *b, int i)
{
	// TODO
	(void) b;
	(void) i;
	return ;
}

/* pop from the end of the int buffer */
void ibuff_pop(t_ibuff *b, int i)
{
	// TODO
	(void) b;
	(void) i;
	return ;
}
