.SILENT:
.PHONY: all run clean

# TOOLCHAIN ---------------------------------------- >>
CXX := g++

# SOURCE FILES ---------------------------------------- >>
SRC := \
	$(wildcard src/interfaces/tui/*.cpp) \
	$(wildcard src/interfaces/tui/*/*.cpp) \
	$(wildcard src/interfaces/tui/*/*/*.cpp)

# COMPILER FLAGS ---------------------------------------- >>
CXXFLAGS := -std=c++20 -Wall -Wextra \
	-Isrc/interfaces/tui/app \
	-Isrc/interfaces/tui/core \
	-Isrc/interfaces/tui/core/reputation \
	-Isrc/interfaces/tui/modules \
	# -Ipackages/pdcurses/include

# LINKER FLAGS ---------------------------------------- >>
LDFLAGS := \
	-lole32 -luuid \
	# -Lpackages/pdcurses/lib -l:pdcurses.a

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