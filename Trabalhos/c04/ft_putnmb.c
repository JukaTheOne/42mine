#include <unistd.h>

void    put_array(int *array, int size)
{
    while(size >= 0)
    write(1, &array[--size], 1);
    write(1, "\n", 1);
}

void ft_putnbr(int nb)
{
    int i;
    int number[12];

    if (0 == nb)
        write(1, "0", 1);
    if  (nb < 0)
        write(1, "-", 1);
    i = 0;
    while(nb != 0)
    {
        if (nb[i] < 0)
        {
            number[i++] = (-1)*(nb % 10) + 48;
            nb = (-1)*(nb / 10);
        }
        else
        {
            number[i++] = (nb % 10) + 48;
            nb = (nb / 10);
        }
    }
    put_array(number, i);
}

int main(void)
{
    int    nbr;
    nbr = -2147483648;
    ft_putnbr(nbr);
}