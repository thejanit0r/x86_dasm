#
#   This file is part of x86_dasm.
#
#   x86_dasm is a compact x86-64 disassembling library
#   
#   Copyright 2014 / the`janitor / < email: base64dec(dGhlLmphbml0b3JAcHJvdG9ubWFpbC5jb20=) >
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#

# To avoid "missing separator" errors when TABs get converted to spaces
ifeq ($(origin .RECIPEPREFIX), undefined)
  $(error Variable .RECIPEPREFIX is unsupported, upgrade to GNU Make 4.0 or later)
endif
.RECIPEPREFIX = >

# Programs
CC = gcc
AS = nasm
CFLAGS = -Wall -Iinclude/ -std=c99 -O3 # -DX86_DASM_DEBUG
LFLAGS = -s
AFLAGS = -f bin

SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

SOURCES_C = $(wildcard $(SRC_DIR)/*.c)
OBJECTS_C = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES_C:.c=.o))

all: x86_dasm

x86_dasm: $(OBJECTS_C)
> $(CC) $(LFLAGS) $^ -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
> $(CC) $(CFLAGS) -c $< -o $@

clean:
> rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*
    
rebuild: clean all
    
.PHONY : clean
.SILENT : clean
