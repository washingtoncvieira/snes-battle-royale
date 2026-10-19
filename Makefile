ROMNAME := game
PVSNESLIB_HOME ?= /opt/pvsneslib/pvsneslib

include $(PVSNESLIB_HOME)/devkitsnes/snes_rules

.PHONY: all

all: $(ROMNAME).sfc

