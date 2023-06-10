# Змінні
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
GTEST_DIR = /usr/include/gtest

# Файли джерела
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Цілі
MAIN_TARGET = $(BIN_DIR)/main.bin
TEST_TARGET = $(BIN_DIR)/test.bin

# Завдання для збірки основного файлу
$(MAIN_TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Завдання для збірки тестового файлу
$(TEST_TARGET): $(OBJS) $(BUILD_DIR)/test.o $(GTEST_DIR)/src/gtest-all.cc
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) $^ -o $@ -pthread

# Завдання для збірки об'єктних файлів
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Завдання для збірки тестового об'єктного файлу
$(BUILD_DIR)/test.o: test/test.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Завдання для очищення збірки
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: clean test

test: $(TEST_TARGET)
	./$(TEST_TARGET)
 
doxygen:
	doxygen
