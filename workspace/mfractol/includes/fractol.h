// #include <libft.h>
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1280
# define HEIGHT 800
# define MAXI 120
# define PI 3.142

typedef struct s_complex 
{
    float x;
    float y;
} 				t_complex;

typedef struct	s_data //data structure for the image
{
	char	*addr;
	void	*img;
	int		bpp;
	int		len_line;
	int		endian;
	int		size[2];
	float	*matrix; //here or in f struct
	float 	zoom;
}				t_data;

typedef struct s_info 
{
	struct s_info	*backup;
	int update;
	int maxi;
	float s_zoom;
	float threshold;
	t_complex pos;
	t_complex radius;
	t_complex step;
	float *array;
	float *step_array;
} 				t_info; 

typedef struct s_fractol //data structure for the fractal
{
	char *name;
	void *mlx;
	void *win;
	t_data img;
	t_info info;
}               t_fractol;

//main
void	init_mlx(t_fractol *f);
int		main(void);
//utils main
void parcel_args(t_fractol *f);
void my_pixel_put(t_data *img, int x, int y,int colour);
void create_val_array(t_fractol *f);
void    create_step_array(t_fractol *f);


//draw map functions
float	actualfractol(t_complex coord, t_fractol *f, float threshold);
void map_values(t_fractol *f);
//// void    partial_map(t_fractol *f, t_complex shift);
void	recalc_vals(t_fractol *f);
//colour functions
void get_colours(t_fractol *f); //, unsigned int colour);
unsigned int set_colour(float val);
//events
int handle_key(int keycode, void *param);
int handle_mouse(int button, int x, int y, void *param);
//events utils
int handle_close(void *param);
void    reset_fractol(t_fractol *f);
void    move_img(int keycode, t_fractol *f);
void    zoom_times(int times, t_fractol *f);
void mouse_zoom(int button, int x, int y, t_fractol *f);

int animate_image(void *param);


#endif
