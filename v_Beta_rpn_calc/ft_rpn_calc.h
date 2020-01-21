#ifndef FT_RPN_CALC
# define FT_RPN_CALC

#include <stdio.h>
#include <stdlib.h>

int ft_check(char *str);
int ft_isspace(char c);
int ft_isdigit(char c);
int ft_isop(char c);
int ft_nbr_word(char *str);
char *ft_cat_word(char *str, int *id);
char    **ft_split(char *str);
int ft_rpn_calc(char *str);

#endif