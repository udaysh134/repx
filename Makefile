.SILENT:
.PHONY: all run clean

# TOOLCHAIN ---------------------------------------- >>
CXX := g++

# SOURCE FILES ---------------------------------------- >>
SRC := $(wildcard \
	src/*.cpp \
	src/app/*.cpp \
	src/core/*.cpp \
	src/modules/*.cpp \
	src/modules/pages/*.cpp \
)

# COMPILER FLAGS ---------------------------------------- >>
CXXFLAGS := -std=c++20 -Wall -Wextra \
	-Isrc/app \
	-Isrc/core \
	-Isrc/modules \
	-Isrc/modules/pages \
	# -Isrc/packages/pdcurses/include

# LINKER FLAGS ---------------------------------------- >>
LDFLAGS := \
	# -Lsrc/packages/pdcurses/lib -l:pdcurses.a

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