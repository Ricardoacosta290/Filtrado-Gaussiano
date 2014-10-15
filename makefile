CXX = g++
CXXFLAGS = -ggdb -Wno-deprecated
# esta asignacion a la variable objetivo, me indica todos los targets necesarios y tendre que definir uno a uno c/u
objetive = Main.o Imagen.o
# pid sera el ejecutable final de mi aplicacion el uso de dolar, me indica que se esta usando la variable
pid: $(objetive)
	$(CXX) -o $@ $^
	#./$@ esto se usa para producir la ejecucion instantanea

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

Imagen.o: Imagen.cpp Imagen.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf pid *.o
