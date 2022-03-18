SYSCONF_LINK = g++
CPPFLAGS     =
LDFLAGS      =
LIBS         = -lm

DESTDIR = ./build/
SRC_DIR = ./src/
TARGET  = main

SRC = $(wildcard $(SRC_DIR)*.cpp)
OBJ = $(patsubst $(SRC_DIR)%.cpp, $(DESTDIR)%.o, $(SRC))

all: $(OBJ)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJ) $(LIBS)

$(DESTDIR)%.o: $(SRC_DIR)%.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJ)
	-rm -f $(TARGET)
	-rm -f *.tga