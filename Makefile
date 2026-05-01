.SILENT:
.PHONY: all run clean

# TOOLCHAIN ---------------------------------------- >>
CXX := g++

# SOURCE FILES ---------------------------------------- >>
SRC := \
	$(wildcard src/*.cpp) \
	$(wildcard src/*/*.cpp) \
    $(wildcard src/*/*/*.cpp)

# COMPILER FLAGS ---------------------------------------- >>
CXXFLAGS := -std=c++20 -Wall -Wextra \
	-Isrc/app \
	-Isrc/core \
	-Isrc/core/reputation \
	-Isrc/modules \
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