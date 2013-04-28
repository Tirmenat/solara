EXEC = solara
COMP = g++
MAIN = main
UNIT = Unit
STAGE = Stage
HERO = Hero
PATROLLER = Patroller
ENEMY = Enemy
SOUND = Sound
BULLET = Bullet
TANK = Tank
FLAGS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lX11

$(EXEC): $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o $(SOUND).o $(PATROLLER).o $(TANK).o
	$(COMP) $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o $(SOUND).o $(PATROLLER).o $(TANK).o -o $(EXEC) $(FLAGS)

$(MAIN).o: $(MAIN).cpp $(UNIT).h $(STAGE).h $(HERO).h $(ENEMY).h $(SOUND).h $(PATROLLER).h $(TANK).h
	$(COMP) -c $(MAIN).cpp

$(STAGE).o: $(STAGE).h $(UNIT).h $(STAGE).cpp
	$(COMP) -c $(STAGE).cpp

$(UNIT).o: $(UNIT).cpp $(UNIT).h
	$(COMP) -c $(UNIT).cpp

$(HERO).o: $(HERO).h $(UNIT).h $(HERO).cpp
	$(COMP) -c $(HERO).cpp

$(ENEMY).o: $(ENEMY).h $(UNIT).h $(ENEMY).cpp
	$(COMP) -c $(ENEMY).cpp

$(PATROLLER).o: $(PATROLLER).h $(PATROLLER).cpp $(ENEMY).h
	$(COMP) -c $(PATROLLER).cpp

$(TANK).o: $(TANK).h $(TANK).cpp $(ENEMY).h
	$(COMP) -c $(TANK).cpp

$(SOUND).o: $(SOUND).h $(SOUND).cpp
	$(COMP) -c $(SOUND).cpp

clean:
	rm -f *.o $(EXEC)