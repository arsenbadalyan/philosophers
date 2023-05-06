#ifndef UTILS_H
#define UTILS_H

// 42 functions
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

// Error handling
int		force_quit(int errno, philos_t *philos);
void	*mem_issue(philos_t *philos);

// Free memory
void *free_single(void **addr);
void *free_double(void ***addr);
void *free_all_mem(philos_t *philos);

#endif