/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:09:50 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/28 13:43:16 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define BS 2000
# define NO_CONV 1
# define CONV_SUCCEED 1
# define ULLMAX 20

/*
** structs
*/
typedef struct		s_size
{
	char			buf[BS];
	int				no;
	int				op;
	int				er;
}					t_size;

typedef struct		s_fwp
{
	int				fi;
	int				fc;
	int				wi;
	int				pr;
}					t_fwp;

typedef struct		s_dif
{
	int				al;
	int				pl;
	int				wl;
	int				cp;
}					t_dif;
/*
** enums
*/
typedef enum		e_flags
{
	fl_ha = 0X01,
	fl_ze = 0X02,
	fl_mi = 0X04,
	fl_pl = 0X08,
	fl_sp = 0X10,
	fl_ne = 0X20,
	fl_pr = 0X40,
}					t_flags;

typedef enum		e_conv
{
	fl_h = 0X01,
	fl_hh = 0X02,
	fl_l = 0X04,
	fl_ll = 0X08,
	fl_j = 0X10,
	fl_z = 0X20,
}					t_conv;
typedef enum		e_mask
{
	msk_1 = 0X0000C080,
	msk_2 = 0X00D08080,
	msk_3 = 0XF0808080,
}					t_mask;
/*
** prototypes
*/
int					ft_printf(const char *format, ...);
void				init_size(t_size *sz);
/*
** parsing
*/
void				init_fwp(t_fwp *fwp);
int					parser(va_list valist, const char *format, t_size *sz);
void				iflags(char *p, t_fwp *fwp);
void				cflag(char *p, t_fwp *fwp, const char *next);
/*
** conversion
*/
int					converter(va_list valist, t_size *sz,
		const char c, t_fwp *fwp);
int					conv_cs(va_list valist, t_size *sz, char c, t_fwp *fwp);
int					conv_si(va_list valist, t_size *sz, char c, t_fwp *fwp);
int					conv_oux(va_list valist, t_size *sz, char c, t_fwp *fwp);
/*
** stock
*/
void				stock_s(char *arg, t_size *sz, t_fwp *fwp);
void				stock_c(unsigned char arg, t_size *sz, t_fwp *fwp);
void				stock_ws(wchar_t *arg, t_size *sz, t_fwp *fwp);
void				stock_wc(wchar_t arg, t_size *sz, t_fwp *fwp);
void				stock_si(long long arg, t_size *sz, t_fwp *fwp);
void				stock_oux(size_t arg, char c, t_size *sz, t_fwp *fwp);
void				stock_us(size_t arg, t_size *sz, t_fwp *fwp);
void				stock_oc(size_t arg, t_size *sz, t_fwp *fwp);
void				stock_hx(size_t arg, char c, t_size *sz, t_fwp *fwp);
int					stock_pt(void *arg, char c, t_size *sz, t_fwp *fwp);
int					stock_n(int *arg, t_size *sz);
/*
** indentation
*/
void				ft_putwchar(wchar_t arg, t_size *sz);
int					putnull(t_size *sz);
void				fill_ze(t_size *sz, int nsp);
void				fill_sp(t_size *sz, int nsp);
void				putsign(t_size *sz, t_fwp *fwp);
void				put_hex_prfx(t_size *sz, char c);
void				itoa_unsigned(unsigned long long arg, char *buf, int len);
void				itoa_deci(long long arg, char *buf, int len);
void				itoa_octal(size_t arg, char *buf, int len);
void				itoa_hexa(size_t arg, char *buf, int len, char c);
void				idt_normls(char *arg, t_dif *df, t_size *sz);
void				idt_normlc(char arg, t_size *sz);
void				idt_normlsi(long long arg, t_dif *df,
		t_size *sz, t_fwp *fwp);
void				idt_normlus(size_t arg, t_dif *df, t_size *sz);
void				idt_normloc(size_t arg, t_dif *df, t_size *sz);
void				idt_normlhx(size_t arg, t_dif *df, t_size *sz, char c);
void				idt_normlpt(void *arg, t_dif *df, t_size *sz, char c);
void				idt_rights(char *arg, t_dif *df, t_size *sz);
void				idt_rightc(char arg, t_size *sz, t_fwp *fwp);
void				idt_rightsi(long long arg, t_dif *df,
		t_size *sz, t_fwp *fwp);
void				idt_rightus(size_t arg, t_dif *df, t_size *sz);
void				idt_rightoc(size_t arg, t_dif *df, t_size *sz);
void				idt_righthx(size_t arg, t_dif *df, t_size *sz, char c);
void				idt_rightpt(void *arg, t_dif *df, t_size *sz, char c);
void				idt_zeros(char *arg, t_dif *df, t_size *sz);
void				idt_zeroc(char arg, t_size *sz, t_fwp *fwp);
void				idt_zerosi(long long arg, t_dif *df,
		t_size *sz, t_fwp *fwp);
void				idt_zerous(size_t arg, t_dif *df, t_size *sz);
void				idt_zerooc(size_t arg, t_dif *df, t_size *sz);
void				idt_zerohx(size_t arg, t_dif *df, t_size *sz, char c);
void				idt_zeropt(void *arg, t_dif *df, t_size *sz, char c);
void				idt_lefts(char *arg, t_dif *df, t_size *sz);
void				idt_leftc(char arg, t_size *sz, t_fwp *fwp);
void				idt_leftsi(long long arg, t_dif *df,
		t_size *sz, t_fwp *fwp);
void				idt_leftus(size_t arg, t_dif *df, t_size *sz);
void				idt_leftoc(size_t arg, t_dif *df, t_size *sz);
void				idt_lefthx(size_t arg, t_dif *df, t_size *sz, char c);
void				idt_leftpt(void *arg, t_dif *df, t_size *sz, char c);
/*
** helpers
*/
void				fillbuffer(unsigned char c, t_size *sz);
void				init_size(t_size *sz);
#endif
