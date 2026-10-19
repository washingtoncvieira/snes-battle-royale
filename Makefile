# Nome da ROM final
ROMNAME := game

# Diretórios padrão do PVSnesLib
PVSNESLIB_HOME ?= /opt/pvsneslib/pvsneslib

include $(PVSNESLIB_HOME)/devkitsnes/snes_rules

.PHONY: all

all: $(ROMNAME).sfc

