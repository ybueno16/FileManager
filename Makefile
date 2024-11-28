# Nome do executável
TARGET = main

# Arquivos de origem
SRCS = main.c directory_manager.c

# Arquivos objetos (gerados a partir dos .c)
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -g

# Regra padrão (primeira regra é a padrão)
all: $(TARGET)

# Como criar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Como compilar os arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos temporários
clean:
	rm -f $(OBJS) $(TARGET)
