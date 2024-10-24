APP_NAME := Seabattle

CXX := g++

CXXFLAGS := -Wall -Wextra -pedantic -std=c++17

SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR := Sources
OBJ_DIR := Resources
DEP_DIR := Headers

SRCS := $(wildcard $(SRC_DIR)/*.cpp)

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DEPS := $(wildcard $(SRC_DIR)/*.h)

$(APP_NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(APP_NAME) $(OBJS)

.PHONY: clean