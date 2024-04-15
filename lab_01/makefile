# Компилятор
CC := gcc

# Названия папок
INC_DIR := ./inc
SRC_DIR := ./src
OUT_DIR := ./out

OBJS := $(OUT_DIR)/draw.o $(OUT_DIR)/edges.o $(OUT_DIR)/err.o $(OUT_DIR)/object.o $(OUT_DIR)/points.o $(OUT_DIR)/str_read.o $(OUT_DIR)/task_mngr.o $(OUT_DIR)/UI.o $(OUT_DIR)/SDL_draw.o

HEADERS := $(INC_DIR)/err.h $(INC_DIR)/UI.h $(INC_DIR)/draw.h $(INC_DIR)/edges.h $(INC_DIR)/object_pos.h $(INC_DIR)/object.h $(INC_DIR)/points.h $(INC_DIR)/str_read.h $(INC_DIR)/task_mngr.h $(INC_DIR)/SDL_draw.h

CFLAGS := -I$(INC_DIR) -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fno-threadsafe-statics

debug : CFLAGS += -g3
debug : app.exe

release : app.exe

app.exe : $(OBJS) $(OUT_DIR)/main.o
	$(CC) $^ -o $@ -lSDL2 -lm

$(OUT_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADERS)
	mkdir -p $(OUT_DIR)
	$(CC) -o ./$@ $(CFLAGS) -c $<

.PHONY : clean
clean :
	rm -f -r $(OUT_DIR)
	rm -f ./*.exe ./*tmp* ./*.txt
