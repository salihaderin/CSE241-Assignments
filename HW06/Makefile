
all: exe

exe: $(addsuffix .o, main GTUIterator GTUIteratorConst GTUSet GTUVector)
	g++ -g -std=c++11 -o $@ $^

%.o: %.cpp
	g++ -g -c -std=c++11 -o $@ $<

clean:
	rm -rf *.o exe

debug: exe
	gdb -ex run $^

lldb: exe
	$@ -o run $^
