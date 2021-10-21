# A Makefile to build the duplicates project.
PROJECT =  duplicates
HEADERS =  $(PROJECT).h
OBJ     =  duplicates.o strSHA2.o readFiles.o globals.o htable.o list.o dupDetect.o hardlink.o

C11     =  cc -std=c11
CFLAGS  =  -Wall -Werror -pedantic

$(PROJECT) : $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm

%.o : %.c $(HEADERS)
	$(C11) $(CFLAGS) -c $<