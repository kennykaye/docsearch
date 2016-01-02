CC := g++
SRC_DIR := src
LIB_DIR := lib
TEST_DIR := tests
BUILD_DIR := build
TARGET := bin/app
TEST_TARGET := bin/tests

SRC_EXT := cpp
LIB := ./lib/porter2_stemmer/porter2_stemmer.cpp
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
TEST_SOURCES := $(subst $(SRC_DIR)/main.$(SRC_EXT),,${SOURCES})
TESTS := $(shell find $(TEST_DIR) -type f -name *.$(SRC_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))
CFLAGS := -g -Wall -std=c++11
INC := -I./src -I./lib -I./lib/Catch/single_include -I./lib/porter2_stemmer

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(TARGET): $(OBJECTS)
	@echo "\nLinking..."
	$(CC) $^ -o $(TARGET)

run:
	@echo "Starting..."
	./$(TARGET)

clean:
	@echo "Cleaning...";
	$(RM) -r $(BUILD_DIR) $(TARGET)
	$(RM) -r $(BUILD_DIR) $(TEST_TARGET)

test-again:
ifneq ("$(wildcard $(TEST_TARGET))", "")
	@echo "Running tests..."
	./$(TEST_TARGET)
else
	@echo "No test target found..."
	$(MAKE) tests
	$(MAKE) test
endif

test:
	@echo "Compiling tests..."
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(INC) $(LIB) $(TEST_SOURCES) $(TESTS)
	$(MAKE) test-again

.PHONY: clean test test-again run
