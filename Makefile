SRC_DIR = src
INC_DIR = inc
TEST_DIR = test
BUILD_DIR = build

INCLUDES = -I $(INC_DIR)
INCLUDES += -I $(SRC_DIR)
INCLUDES += -I $(TEST_DIR)

SRC_FILES += \
    $(SRC_DIR)/Det.c \

TEST_FILES += \
    $(TEST_DIR)/UT_Det.c \

CC = gcc
CFLAGS = $(INCLUDES) -fprofile-arcs -ftest-coverage -g --coverage

all: $(SRC_FILES)
    cppcheck --addon=cert $(BUILD_DIR)
    rm -f $(BUILD_DIR)/*.gcov
    rm -f $(BUILD_DIR)/*.gcda
    rm -f $(BUILD_DIR)/*.gcno
    gcov $^
    gcov *.gcno
    @mv *.gcov $(BUILD_DIR)
    @mv *.gcda $(BUILD_DIR)
    @mv *.gcno $(BUILD_DIR)
    gcovr -r . --print-summary --html-details -o coverage.html

clean:
    rm -rf $(BUILD_DIR)

$(TEST_FILES): SRC_FILES
    $(CC) -o $@ $(CFLAGS)
