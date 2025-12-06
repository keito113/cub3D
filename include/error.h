/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:18:36 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/03 14:42:58 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_errc
{
	ERR_USAGE = 1,
	ERR_EXT,
	ERR_OPEN,
	ERR_PARSE,
	ERR_MAP,
	ERR_MLX,
	ERR_IMG,
	ERR_ALLOC
}	t_errc;

#endif
