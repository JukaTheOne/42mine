/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:55:38 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/12 20:55:38 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_key(int keycode, void *param)
{
    t_fractol *f;
 
    // printf("keycode: %d\n", keycode);
    f = (t_fractol *)param;
    if(keycode == 65307)
    {
        //exit_free(f);
        mlx_destroy_window(f->mlx, f->win);
        exit(0);
    }
    if (keycode == 65361 || keycode == 65363 || keycode == 65362 || keycode == 65364)
        move_img(keycode, f);
    if (keycode == 44 || keycode == 46)
        zoom_times(keycode, f);
    if (keycode == 114) //(r)
        reset_fractol(f); //recalls parcel_args
    // if (keycode == 99) //(c) //TODO upgrade colour palet and 
        //change_palete(1, f);
    //if (keycode >= 49 && keycode <= 57) //(1-9)
        //change_palete(keycode - 48, f);
    // if (keycode == 108) //(l)
        //f->loop_colour = 1;
    // if (keycode == 107) //(k)
        //f->loop_zoom = 1;
    return 0;
}
int handle_mouse(int button, int x, int y, void *param)
{
    t_fractol *f;
 
    // printf("button: %d\n", button);
    // printf("x: %d y: %d\n", x, y);
    f = (t_fractol *)param;
    if(button == 4 || button == 5) //up down
        mouse_zoom(button, x, y, f);
    if(button == 3) 
        mouse_zoom(button, x, y, f);
    // if button 4 print coord
    return 0;
}

int handle_close(void *param)
{
    t_fractol *f = (t_fractol *)param;
    //free(f); and exit
    mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
    exit(0);
}

//////////////////
//////////////////      NEW FILE
//////////////////
//////////////////

void    reset_fractol(t_fractol *f)
{
    t_info *info;
    
	info = f->info.backup;
    f->info = *info;
    f->info.backup = info;
    f->info.update = 1;
    recalc_vals(f);
}

// static void	zoom(t_fractol *f, double zoom)
// {
// 	double	center_r;
// 	double	center_i;

// 	center_r = f->min_r - f->max_r;
// 	center_i = f->max_i - f->min_i;
// 	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
// 	f->min_r = f->max_r + zoom * center_r;
// 	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
// 	f->max_i = f->min_i + zoom * center_i;
// }//TODO

void    zoom_times(int keycode, t_fractol *f)
{
    float zoom_dir;

    zoom_dir = (45.0f - (float) keycode);//confusing
    if (zoom_dir > 0)
        f->info.s_zoom *= 1.2f;
    else if (zoom_dir < 0)
        f->info.s_zoom /= 1.2f;
    f->info.update = 1;
    recalc_vals(f);
    return ;
}

void    move_img(int keycode, t_fractol *f)
{
    t_complex  shift;

    if(keycode == 65361 || keycode == 65363) //left or right
    {
        shift.x =  40.0f * (f->info.step_array[1] - f->info.step_array[0]) * (float) (keycode - 65362);
        f->info.pos.x += shift.x; // + f->info.radius.x * 2;
    }
    else if(keycode == 65362 || keycode == 65364) //up or down
    {
        shift.y =  40.0f * (f->info.step_array[WIDTH + 1] - f->info.step_array[WIDTH]) * (float) (keycode - 65363);
        f->info.pos.y += shift.y; // + f->info.radius.y * 2;
    }
    //partial_map(f, shift); //TODO partial_map upgrade
    f->info.update = 1;
    recalc_vals(f);
    return ;
}

void mouse_zoom(int button, int x, int y, t_fractol *f)
{
    t_info info;
    
	info = f->info;
    button = (4 - button);
    if (button == 0)
        f->info.s_zoom *= 1.2f;
    else if (button < 0)
        f->info.s_zoom /= 1.2f; //TODO reorganize main struct
    f->info.pos.x += (x * (f->info.step_array[1] - f->info.step_array[0])) - info.radius.x;
    f->info.pos.y += (y * (f->info.step_array[WIDTH + 1] - f->info.step_array[WIDTH])) - info.radius.y;
    f->info.update = 1;
    recalc_vals(f);
    return ;
}

//loops
//