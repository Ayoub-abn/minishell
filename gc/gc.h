/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:30:34 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/08 20:30:43 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdlib.h>

typedef struct s_malloc
{
	void			*address_to_save;
	struct s_malloc	*next;
}					t_malloc;

void				gc_push(void *address_to_save);
void				_free(void);
void				error_exit(int status, char *str);
#endif
