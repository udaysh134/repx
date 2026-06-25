.SILENT:
.PHONY: all run clean

# TOOLCHAIN ---------------------------------------- >>
CXX := g++

# SOURCE FILES ---------------------------------------- >>
SRC := \
	$(wildcard src/engine/*.cpp) \
    $(wildcard src/engine/*/*.cpp) \
	$(wildcard src/interfaces/tui/*.cpp) \
	$(wildcard src/interfaces/tui/*/*.cpp) \
	$(wildcard src/interfaces/tui/*/*/*.cpp)

# COMPILER FLAGS ---------------------------------------- >>
CXXFLAGS := -std=c++20 -Wall -Wextra \
	-Isrc \
	-Ipackages

# LINKER FLAGS ---------------------------------------- >>
LDFLAGS := \
	-lole32 -luuid \
	# -Lpackages/pdcurses/lib -l:pdcurses.a

# OUTPUT ---------------------------------------- >>
TARGET := RepX_TUI.exe


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