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
	new->buff = (int *)malloc(sizeof(int) * BUFFER_BLOCK_LEN);
	new->bptr = new->buff;
	new->bmax = BUFFER_BLOCK_LEN;
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

/* frees the int buffer and its content */
void ibuff_free(t_ibuff *b)
{
	// TODO
	(void) b;
	return ;
}