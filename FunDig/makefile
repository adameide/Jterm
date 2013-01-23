LIBS= -lsfml-graphics -lsfml-window -lsfml-system
CXX := g++

all: main main.o

%.o: %.cpp
	$(CXX) -c $< -o $@

%.o: %.hpp
	$(CXX) -c $< -o $@

main: main.o
	@echo "** Building main"
	$(CXX) -o main main.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm main *.o