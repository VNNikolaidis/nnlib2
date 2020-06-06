ccsrc = $(wildcard ../nnlib2/*.cpp) \ $(wildcard *.cpp)
obj = $(ccsrc:.cpp=.o)

test_MAM:	$(obj) ../test_main/test_main_with_sMAM.o
	$(CXX) -o $@ $^ 

test_SOM:	$(obj) ../test_main/test_main_with_SOM.o
	$(CXX) -o $@ $^ 
