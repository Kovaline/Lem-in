/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:42:52 by ikovalen          #+#    #+#             */
/*   Updated: 2018/12/03 12:52:05 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			base_length(intmax_t val, int base, t_flag *fl)
{
	int len;
	int i;

	i = fl->dot;
	len = 0;
	if (val < 0)
		val = val * -1;
	while (val > 0)
	{
		val = val / base;
		len++;
	}
	if (i > len)
		len = i;
	return (len);
}

static char			*to_str(intmax_t val, int len, int i, int base)
{
	static char		*digits = "0123456789ABCDEF";
	char			*out;

	out = ft_strnew(len + 1);
	if (val < 0)
	{
		val *= -1;
		if (base == 10)
		{
			out = ft_strnew(len + 2);
			i = 1;
			len++;
			out[0] = '-';
		}
	}
	out[len] = '\0';
	while (val != 0 && len > i)
	{
		out[len - 1] = digits[val % base];
		val = val / base;
		len--;
	}
	while (--len >= i)
		out[len] = '0';
	return (out);
}

char				*ft_itoa_base(intmax_t nb, int base, t_flag *fl)
{
	int	len;

	if (base < 2 || base > 16)
		return (NULL);
	if (nb < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	len = base_length(nb, base, fl);
	return (to_str(nb, len, 0, base));
}
