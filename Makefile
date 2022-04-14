example_c:
	$(CC) example.c -o example_c

example_cpp:
	$(CXX) -std=c++11 example.cc -o example_cpp

docs:
	doxygen dconfig

.PHONY: clean
clean:
	-rm example_*
