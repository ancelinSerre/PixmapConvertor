CC=gcc
LIB_DIR=../../lib
INC_DIR=../the_headers
BIN_DIR=../bin

OPTIM=-O2
OPTIONS= $(OPTIM) -g

OBJECTS=readimg.o struct.o main.o write_img.o
FINAL=main

# Liste des commandes n'étant pas liés à des fichiers
.PHONY: clean all clean_obj

#Commande pour build main et le placer dans le dossier bin
$(BIN_DIR)/main : $(OBJECTS)
	$(CC) $(OPTIONS) -o $@ $^

# compile tous les .c en prenant en compte les .h en .o (fichiers objets intermédiaires)
%.o : %.c $(INC_DIR)/%.h
	$(CC) $(OPTIONS) -c $^

main.o : main.c 
	$(CC) $(OPTIONS) -c $^

# Commande de nettoyage intermediaire (sans executables)
clean_obj:
	rm -rf *.o
	rm -rf $(INC_DIR)/*.gch

# Commande de nettoyage totale (avec executables)
clean:
	make clean_obj
	rm -rf $(BIN_DIR)/$(FINAL)