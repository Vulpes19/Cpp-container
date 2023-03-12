#* TARGETS *#
VECTOR = test_vector
STACK = test_stack
MAP = test_map

#* SRC FILES *#
V_FILE = vector_main.cpp

#* OBJECT FILES *#
V_OBJ = vector_main.o

#* FLAGS *#
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

#* INCLUDE PATHS *#
V_INCLUDE = Vector/
IT_INCLUDE = Iterators/
TYPE_INCLUDE = TypeTraits/
ALGO_INCLUDE = Algorithm/
UTIL_INCLUDE = Utility/

#* DELETE *#
DEL = rm -rf

all: $(VECTOR) $(STACK) $(MAP)

vector: $(VECTOR)

$(V_OBJ): $(V_FILE) $(V_INCLUDE) $(IT_INCLUDE) $(TYPE_INCLUDE) $(UTIL_INCLUDE) $(ALGO_INCLUDE)
	@c++ $(CFLAGS) -I $(V_INCLUDE) -I $(IT_INCLUDE) -I $(TYPE_INCLUDE) -I $(UTIL_INCLUDE) -I $(ALGO_INCLUDE) -c $(V_FILE)
	@echo "Vector test object files created"

$(VECTOR): $(V_OBJ) $(V_FILE) $(V_INCLUDE) $(IT_INCLUDE) $(TYPE_INCLUDE) $(UTIL_INCLUDE) $(ALGO_INCLUDE)
	@c++ $(CFLAGS) -I $(V_INCLUDE) -I $(IT_INCLUDE) -I $(TYPE_INCLUDE) -I $(UTIL_INCLUDE) -I $(ALGO_INCLUDE) $(V_OBJ) -o $(VECTOR)
	@echo "Vector test compiled"

re: fclean all
rev: fclean vector
res: fclean stack
rem: fclean map

clean:
	@$(DEL) $(V_OBJ)
	@echo "Vector test object files deleted"

fclean: clean
	@$(DEL) $(VECTOR)
	@echo "Vector test binary deleted"

.PHONY: all re clean fclean
