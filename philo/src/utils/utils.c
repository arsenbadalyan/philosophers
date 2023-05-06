#include "philo.h"

int ft_atoi(const char *str)
{
    int i;
    unsigned int num;
    int sym_counter;

    i = 0;
    num = 0;
    sym_counter = 1;
    while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v') && str[i])
        i++;
    while ((str[i] == '-' || str[i] == '+') && str[i])
    {
        if (str[i++] == '-')
            sym_counter = -1;
        break;
    }
    while ((str[i] >= '0' && str[i] <= '9') && str[i])
        num = num * 10 + (str[i++] - 48);
    return ((int)(num * sym_counter));
}

void ft_putstr_fd(char *s, int fd)
{
    size_t i;

    i = 0;
    if (!s)
        return;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

void ft_putnbr_fd(int n, int fd)
{
    if (n == 0)
    {
        write(fd, "0", 1);
        return;
    }
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n *= -1;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
    {
        ft_putchar_fd(n + '0', fd);
    }
}

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
