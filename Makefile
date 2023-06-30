NAME			= philo
LIBFT			= libft.a

SRCS			=	ft_main.c \
					parsing/ft_parsing.c \
					parsing/ft_init.c \
					parsing/utils/ft_lst_alt.c \
					parsing/utils/ft_parsing_utils.c \
					routine/ft_routine.c \
					routine/ft_eat.c \
					routine/ft_fork.c \
					routine/ft_sleep.c \
					routine/ft_time.c \
					routine/utils/ft_routine_utils.c \
					routine/utils/ft_check_status.c \
					routine/utils/ft_handle_error.c \
					utils/ft_error_1.c \
					utils/ft_error_2.c \
					utils/ft_clean.c \
					utils/ft_main_utils.c \
					monitoring/ft_monitor.c

SRCS_DIR		= ./srcs
BUILD_DIR       = .build
INCLUDES_DIR	= ./includes
LIBFT_DIR		= ./libft

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.c=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC				= cc
CFLAGS          = -Wall -Werror -Wextra #-fsanitize=thread  
HFLAGS			= -I $(INCLUDES_DIR) -I $(LIBFT_DIR)/includes

all						: ${NAME}

${NAME}         		: ${OBJS}
			${CC} $(OBJS) -o $(NAME) -Llibft -lft -pthread

${BUILD_DIR}/%.o		: $(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) $(BUILD_DIR)
			${CC} -g3 $(HFLAGS) ${CFLAGS} -c $< -o $@ 

$(LIBFT_DIR)/$(LIBFT)	:
			make -C $(LIBFT_DIR)

$(BUILD_DIR)			:
			mkdir $(BUILD_DIR)
			mkdir $(BUILD_DIR)/monitoring
			mkdir $(BUILD_DIR)/parsing
			mkdir $(BUILD_DIR)/parsing/utils
			mkdir $(BUILD_DIR)/routine
			mkdir $(BUILD_DIR)/routine/utils
			mkdir $(BUILD_DIR)/utils

clean					:
			make -C $(LIBFT_DIR) clean
			rm -rf ${OBJS}

fclean					: clean
			rm -rf ${NAME} $(LIBFT_DIR)/$(LIBFT)

re						: fclean all

.PHONY					: all clean fclean re