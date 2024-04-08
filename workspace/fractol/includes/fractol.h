// #include <libft.h>
# include <mlx.h>

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define LENGTH 800
# define MAXI 200


typedef struct {
    double x;
    double y;
} Point;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
