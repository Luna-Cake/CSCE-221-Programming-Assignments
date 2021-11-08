WARNINGS=-Wall -Wextra -Wpedantic -Werror
CPP_VERSION=-std=c++17

STD_BUILD=g++ $(CPP_VERSION) $(WARNINGS) -g -o $@ $^
STD_BUILD_O_FILE=g++ $(CPP_VERSION) $(WARNINGS) -g -o $@ -c $<

all:
	echo "Please provide a target with make: DLList TemplatedDLList Record Library"

clean:
	rm -f *.o DLList TemplatedDLList Record Library

DLList: DLList.o DLList-main.o
	$(STD_BUILD)

DLList.o: DLList.cpp DLList.h
	$(STD_BUILD_O_FILE)

DLList-main.o: DLList-main.cpp DLList.h
	$(STD_BUILD_O_FILE)

TemplatedDLList: TemplatedDLList-main.o
	$(STD_BUILD)

TemplatedDLList-main.o: TemplatedDLList-main.cpp TemplatedDLList.h
	$(STD_BUILD_O_FILE)

Record: Record.o Record-main.o
	$(STD_BUILD)

Record.o: Record.cpp Record.h
	$(STD_BUILD_O_FILE)

Record-main.o: Record-main.cpp Record.h
	$(STD_BUILD_O_FILE)

Library: Library.o Library-main.o Record.o TemplatedDLList.h
	echo "Not implemented yet, check back later"
	$(STD_BUILD)

Library.o: Library.cpp Library.h
	echo "Not implemented yet, check back later"
	$(STD_BUILD_O_FILE)

Library-main.o: Library-main.cpp Library.h Record.h
	echo "Not implemented yet, check back later"
	$(STD_BUILD_O_FILE)

