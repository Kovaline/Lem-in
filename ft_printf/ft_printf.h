/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:55:28 by ikovalen          #+#    #+#             */
/*   Updated: 2019/01/29 14:43:05 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define A i = 0; fl.count = 0; settozero(&ft, &fl); va_start(var, format)
# define B fl->isdot = 0; fl->dot = 0; tmp = applyflagsint(tmp, ft, fl)
# define C fl->sharp = 0; fl->plus = 0; fl->space = 0
# define D fl->plus = 0; fl->space = 0
# define E if (fl->type == 'F' || fl->type == 'f') fl->type = 'f'
# define F fl->type = fl->type + 32; ft->l = 1
# define G while (str[i] > 47 && str[i] < 58) i++
# define H if (fl->starwidth == 1) fl->checkstar = 1
# define I va_list var; int		i; t_fl	ft; t_flag	fl;
# define J printit(var, &ft, &fl); settozero(&ft, &fl)
# include "libft/libft.h"

# define BOLD "\x1b[1m"
# define UNDERLINED "\x1b[4m"
# define BLINK "\x1b[5m"
# define INVERT "\x1b[7m"
# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define PINK "\x1b[35m"
# define AQUA "\x1b[36m"
# define WHITE "\x1b[37m"

# define EOM "\x1b[0m"

typedef	struct	s_fl
{
	unsigned int		l : 1;
	unsigned int		h : 1;
	unsigned int		ll : 1;
	unsigned int		hh : 1;
	unsigned int		bigl : 1;
	unsigned int		z : 1;
	unsigned int		j : 1;
}				t_fl;

typedef struct	s_flag
{
	unsigned int		zero : 1;
	unsigned int		sharp : 1;
	unsigned int		minus : 1;
	unsigned int		plus : 1;
	unsigned int		space : 1;
	unsigned int		width;
	unsigned int		dot;
	unsigned int		count;
	unsigned int		isdot;
	char				type;
	unsigned int		iszero;
	unsigned int		starwidth;
	unsigned int		stardot;
	unsigned int		checkstar;
}				t_flag;

int				ft_printf(const char *format, ...);
void			printbinary(va_list var, t_fl *ft, t_flag *fl);
void			printnone(t_fl *ft, t_flag *fl, char c);
void			fillstar(va_list var, t_flag *fl);
char			*ft_itoad(intmax_t nb, int base);
void			printdouble(va_list var, t_fl *ft, t_flag *fl);
char			*ft_utoa_base(uintmax_t nb, int base, t_flag *fl);
void			printocta(va_list var, t_fl *ft, t_flag *fl);
char			*sharp(char *tmp, t_flag *fl, struct s_norme *t);
uintmax_t		convertingu(uintmax_t i, t_fl *ft);
char			*applyflagsint(char *str, t_fl *ft, t_flag *fl);
void			printhexa(va_list var, t_fl *ft, t_flag *fl);
void			printu(va_list var, t_fl *ft, t_flag *fl);
char			*ft_itoa_base(intmax_t nb, int base, t_flag *fl);
char			*applysignsnone(char *tmp, int j, int len);
char			*applynone(char *tmp, char *str, t_flag *fl, unsigned int size);
char			*applyzero(char *tmp, char *str, t_flag *fl);
char			*applyminus(char *tmp, char *str,
				t_flag *fl, unsigned int size);
void			printint(va_list var, t_fl *ft, t_flag *fl);
int				checkflags(char *str, int i, t_fl *ft, t_flag *fl);
int				validletter(char s);
void			printit(va_list var, t_fl *ft, t_flag *fl);
int				settype(char s, t_flag *fl, t_fl *ft);
#endif
