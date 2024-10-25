#############################################################
#                   M a k e f i l e 
# 
#     généré automatiquement le 23/10/2024 à 14:21:35
#         avec buildMakefile (version du  2 Sep 2023)
#                 (c) B. Froger 
# 
#############################################################

#------------------------------------------------------------
# Définition des variables
#------------------------------------------------------------
# de compilation
CC=g++
CCFLAGS=-Werror -Wall 
LDFLAGS= 

# de definition des répertoires
SRCDIR=src
INCDIR=inc
OBJDIR=obj
BINDIR=bin
INSTALLDIR=~/bin

# de definition des listes de fichiers a traiter
SRCCPP=$(wildcard $(SRCDIR)/*.cpp)
SRCC=$(wildcard $(SRCDIR)/*.c)
TMPCPP=$(patsubst %.cpp, %.o, $(SRCCPP))
TMPC=$(patsubst %.c, %.o, $(SRCC))
TMP=$(TMPCPP) $(TMPC)
OBJ=$(patsubst $(SRCDIR)/%.o, $(OBJDIR)/%.o, $(TMP))
EXEC = $(BINDIR)/jeuDeLaVie

# des autres variables
ENTETE = $(info ******************************) $(info *) $(info *   M A K E (jeuDeLaVie)) $(info *) $(info ******************************)

#------------------------------------------------------------
# Définition des règles génériques
#------------------------------------------------------------
ALL : $(info $(ENTETE)) $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $(LDFLAGS) $(OBJ) -o $@
	@echo "Edition de lien de $@ OK"

#------------------------------------------------------------
# Définition des règles pour chaque fichier source
#------------------------------------------------------------
$(OBJDIR)/afficheGrille.o: $(SRCDIR)/afficheGrille.cpp \
	$(INCDIR)/datas.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/aide.o: $(SRCDIR)/aide.cpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/allocMemoireGrille.o: $(SRCDIR)/allocMemoireGrille.cpp \
	$(INCDIR)/datas.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/analyseParametres.o: $(SRCDIR)/analyseParametres.cpp \
	$(INCDIR)/datas.hpp \
	$(INCDIR)/aide.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/calculEvolution.o: $(SRCDIR)/calculEvolution.cpp \
	$(INCDIR)/datas.hpp \
	$(INCDIR)/calculNbVoisins.hpp \
	$(INCDIR)/afficheGrille.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/calculNbVoisins.o: $(SRCDIR)/calculNbVoisins.cpp \
	$(INCDIR)/datas.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/chargeGrille.o: $(SRCDIR)/chargeGrille.cpp \
	$(INCDIR)/datas.hpp \
	$(INCDIR)/afficheGrille.hpp \
	$(INCDIR)/allocMemoireGrille.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp \
	$(INCDIR)/datas.hpp \
	$(INCDIR)/afficheGrille.hpp \
	$(INCDIR)/chargeGrille.hpp \
	$(INCDIR)/calculEvolution.hpp \
	$(INCDIR)/analyseParametres.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

#------------------------------------------------------------
# Définition des règles utilitaires
#------------------------------------------------------------
clean: 
	@rm -f $(OBJDIR)/* $(BINDIR)/*
	@echo "Clean OK"

info: 
	@echo "Liste des variables du makefile"
	@echo "CC         = " $(CC)
	@echo "CCFLAGS    = " $(CCFLAGS)
	@echo "LDFLAGS    = " $(LDFLAGS)
	@echo "SRCDIR     = " $(SRCDIR)
	@echo "INCDIR     = " $(INCDIR)
	@echo "OBJDIR     = " $(OBJDIR)
	@echo "BINDIR     = " $(BINDIR)
	@echo "INSTALLDIR = " $(INSTALLDIR)
	@echo "SRCCPP     = " $(SRCCPP)
	@echo "SRCC       = " $(SRCC)
	@echo "TMPCPP     = " $(TMPCPP)
	@echo "TMPC       = " $(TMPC)
	@echo "TMP        = " $(TMP)
	@echo "OBJ        = " $(OBJ)
	@echo "EXEC       = " $(EXEC)

install: 
	@make
	@rm -f $(INSTALLDIR)/jeuDeLaVie
	@cp -f $(BINDIR)/jeuDeLaVie ~/bin
	@chmod +x $(INSTALLDIR)/jeuDeLaVie
	@echo "installation de jeuDeLaVie dans ~/bin OK"
