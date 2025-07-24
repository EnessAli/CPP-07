NAME = iter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj
INCDIR = .

SOURCES = main.cpp
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BOLD)$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(BOLD)$(GREEN)$(NAME) created successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@echo "$(BOLD)$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(BOLD)$(RED)Cleaning executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
