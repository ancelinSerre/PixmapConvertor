CC=gcc
LIB_DIR=../../lib
INC_DIR=../the_headers
BIN_DIR=../bin

OPTIM=-O2
OPTIONS= $(OPTIM) -g -fPIC

OBJECTS=readimg.o struct.o main.o writeimg.o processing.o

all: $(BIN_DIR)/main $(LIB_DIR)/pixmaplib.a $(LIB_DIR)/pixmaplib.so clean_obj
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

# Bibliothèque statique
$(LIB_DIR)/pixmaplib.a: $(OBJECTS)
	rm -f $@
	ar -r $@ $^

# Bibliothèque dynamique
$(LIB_DIR)/pixmaplib.so: $(OBJECTS)
	rm -f $@
	gcc -shared -o $@ $^

# Commande de nettoyage intermediaire (sans executables et lib)
clean_obj:
	rm -rf *.o
	rm -rf $(INC_DIR)/*.gch

# Commande de nettoyage totale (avec executables et lib)
clean:
	make clean_obj
	rm -rf $(BIN_DIR)/main
	rm -rf $(LIB_DIR)/pixmaplib.a $(LIB_DIR)/pixmaplib.so