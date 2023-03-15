#* TARGETS *#
VECTOR = test_vector
STACK = test_stack
MAP = test_map

#* SRC FILES *#
V_FILE = vector_main.cpp
M_FILE = map_main.cpp

#* OBJECT FILES *#
V_OBJ = vector_main.o
M_OBJ = map_main.o

#* FLAGS *#
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

#* INCLUDE PATHS *#
V_INCLUDE = Vector/
M_INCLUDE = Map/
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

map: $(MAP)

$(M_OBJ): $(M_FILE)
	@c++ $(CFLAGS) -I $(M_INCLUDE) -c $(M_FILE)
	@echo "Map test object files created"

$(MAP): $(M_OBJ)
	@c++ $(CFLAGS) -I $(M_INCLUDE) $(M_OBJ) -o $(MAP)
	@echo "Map test compiled"

re: fclean all
rev: fclean vector
res: fclean stack
rem: fclean map

clean:
	@$(DEL) $(V_OBJ) $(M_OBJ)
	@echo "all test object files deleted"

fclean: clean
	@$(DEL) $(VECTOR) $(MAP)
	@echo "all test binary deleted"

.PHONY: all re clean fclean
