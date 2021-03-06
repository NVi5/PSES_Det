SRC_DIR = src
INC_DIR = inc
TEST_DIR = test
BUILD_DIR = build

INCLUDES = -I $(INC_DIR)
INCLUDES += -I $(SRC_DIR)
DEFINES = -D DET_VERSIONINFO_API=1

CFLAGS = $(INCLUDES) -fprofile-arcs -ftest-coverage -g --coverage -Wall -Wextra -Wpedantic

TARGET = UT_Det
SRC_FILES = $(SRC_DIR)/Det.c $(SRC_DIR)/Det_User.c
TEST_FILE = $(TEST_DIR)/UT_Det.c

all: $(BUILD_DIR)/$(TARGET)
	cppcheck --addon=cert --cppcheck-build-dir=$(BUILD_DIR) $(SRC_DIR) -I $(INC_DIR) --xml --xml-version=2 2>build/cppcheck.xml
	./$(BUILD_DIR)/$(TARGET)
	@mv *.gcda $(BUILD_DIR)
	@mv *.gcno $(BUILD_DIR)
	gcov -o $(BUILD_DIR) $(TEST_FILE)
	@mv *.gcov $(BUILD_DIR)
	gcovr -r . --print-summary --filter "src/Det.c" --html-details -o $(BUILD_DIR)/coverage.html

clean:
	@rm -rf $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(SRC_FILES) $(TEST_FILE) $(BUILD_DIR)
	gcc $(TEST_FILE) -o $@ $(CFLAGS) $(DEFINES)

$(BUILD_DIR):
	@mkdir -p $@
