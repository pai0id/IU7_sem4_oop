# Компилятор
CC := gcc

# Названия папок
INC_DIR := ./inc
SRC_DIR := ./src
OUT_DIR := ./out

OBJS := $(OUT_DIR)/file_sys.o $(OUT_DIR)/object.o $(OUT_DIR)/str_read.o $(OUT_DIR)/UI.o

HEADERS :=$(INC_DIR)/file_sys.h $(INC_DIR)/object.h $(INC_DIR)/str_read.h $(INC_DIR)/UI.h $(INC_DIR)/err.h

CFLAGS := -std=c99 -I$(INC_DIR) -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

debug : CFLAGS += -g3
debug : app.exe

release : app.exe

app.exe : $(OBJS) $(OUT_DIR)/main.o
	$(CC) $^ -o $@ -lm -lGL -lGLU -lglut

$(OUT_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(OUT_DIR)
	$(CC) -o ./$@ $(CFLAGS) -c $<

.PHONY : clean
clean :
	rm -f -r $(OUT_DIR)
	rm -f ./*.exe ./*tmp* ./*.txt
