# Variáveis de compilação
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =

# Diretórios de inclusão e biblioteca
INCLUDE_DIR = ./include
LIBRARY_DIR = ./lib

# Arquivos de código-fonte
SRC = main.c crypto.c
OBJ = $(SRC:.c=.o)

# Nome do executável
EXEC = encryptor

# Regra padrão para compilar o programa
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpeza dos arquivos de compilação
clean:
	rm -f $(OBJ) $(EXEC)

# Para depurar
debug:
	$(CC) $(CFLAGS) -g $(SRC) -o $(EXEC) $(LDFLAGS)
