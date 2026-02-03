# Build target
all: repx

repx:
	g++ \
	src/main.cpp \
	\
	-o RepX.exe

# Run target
run: repx
	./RepX.exe