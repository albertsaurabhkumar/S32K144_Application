#Makefile for S32K144 Application

#RootDirectory with the Project paths
ROOT = ./..
SRC_DIR = $(ROOT)/app/src
INC_DIR = $(ROOT)/app/inc $(ROOT)/app/common 
BIN_DIR = $(ROOT)/build/bin
OBJ_DIR = $(ROOT)/build/obj

#Compiler Directories
CC_DIR = $(ROOT)/tools/CC/gcc-10.3
CC_BIN = $(CC_DIR)/bin
CC_INC = $(CC_DIR)/include
CC_LIB = $(CC_DIR)/lib

#Compilar Path
CC = $(CC_BIN)/arm-none-eabi-gcc

#Project Name
PROJECT = S32_App

SRC = $(wildcard $(SRC_DIR)/*.c)
INC = $(wildcard $(INC_DIR)/*.h) $(ROOT)/app/common/common.h 
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#Compiler and Linker flags

CFLAGS = -c -mthumb -mcpu=cortex-m4 -Wall -std=gnu11 $(addprefix -I ,$(INC_DIR))
LDFLAGS = -T S32K144_64_flash.ld -Wl,-Map=S32_App.map -nostdlib -mcpu=cortex-m4 -Wall -Werror -Wshadow $(addprefix -L ,$(CC_LIB))

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