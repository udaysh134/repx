.SILENT:
.PHONY: all run clean

# TOOLCHAIN ---------------------------------------- >>
CXX := g++

# SOURCE FILES ---------------------------------------- >>
SRC := $(wildcard \
	src/*.cpp \
	src/modules/*.cpp \
	src/ui/*.cpp \
	src/ui/menus/*.cpp \
)

# COMPILER FLAGS ---------------------------------------- >>
CXXFLAGS := -std=c++20 -Wall -Wextra \
	-Isrc/include \
	-Isrc/packages/pdcurses/include

# LINKER FLAGS ---------------------------------------- >>
LDFLAGS := \
	-Lsrc/packages/pdcurses/lib -l:pdcurses.a

# OUTPUT ---------------------------------------- >>
TARGET := RepX.exe


# ----------------------------------------------------------------------------------------------------
# BUILD RULES
# ----------------------------------------------------------------------------------------------------
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del $(TARGET)