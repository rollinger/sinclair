/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:29:27 by prolling          #+#    #+#             */
/*   Updated: 2021/07/24 20:09:59 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define BUFFER_BLOCK_LEN 10

/*
* Integer buffer that you can push/pop to (lifo)
* It keeps track of the current end pointer and the maximum size
*/
typedef struct s_ibuff
{
	int		*buff; 	/* actual buffer of ints */
	int		*bptr; 	/* ptr of next insertion */
	size_t	bmax; 	/* current buffer size */
}				t_ibuff;

t_ibuff	*ibuff_create(void);
void	ibuff_push(t_ibuff *b, int i);
void	ibuff_pop(t_ibuff *b, int i);
