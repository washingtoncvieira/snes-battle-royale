# Nome do projeto
ROMNAME := game

# Ficheiros do projeto
SOURCES := main.c

include $(PVSNESLIB_HOME)/devkitsnes/snes_rules

.PHONY: all

all: $(ROMNAME).sfc

