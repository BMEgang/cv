# 定义编译器
CXX = g++

# 定义编译器标志，-I. 表示包含当前目录
CXXFLAGS = -Wall -Wextra -std=c++17 -g -I.

# 定义目标
TARGET = myapp

# 自动找到所有的 .cpp 文件
SRC = $(wildcard *.cpp) $(wildcard DTLib/*.cpp)

# 默认目标
all: clean_screen $(TARGET)

# 链接
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# 清理
clean:
	rm -f $(TARGET) $(TARGET).dSYM

# 清屏
clean_screen:
	clear

# 伪目标
.PHONY: all clean clean_screen
