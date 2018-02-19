/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:42:38 by aderby            #+#    #+#             */
/*   Updated: 2017/07/10 16:00:42 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include "../miniLibx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIN_H 900
# define WIN_L 1600
# define POINT (*wincon)->map->point
# define STRING1 "///////////////////////////////////////////////////"
# define STRING2 "////USE THE LEFT MOUSE BUTTON TO MOVE THE MODEL////"
# define STRING3 "////USE THE RIGHT MOUSE TO ROTATE THE MODEL    ////"
# define STRING4 "////USE THE MOUSE WHEEL TO ZOOM                ////"

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	long			color;
	int				tx;
	int				ty;
	struct s_point	*next;
	struct s_point	*right;
	struct s_point	*down;
}					t_point;

typedef struct		s_map
{
	t_point			*point;
}					t_map;

typedef struct		s_bres
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				d;
	int				s1;
	int				s2;
	int				swap;
	int				tmp;
	int				i;
}					t_bres;

typedef struct		s_wincon
{
	void			*win;
	void			*mlx;
	t_map			*map;
	int				row;
	int				col;
	int				mouse;
	int				rot;
}					t_wincon;

void				draw_image(t_wincon **wincon);
void				string_put(t_wincon **wincon);
void				blacken_points(t_wincon **wincon);
void				initialize_hooks(t_wincon *wincon);
void				draw_line(t_wincon **wincon, t_bres **b, int brd);
void				draw_lines_r(t_wincon **wincon, t_bres *bres);
void				draw_lines_d(t_wincon **wincon, t_bres *bres);
void				blacken_lines_r(t_wincon **wincon, t_bres *bres);
void				blacken_lines_d(t_wincon **wincon, t_bres *bres);
void				make_connection(t_wincon **wincon, int len, int col);
void				initialize_pts(t_wincon **wincon, int row, int col, int r);
void				pointnew(t_point **point);
int					translate(t_wincon *wincon, int x_dist, int y_dist);
int					key_release(int keycode, t_wincon *wincon);
int					scale(t_wincon *wincon, double multiplyer);
int					key_press(int keycode, t_wincon *wincon);
int					exit_program(void);
int					rotate_x(t_wincon *wincon, float degrees);
int					rotate_y(t_wincon *wincon, float degrees);
int					rotate_z(t_wincon *wincon, float degrees);
int					mouse_release(int button, int x, int y, t_wincon *wincon);
int					mouse_press(int button, int x, int y, t_wincon *wincon);
int					mouse_move(int x, int y, t_wincon *wincon);
int					get_color(char *color);
int					readfile(int fd, t_wincon **wincon, int i);
int					count_list(t_wincon **wincon);
t_wincon			*init(int fd);

#endif
