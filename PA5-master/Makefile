MAIN = main

$(MAIN): main.cpp graph.h
	$(CXX) -g -std=c++11 -Wall -Wextra -Wpedantic -o $(MAIN) $<


run: $(MAIN)
	./$(MAIN)

clean: 
	rm -f $(MAIN)
