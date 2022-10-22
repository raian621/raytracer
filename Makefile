GXX := g++
WFLAGS := -Wall
INCLUDE := -Iinclude
LIBRARIES := -lm

SRC_DIRS := src/ $(sort $(dir $(wildcard src/**/*)))
OBJ_DIRS := $(SRC_DIRS:src%=obj%)
DBG_DIRS := $(SRC_DIRS:src%=dbg%)

SRC := $(foreach x, $(SRC_DIRS), $(wildcard $(x)*.cpp))
OBJ := $(SRC:src%.cpp=obj%.o)
DBG := $(SRC:src%.cpp=dbg%.o)

TARGET := raytracer
DEBUG_TARGET = dbg/$(TARGET).dbg

.PHONY: default
default: $(TARGET)

.PHONY: debug
debug: $(DEBUG_TARGET)

.PHONY: clean
clean:
	-rm $(OBJ)
	-rm $(DBG)
	-rm $(TARGET)
	-rm $(DEBUG_TARGET)
	-rmdir $(OBJ_DIRS) obj
	-rmdir $(DBG_DIRS) dbg

$(TARGET): $(OBJ_DIRS) $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LIBRARIES)

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $^ $(WFLAGS) $(INCLUDE)

$(OBJ_DIRS):
	mkdir $(OBJ_DIRS)

$(DEBUG_TARGET): $(DBG_DIRS) $(DBG)
	$(CXX) -g -o $@ $(DBG) $(WFLAGS)

dbg/%.o: src/%.cpp
	$(CXX) -g -c -o $@ $^ $(WFLAGS) $(INCLUDE)

$(DBG_DIRS):
	mkdir $(DBG_DIRS)

print:
	@echo $(SRC_DIRS) | awk 'BEGIN { RS=" " } {print $0 }'
	@echo $(OBJ_DIRS) | awk 'BEGIN { RS=" " } {print $0 }'
	@echo $(DBG_DIRS) | awk 'BEGIN { RS=" " } {print $0 }'
	@echo $(SRC) | awk 'BEGIN { RS=" " } {print $0 }'
	@echo $(OBJ) | awk 'BEGIN { RS=" " } {print $0 }'
	@echo $(DBG) | awk 'BEGIN { RS=" " } {print $0 }'
	@echo $(TARGET) $(DEBUG_TARGET) | awk 'BEGIN { RS=" " } {print $0 }'

