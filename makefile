CC = g++

CFLAGS = -Wall -std=c++17 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations   \
		 -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy     \
		 -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2     \
		 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith       \
		 -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo           \
		 -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef   \
		 -Wunreachable-code -Wunused -Wvariadic-macros -Wno-literal-range 			     \
		 -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast 			 \
		 -Wno-varargs -Wstack-protector -Wsuggest-override -Wbounds-attributes-redundant \
		 -Wlong-long -Wopenmp -fcheck-new -fsized-deallocation -fstack-protector 		 \
		 -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-protector  \
		 -fPIE -Werror=vla -fsanitize=address

SOURCE = 

OBJ = &(SOURCE:.cpp = .o)

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -lm

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) all

.PHONY: clean
