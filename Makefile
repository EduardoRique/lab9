INC_DIR = ./include
SRC_DIR = ./src
DOC_DIR = ./doc
OBJ_DIR = ./build
BIN_DIR = ./bin
LIB_DIR = ./lib

CC      = g++
CFLAGS  = -Wall -pedantic -std=c++11 -ansi -I. -I$(INC_DIR) -g
ARCHIVE = ar

linux: clean eduardo.a eduardo.so prog_estatico prog_dinamico doxy

windows: clean eduardo.lib eduardo.dll prog_estatico.exe prog_dinamico.exe doxy

#LINUX
eduardo.a: $(SRC_DIR)/eduardo.cpp $(INC_DIR)/pilha.h $(INC_DIR)/lista.h $(INC_DIR)/busca.h $(INC_DIR)/eduardo.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/eduardo.cpp -o $(OBJ_DIR)/eduardo.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/eduardo.o
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

eduardo.so: $(SRC_DIR)/eduardo.cpp $(INC_DIR)/pilha.h $(INC_DIR)/lista.h $(INC_DIR)/busca.h $(INC_DIR)/eduardo.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/eduardo.cpp -o $(OBJ_DIR)/eduardo.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/eduardo.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/eduardo.a -o $(BIN_DIR)/$@

prog_dinamico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/eduardo.so -o $(BIN_DIR)/$@


#WINDOWS
eduardo.lib: $(SRC_DIR)/eduardo.cpp $(INC_DIR)/pilha.h $(INC_DIR)/lista.h $(INC_DIR)/busca.h $(INC_DIR)/eduardo.h
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/eduardo.o
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

eduardo.dll: $(SRC_DIR)/eduardo.cpp $(INC_DIR)/pilha.h $(INC_DIR)/lista.h $(INC_DIR)/busca.h $(INC_DIR)/eduardo.h
	$(CC) -shared -o $(LIB_DIR)/$@ $(OBJ_DIR)/eduardo.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/eduardo.lib -o $(BIN_DIR)/$@

prog_dinamico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/eduardo.dll -o $(BIN_DIR)/$@

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	@echo "Removendo arquivos objeto..."
	@rm -rf $(OBJ_DIR)/*
	@rm -rf $(DOC_DIR)/*