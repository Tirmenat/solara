EXEC = solara
COMP = g++
MAIN = main
UNIT = Unit
STAGE = Stage
HERO = Hero
ENEMY = Enemy
FLAGS = -lSDL -lSDL_image -lSDL_ttf

$(EXEC): $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o
	$(COMP) $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o -o $(EXEC) $(FLAGS)

$(MAIN).o: $(MAIN).cpp $(UNIT).h $(STAGE).h $(HERO).h
	$(COMP) -c $(MAIN).cpp

$(STAGE).o: $(STAGE).h $(UNIT).h $(STAGE).cpp
	$(COMP) -c $(STAGE).cpp

$(UNIT).o: $(UNIT).cpp $(UNIT).h
	$(COMP) -c $(UNIT).cpp

$(HERO).o: $(HERO).h $(UNIT).h $(HERO).cpp
	$(COMP) -c $(HERO).cpp

$(ENEMY).o: $(ENEMY).h $(UNIT).h $(ENEMY).cpp
	$(COMP) -c $(ENEMY).cpp

clean:
	rm -f *.o $(EXEC)