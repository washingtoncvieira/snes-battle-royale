# Nome do projeto e da ROM final
ROMNAME := game

include $(PVSNESLIB_HOME)/devkitsnes/snes_rules

.PHONY: all

all: $(ROMNAME).sfc
