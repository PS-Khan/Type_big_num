CC=g++
CFLAGS = -Wall -g -O
SRC = src/main.cpp
OBJ = obj/main.o
LIB_SRC = src/BigInteger.cpp
LIB_OBJ = obj/BigInteger.o
TARGET = type

all : $(TARGET)

$(TARGET): $(OBJ) $(LIB_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ): $(SRC)
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	del /Q obj\*.o
	del /Q type.exe
	