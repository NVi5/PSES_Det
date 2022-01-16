SRC_DIR = src
INC_DIR = inc
TEST_DIR = test
BUILD_DIR = build

INCLUDES = -I $(INC_DIR)
INCLUDES += -I $(SRC_DIR)

CFLAGS = $(INCLUDES) -fprofile-arcs -ftest-coverage -g --coverage

SRC_FILES += \
	$(SRC_DIR)/Det.c \

TEST_FILES += \
	$(TEST_DIR)/UT_Det.c \

all: $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	cppcheck --addon=cert --cppcheck-build-dir=$(BUILD_DIR) $(SRC_DIR)
	@rm -f $(BUILD_DIR)/*.gcov
	@rm -f $(BUILD_DIR)/*.gcda
	@rm -f $(BUILD_DIR)/*.gcno
	gcov $^
	# @mv *.gcov $(BUILD_DIR)
	# @mv *.gcda $(BUILD_DIR)
	# @mv *.gcno $(BUILD_DIR)
	gcovr -r . --print-summary --html-details -o $(BUILD_DIR)/coverage.html

clean:
	@rm -rf $(BUILD_DIR)

$(TEST_FILES): $(SRC_FILES)
	gcc $@ $(CFLAGS)
