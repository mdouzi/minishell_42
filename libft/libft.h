/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:25 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 22:20:43 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE_LOW "0123456789abcdef"
# define BASE_UP "0123456789ABCDEF"

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, int len);
int		ft_strlen(const char *s);
void	ft_bzero(void *s, int n);
void	*ft_memmove(void *dst, const void *src, int len);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strchr(char *s, char c);
int		ft_indexchr(char *s, char c);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strncmp(const char *s1, const char *s2, int n);
long	ft_atoi(char *str);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
int		ft_strlcat(char *dst, const char *src, int dstsize);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_putstr(char *s);
int		ft_argprint(va_list p, char c);
int		ft_putchar(char c);
int		ft_putnbrhex(long b, char *base);
int		ft_putnbr(long n);
int		ft_unsigned(unsigned int k);
int		ft_printf(char *s, ...);

#endif
