CCFLAGS = -I ../../libs/allegro5/include/ -I /usr/include $(INCLUDEDIRS) -std=c++11
LIBDIR = -L /usr/lib
INCLUDEDIRS = -I ../../include/
OBJDIR = ../../obj/SideScrollerObjs/
LNFLAGS = -lallegro -lallegro_primitives -lallegro_font -lallegro_audio -lallegro_ttf -lallegro_acodec -lallegro_dialog -lallegro_image
OBJECTS = GameScreenInterface.o InputManagement.o ScreenManager.o main.o TitleScreen.o SplashScreen.o DeathScreen.o Display.o GameScreen.o Player.o CollisionDetection.o Animation.o ScreenTransition.o SpriteSheet.o ObjectDimensions.o ScrollerObstacle.o BlockPlatform.o BusObject.o ScrollerHole.o SmallBlock.o HalfInvisibleBlock.o ObstacleDrawer.o Spike.o
OBJS = $(addprefix $(OBJDIR), $(OBJECTS))
EXECUTALBE = ../../bin/sideScroller
EXECUTALBEWINDOWS = ../../sideScroller.exe

$(EXECUTALBE): $(OBJS)
	g++ $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
$(OBJDIR)%.o : %.cpp
	g++ -c -o $@ $< $(CCFLAGS)

clean:
	rm -f ../../include/*~ ../../include/*% ../../include/*# ../../include/.#*
	rm -f ../../src/*~ ../../src/*% ../../src/*# ../../src/.#*
	rm -f ../../obj/SideScrollerObjs/*.o

clean-all: clean
	rm -f $(EXECUTALBE)
