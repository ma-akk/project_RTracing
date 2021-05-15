SRCS		= parser/init_object.c \
			  parser/parser.c \
			  parser/parser_base.c \
			  parser/parser_color.c \
			  parser/parser_shape.c \
			  parser/parser_vector.c \
			  parser/utils_parser.c  \
			  parser/valid_object.c \
			  math/math_alloc.c \
			  math/matrix_operation.c \
			  math/transform_matrix.c \
			  math/vector_operation.c \
			  math/vector_transform.c \
			  lights/lights.c \
			  lights/utils_lights.c\
			  tracing/utils_tracing.c \
			  tracing/sp_pl.c \
			  tracing/cy.c \
			  tracing/sq.c \
			  tracing/tr.c \
			  tracing/ray_tracing.c \
			  errors.c \
			  save_img.c \
			  shadow_ray_tracing.c \
			  utils_mlx.c \
			  render.c \
			  main.c \

OBJS		= ${SRCS:.c=.o}

NAME		= miniRT

CC          = gcc -framework OpenGL -framework Appkit

FLAGS		= -Wall -Wextra -Werror

HEADER		= mini_rt.h

LIBS      	= libmlx.dylib libft/libft.a

.c.o:
			gcc ${FLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${HEADER}
			${MAKE} bonus -C ./libft libft.a
			${MAKE} -C ./minilibx_mms
			cp ./minilibx_mms/libmlx.dylib libmlx.dylib
			$(CC) $(FLAGS) -I $(HEADER) $(LIBS) $(OBJS) -o $(NAME)

clean:
		    ${MAKE} clean -C ./libft
		    ${MAKE} clean -C ./minilibx_mms
		    rm -rf ${OBJS}

fclean:		clean
			${MAKE} fclean -C ./libft
			rm -rf libmlx.dylib
			rm -rf $(NAME)
			rm -rf "image.bmp"

re:		    fclean all

norm:	
		norminette $(SRCS) libft/* mini_rt.h parser/parser.h

.PHONY:	all clean fclean re
