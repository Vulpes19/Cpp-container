#* TARGETS *#
VECTOR = test_vector

#* SRC FILES *#
V_FILE = vector_main.cpp

#* OBJECT FILES *#
V_OBJ = vector_main.o

#* FLAGS *#
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

#* INCLUDE PATHS *#
V_INCLUDE = Vector/
IT_INCLUDE = Iterator/
TYPE_INCLUDE = TypeTraits/

#* DELETE *#
DEL = rm -rf

all: $(VECTOR)

$(V_OBJ): $(V_FILE)
	@g++ $(CFLAGS) -I $(V_INCLUDE) -I $(IT_INCLUDE) -I $(TYPE_INCLUDE) -c $(V_FILE)
	@echo "Vector test object files created"

$(VECTOR): $(V_OBJ)
	@g++ $(CFLAGS) -I $(V_INCLUDE) -I $(IT_INCLUDE) -I $(TYPE_INCLUDE) $(V_OBJ) -o $(VECTOR)
	@echo "Vector test compiled"

re: fclean all

clean:
	@$(DEL) $(V_OBJ)
	@echo "Vector test object files deleted"

fclean: clean
	@$(DEL) $(VECTOR)
	@echo "Vector test binary deleted"

.PHONY: all re clean fclean
