SDIR				=	src
ODIR				=	obj
HDIR				=	inc
LIB_DIR				=	libft
NAME				=	fractol

CC					=	gcc
CFLAGS				=	-g -Wall -Wextra -Werror -O3 -fopenmp -I$(HDIR)

VPATH				=	$(SDIR):$(HDIR)

MAKE_LIB			=	@make --no-print-directory -C

PRINTF_DIR			=	$(LIB_DIR)/printf
PRINTF_FILE			=	printf.a 	
PRINTF				=	$(PRINTF_DIR)/$(PRINTF_FILE)
CFLAGS				+=	-I$(PRINTF_DIR)/include
LIB					+=	$(PRINTF)

LIBFT_DIR			=	$(LIB_DIR)/libft
LIBFT_FILE			=	libft.a
LIBFT				=	$(LIBFT_DIR)/$(LIBFT_FILE)
CFLAGS				+=	-I$(LIBFT_DIR)/include
LIB					+=	$(LIBFT)

MINILIBX_DIR		=	minilibx
MINILIBX_FILE		=	libmlx.a
MINILIBX			=	$(MINILIBX_DIR)/$(MINILIBX_FILE)
CFLAGS				+=	-I$(MINILIBX_DIR) 
LIB					+=	$(MINILIBX)	

SRCS				=	main.c event.c init.c utils.c fractols.c palletes.c palletes2.c render.c keyboard.c
SRCS				+=	thread.c	
OBJS				:=	$(patsubst %.c, $(ODIR)/%.o, $(SRCS))

DIRS				=	$(ODIR)

all: $(NAME)

$(NAME): $(LIB) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@ -L$(MLX_PATH) -lmlx -lX11 -lXext -lm -lpthread

$(ODIR)/%.o: %.c | $(DIRS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(DIRS):
	@mkdir -p $@

$(PRINTF):
	$(MAKE_LIB) $(PRINTF_DIR)

$(LIBFT):
	$(MAKE_LIB) $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE_LIB) $(MINILIBX_DIR)

lib_clean:
	$(MAKE_LIB) $(PRINTF_DIR) clean
	$(MAKE_LIB) $(LIBFT_DIR) clean
	$(MAKE_LIB) $(MINILIBX_DIR) clean

lib_fclean:
	$(MAKE_LIB) $(PRINTF_DIR) fclean
	$(MAKE_LIB) $(LIBFT_DIR) fclean

clean: lib_clean
	@rm -rf $(ODIR)

fclean: clean lib_fclean 
	@rm -rf $(NAME)

re: fclean $(LIB) all

.PHONY: all bonus clean fclean re
