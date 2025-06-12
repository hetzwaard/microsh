# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror 
LIBS = -L$(LIBFTDIR) -lft
INCLUDES = -Iinclude

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = include
LIBFTDIR = include/libft
LIBFT = $(LIBFTDIR)/libft.a

# Source files and object files
SRCS = $(SRCDIR)/microsh.c
SRCS += $(SRCDIR)/utils/getcwd.c
SRCS += $(SRCDIR)/utils/malloc.c
SRCS += $(SRCDIR)/utils/realloc.c
SRCS += $(SRCDIR)/utils/execve.c
SRCS += $(SRCDIR)/utils/wait.c
SRCS += $(SRCDIR)/utils/fork.c
SRCS += $(SRCDIR)/utils/banner.c
SRCS += $(SRCDIR)/micro/micro_coms.c
SRCS += $(SRCDIR)/micro/micro_line.c
SRCS += $(SRCDIR)/micro/micro_path.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Output executable
NAME = microsh

# Colors for output
GREEN		=	\033[0;32m
ORANGE	=	\033[38;5;214m
GRAY		=	\033[0;90m

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(GRAY)building microsh..."
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created successfully"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFT):
	@echo "$(GRAY)building libft..."
	@make -C $(LIBFTDIR) > /dev/null
	@echo "$(GREEN)libft has been created successfully"

clean:
	@echo "$(ORANGE)removing object files..."
	@rm -rf $(OBJDIR)
	@echo "$(ORANGE)objects have been removed"

fclean: clean
	@echo "$(ORANGE)removing $(NAME)..."
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean > /dev/null
	@echo "$(ORANGE)$(NAME) has been removed"

re: fclean all

.PHONY: all clean fclean re
