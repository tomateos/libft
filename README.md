Implemented libc functions and some others using only malloc, free and write.
Functions were not necessarily written in most efficient manner, rather they
were written to comply with the Norm at 42. The library will be used in future
C projects at 42.

The following functions were implemented for the make file:
-make all: generates object files for every source file, then creates libft.a
-make clean: removes object files
-make fclean: removes object files and libft.a
-make re: removes object files and libft.a, then remakes libft.a
