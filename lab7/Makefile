# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = lab7_test

# The 'check' target for memory leak detection
check: $(TARGET)
	@echo "Running Valgrind memory check..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f *.o lab7

pdf:
	pandoc readme.md  --defaults=style.yaml -o lab-7.pdf