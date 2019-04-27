CC =g++ -std=c++11
exe_file = a2
# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -O3
endif

$(exe_file): A2_Implementation.o A2_Application.o
	$(CC) A2_Implementation.o A2_Application.o -o $(exe_file) $(CFLAGS)
A1_Implementation.o: A2_Implementation.cpp
	$(CC) -c A2_Implementation.cpp $(CFLAGS)
A1_Application.o: A2_Application.cpp
	$(CC) -c A2_Application.cpp $(CFLAGS)

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean

