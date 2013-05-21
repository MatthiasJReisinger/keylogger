SRC = src/main.c src/logger.c src/keylogger.c
PROGRAM_NAME = keylogger
TARGET_DIR = target
FRAMEWORKS = -framework IOKit -framework ApplicationServices

all: $(SRC)
	mkdir -p $(TARGET_DIR)
	gcc -g $(SRC) $(FRAMEWORKS) -o $(TARGET_DIR)/$(PROGRAM_NAME)

clean:
	rm -rf $(TARGET_DIR)

.PHONY: clean
