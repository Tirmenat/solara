EXEC = solara
COMP = g++
MAIN = main
UNIT = Unit
STAGE = Stage
HERO = Hero
ENEMY = Enemy
SOUND = Sound
FLAGS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

$(EXEC): $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o $(SOUND).o
	$(COMP) $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o $(SOUND).o -o $(EXEC) $(FLAGS)

$(MAIN).o: $(MAIN).cpp $(UNIT).h $(STAGE).h $(HERO).h $(SOUND).h
	$(COMP) -c $(MAIN).cpp

$(STAGE).o: $(STAGE).h $(UNIT).h $(STAGE).cpp
	$(COMP) -c $(STAGE).cpp

$(UNIT).o: $(UNIT).cpp $(UNIT).h
	$(COMP) -c $(UNIT).cpp

$(HERO).o: $(HERO).h $(UNIT).h $(HERO).cpp
	$(COMP) -c $(HERO).cpp

$(ENEMY).o: $(ENEMY).h $(UNIT).h $(ENEMY).cpp
	$(COMP) -c $(ENEMY).cpp

$(SOUND).o: $(SOUND).h $(SOUND).cpp
	$(COMP) -c $(SOUND).cpp

clean:
	rm -f *.o $(EXEC)