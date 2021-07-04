/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:02:52 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/15 15:50:36 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define BUFFER_SIZE 1024
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_bmp_header
{
	unsigned int	bfsize;
	unsigned short	bfreserved1;
	unsigned short	bfreserved2;
	unsigned int	bfoffbits;
}					t_bmp_h;

typedef struct		s_bmp_infos
{
	unsigned int	bisize;
	int				biwidth;
	int				biheight;
	unsigned short	biplanes;
	unsigned short	bibitcount;
	unsigned int	bicompression;
	unsigned int	bisizeimage;
	int				bixpixelspermeter;
	int				biypixelspermeter;
	unsigned int	biclrused;
	unsigned int	biclrimportant;
}					t_bmp_i;

typedef struct		s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_cub
{
	int				x;
	int				y;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	size_t			**saved;
	int				save;
	int				fd;
	int				ret;
	int				data_found;
	int				empty_lines;
	int				nbr_line;
	int				len_line;
	char			*line;
	char			**map;
	char			*path_no;
	int				path_no_ispec;
	char			*path_so;
	int				path_so_ispec;
	char			*path_we;
	int				path_we_ispec;
	char			*path_ea;
	int				path_ea_ispec;
	char			*path_sp;
	int				path_sp_ispec;
	int				x_render_size;
	int				x_ispec;
	int				y_render_size;
	int				y_ispec;
	int				f_r;
	int				f_g;
	int				f_b;
	int				f_rgb;
	int				c_r;
	int				c_g;
	int				c_b;
	int				c_rgb;
	int				x_start;
	int				y_start;
	char			player;
	int				start_point;
	int				opened;
	int				cells;
	int				code;
	int				i;
	int				j;
}					t_cub;

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_var
{
	int				x_size_max;
	int				y_size_max;
	t_cub			*admp;
	int				len_line;
	int				nbr_line;
	t_sprite		*sp;
	int				w;
	int				h;
	size_t			**buffer;
	double			*zbuffer;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				**worldmap;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				drawstart;
	int				drawend;
	int				lineheight;
	int				x;
	int				y;
	int				texwidth;
	int				texheight;
	int				select_tex;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			wallx;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			movespeed;
	double			rotspeed;
	int				start_north;
	int				start_south;
	int				start_west;
	int				start_east;
	int				started;
	void			*north;
	void			*addr_no;
	int				w_no;
	int				h_no;
	int				bpp_no;
	int				len_no;
	int				endian_no;
	void			*south;
	void			*addr_so;
	int				w_so;
	int				h_so;
	int				bpp_so;
	int				len_so;
	int				endian_so;
	void			*west;
	void			*addr_we;
	int				w_we;
	int				h_we;
	int				bpp_we;
	int				len_we;
	int				endian_we;
	void			*east;
	void			*addr_ea;
	int				w_ea;
	int				h_ea;
	int				bpp_ea;
	int				len_ea;
	int				endian_ea;
	void			*sprite;
	void			*addr_sp;
	int				w_sp;
	int				h_sp;
	int				bpp_sp;
	int				len_sp;
	int				endian_sp;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texxs;
	int				d;
	int				texys;
	int				stripe;
	int				z;
	int				*sprite_order;
	double			*sprite_distance;
	int				n;
	int				i;
}					t_var;

void				ft_init_struct(t_cub *ad);
void				ft_print_map(t_cub *ad);
void				ft_print_lst(t_list *lst);
int					ft_add_res(char *elem, t_cub *ad);
void				ft_check_for_valid_map(char *s);
int					ft_add_north_tex(char *elem, t_cub *ad);
int					ft_add_south_tex(char *elem, t_cub *ad);
int					ft_add_west_tex(char *elem, t_cub *ad);
int					ft_add_east_tex(char *elem, t_cub *ad);
int					ft_add_sprite_tex(char *elem, t_cub *ad);
int					ft_add_floor_rgb(char *elem, t_cub *ad);
int					ft_add_ceiling_rgb(char *elem, t_cub *ad);
int					ft_valid_value(int a, int b, int c);
int					ft_is_digit(char c);
void				ft_skip_non_digit(char *s, int *i);
void				ft_skip_digit(char *s, int *i);
void				ft_goto_next(char *s, int *i);
int					ft_gnl(int fd, char **line);
int					ft_atoi(char *s);
int					ft_strlen(char *s);
size_t				ft_partcmp(char *s1);
char				*ft_memzero(size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *src);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(char *data);
void				ft_lstadd_back(t_list **lst, t_list *new_elem);
int					ft_stock_lines(t_list **lst, char *line);
int					ft_all_infos(t_cub *ad);
void				ft_clear_struct(t_cub *ad);
int					ft_select(char *elem, t_cub *ad);
char				*ft_dup(t_cub *ad, char *src, char *dst);
int					ft_check_lst(t_list *lst);
int					ft_copy_map(t_cub *ad, t_list *lst);
int					ft_find_dim(t_cub *ad, t_list *lst);
int					ft_launcher(t_cub *admp, t_list *lst);
int					ft_playable(t_cub *ad);
int					ft_valid_char(char c);
int					ft_player_start(t_cub *ad);
int					ft_commas(char *elem);
int					ft_player_start(t_cub *ad);
int					ft_check_borders(t_cub *ad);
int					ft_closed(t_cub *ad, int x, int y);
int					ft_check_closed(t_cub *ad);
void				ft_putstr_fd(char *s, int fd);
int					ft_exit_all(int code);
t_var				*ft_init(t_var *ad, t_cub *admp);
double				ft_rad(double degrees);
void				ft_mlx_tex(t_var *ad, int x, int y, size_t *color);
void				ft_mlx_sprite(t_var *ad, int x, int y, size_t *color);
void				ft_draw_buffer(t_var *ad);
void				ft_move_forward(t_var *ad);
void				ft_move_backward(t_var *ad);
void				ft_rotate_right(t_var *ad);
void				ft_rotate_left(t_var *ad);
int					ft_close(int keycode, void *param);
int					ft_keycode(int key, void *param);
void				*ft_raycast(t_var *ad, t_cub *admp);
unsigned int		ft_create_trgb(int t, int r, int g, int b);
void				ft_mlx_frame(t_var *ad, int x, int y, int color);
void				ft_draw_frame(t_var *ad, t_cub *admp);
void				*ft_load_xpm_files(t_var *ad, t_cub *admp);
void				ft_update(t_var *ad);
void				ft_select_texture(t_var *ad);
void				ft_step(t_var *ad);
void				ft_setup_for_raycast(t_var *ad);
void				ft_raycast_loop(t_var *ad);
void				ft_sprite_cast(t_var *ad);
void				ft_collision(t_var *ad);
void				ft_raycast_loop(t_var *ad);
void				ft_sort_sprites(int *spo, double *spd, int nbsp);
void				ft_set_sprites(t_var *ad, t_sprite *sp);
int					ft_count_sprites(t_var *ad);
double				ft_rad(double degrees);
t_sprite			*ft_setup_sprites(t_var *ad);
void				ft_transform(t_var *ad, t_sprite *sp);
void				ft_start_direction(t_var *ad);
int					ft_mlx_exit(int code);
void				ft_putstr_fd(char *s, int fd);
int					ft_raycasting(t_cub *admp);
int					ft_map(t_var *ad, t_cub *admp);
void				ft_player_start_pos(t_var *ad, t_cub *admp);
void				ft_init_refs_and_start_pos(t_var *ad, t_cub *admp);
int					ft_strcmp(char *s1, char *s2);
void				ft_save_frame(t_var *ad, t_cub *admp);
void				ft_save(t_cub *admp);
void				ft_save_buffer(t_var *ad, t_cub *admp);
int					ft_get_r(int trgb);
int					ft_get_g(int trgb);
int					ft_get_b(int trgb);
void				ft_init_bmp(t_bmp_h *bfh, t_bmp_i *bih, t_cub *admp);
char				*ft_get_path(char *src);

#endif
