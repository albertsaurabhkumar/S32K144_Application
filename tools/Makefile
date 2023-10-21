#Makefile for S32K144 Application

#Compiler Directories
CC_DIR = E:/S32_App/tools/CC/gcc-10.3
CC_BIN = $(CC_DIR)/bin
CC_INC = $(CC_DIR)/include
CC_LIB = $(CC_DIR)/lib

#Compilar Path
CC = $(CC_BIN)/arm-none-eabi-gcc

#Project Name
PROJECT = S32_App

#RootDirectory with the Project paths
ROOT = ./..
SRC_DIR = $(ROOT)/app/src
BIN_DIR = $(ROOT)/build/bin
OBJ_DIR = $(ROOT)/build/obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#Compiler and Linker flags

CFLAGS = -c -mthumb -mcpu=cortex-m4 -Wall -std=gnu11 
LDFLAGS = -T S32_App.ld -Wl,Map=S32_App -nostdlib -mcpu=cortex-m4 -Wall -Werror -Wshadow

#Target name with path
TARGET = $(ROOT)/build/bin/$(PROJECT).elf

#Makefile rules to build the project
all: $(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(TARGET) $(OBJ)

.PHONY: all clean