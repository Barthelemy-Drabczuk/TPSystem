#/**
#*
#* @File : nmakefile
#*
#*
#* @Synopsis : Makefile pour les TD/TP Systemes
#*
#**/
include ../include/INCLUDE_H
#
COMPILER = g++ -c -I$(INCLUDE) -Wall -O3 -Werror $*.cxx; mkdir -p ../lib; ar -cqs ../lib/libSys.a $*.o 

LIBBUILDER = mkdir -p ../lib; ar -cqs ../lib/libSys.a $*.o

#
# Edition de liens
#
$(nom) : codeobjsyst $(nom).o 
	g++ -s -o $(nom).run $(nom).o -L../lib -lSys
#
$(nom).o : $(nom).cxx $(CEXC_H) $(NSSYSTEME_H)
	$(COMPILER)
#
# Code Objet pour la bibliotheque Systemes
# 
codeobjsyst: 
	make general
#
general:    nsSysteme.o   
#
nsSysteme.o : nsSysteme.cxx $(CEXC_H) $(NSSYSTEME_H)
	$(COMPILER); $(LIBBUILDER)
#
# Nettoyage du repertoire courant : executables et fichiers .o
#
clean : 
	clear; rm -rf *.o *.run ../lib -v *~ ../include/*~
#





