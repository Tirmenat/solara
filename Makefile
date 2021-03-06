EXEC = solara
COMP = g++
MAIN = main
UNIT = Unit
STAGE = Stage
HERO = Hero
PATROLLER = Patroller
ENEMY = Enemy
SOUND = Sound
BURSTER = Burster
SHOOTER = Shooter
BULLET = Bullet
MIKE = Mike
TANK = Tank
BRAD = Brad
SNEAL=Sneal
SEAN = Sean
FLAGS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lX11

$(EXEC): $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o $(SOUND).o $(PATROLLER).o $(TANK).o $(BURSTER).o $(BULLET).o $(MIKE).o $(SHOOTER).o $(BRAD).o $(SEAN).o $(SNEAL).o
	$(COMP) $(MAIN).o $(UNIT).o $(STAGE).o $(HERO).o $(ENEMY).o $(SOUND).o $(PATROLLER).o $(TANK).o $(BURSTER).o $(BULLET).o  $(MIKE).o $(SHOOTER).o $(BRAD).o $(SEAN).o $(SNEAL).o -o $(EXEC) $(FLAGS)

$(MAIN).o: $(MAIN).cpp $(UNIT).h $(STAGE).h $(HERO).h $(ENEMY).h $(SOUND).h $(PATROLLER).h $(TANK).h $(BURSTER).h $(BULLET).h $(MIKE).h $(SHOOTER).h $(BRAD).h $(SEAN).h $(SNEAL).h
	$(COMP) -c $(MAIN).cpp

$(STAGE).o: $(STAGE).h $(UNIT).h $(STAGE).cpp
	$(COMP) -c $(STAGE).cpp

$(UNIT).o: $(UNIT).cpp $(UNIT).h
	$(COMP) -c $(UNIT).cpp

$(HERO).o: $(HERO).h $(UNIT).h $(HERO).cpp
	$(COMP) -c $(HERO).cpp

$(ENEMY).o: $(ENEMY).h $(UNIT).h $(ENEMY).cpp
	$(COMP) -c $(ENEMY).cpp

$(PATROLLER).o: $(PATROLLER).h $(PATROLLER).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(PATROLLER).cpp

$(BURSTER).o: $(BURSTER).h $(BURSTER).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(BURSTER).cpp

$(TANK).o: $(TANK).h $(TANK).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(TANK).cpp

$(MIKE).o: $(MIKE).h $(MIKE).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(MIKE).cpp

$(SHOOTER).o: $(SHOOTER).h $(SHOOTER).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(SHOOTER).cpp

$(BRAD).o: $(BRAD).h $(BRAD).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(BRAD).cpp

$(SEAN).o: $(SEAN).h $(SEAN).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(SEAN).cpp

$(SNEAL).o: $(SNEAL).h $(SNEAL).cpp $(ENEMY).h $(UNIT).h
	$(COMP) -c $(SNEAL).cpp

$(SOUND).o: $(SOUND).h $(SOUND).cpp
	$(COMP) -c $(SOUND).cpp

$(BULLET).o: $(BULLET).h $(BULLET).cpp $(UNIT).h
	$(COMP) -c $(BULLET).cpp

clean:
	rm -f *.o $(EXEC)