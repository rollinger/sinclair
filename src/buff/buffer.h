/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:29:27 by prolling          #+#    #+#             */
/*   Updated: 2021/07/24 19:36:46 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define BUFFER_SLICES 10

/*
* Integer buffer that you can push/pop to (lifo)
* It keeps track of the end
*/
typedef struct s_ibuff
{
	int		*buff;
	int		*bptr;
	size_t	bmax;
}				t_ibuff;

t_ibuff	*ibuff_create(void);
void	ibuff_push(t_ibuff *b, int i);
void	ibuff_pop(t_ibuff *b, int i);
