#
# GTKmm4 avec -std=c++17
#
OUT = simple
CXX = g++
CXXFLAGS = -Wall -std=c++17 
LINKING = `pkg-config --cflags gtkmm-4.0`
LDLIBS = `pkg-config --libs gtkmm-4.0`
OFILES = simple.o 

all: $(OUT)

simple.o: simple.cc
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)



$(OUT): $(OFILES)
	$(CXX) $(CXXFLAGS) $(LINKING) $(OFILES) -o $@ $(LDLIBS)


clean:
	@echo "Cleaning compilation files"
	@rm *.o $(OUT) *.cc~ *.h~
