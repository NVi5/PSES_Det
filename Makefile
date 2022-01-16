SRC_DIR = src
INC_DIR = inc
TEST_DIR = test
BUILD_DIR = build

INCLUDES = -I $(INC_DIR)
INCLUDES += -I $(SRC_DIR)

CFLAGS = $(INCLUDES) -fprofile-arcs -ftest-coverage -g --coverage

TARGET = UT_Det
SRC_FILE = $(SRC_DIR)/Det.c
TEST_FILE = $(TEST_DIR)/UT_Det.c

all: $(BUILD_DIR)/$(TARGET)
	cppcheck --addon=cert --cppcheck-build-dir=$(BUILD_DIR) $(SRC_DIR) $(INCLUDES)
	./$(BUILD_DIR)/$(TARGET)
	@mv *.gcda $(BUILD_DIR)
	@mv *.gcno $(BUILD_DIR)
	gcov -o $(BUILD_DIR) $(TEST_FILE)
	@mv *.gcov $(BUILD_DIR)
	gcovr -r . --print-summary --filter $(SRC_FILE) --html-details -o $(BUILD_DIR)/coverage.html

clean:
	@rm -rf $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(SRC_FILE) $(TEST_FILE) $(BUILD_DIR)
	gcc $(TEST_FILE) -o $@ $(CFLAGS)

$(BUILD_DIR):
	@mkdir -p $@
