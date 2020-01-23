/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:13:24 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/23 16:13:26 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL
# define FLOOD_FILL

typedef struct s_point {
    int         x;
    int         y;
}               t_point;
void    flood_fill(char **tab, t_point size, t_point begin);

#endif