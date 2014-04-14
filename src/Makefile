CCFLAGS = -I ../libs/allegro5/include/ -I /usr/include $(INCLUDEDIRS) -std=c++11
LIBDIR = -L ../libs/allegro5/lib -L /usr/lib
INCLUDEDIRS = -I ../include/
OBJDIR = ../obj/
LNFLAGS = -lallegro -lallegro_primitives -lallegro_font -lallegro_audio -lallegro_ttf -lallegro_acodec -lallegro_dialog -lallegro_image
OBJECTS = Platform.o GameScreenInterface.o InputManagement.o ScreenManager.o main.o TitleScreen.o SplashScreen.o Display.o GameScreen.o Player.o CollisionDetection.o Animation.o ScreenTransition.o SpriteSheet.o ObjectDimensions.o BlockPlatform.o BusObject.o
OBJS = $(addprefix $(OBJDIR), $(OBJECTS))
EXECUTALBE = ../sideScroller

$(EXECUTALBE): $(OBJS)
	g++ $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
$(OBJDIR)%.o : %.cpp
	g++ -c -o $@ $< $(CCFLAGS)

clean:
	rm -f ./include/*~ ./include/*% ./include/*# ./include/.#*
	rm -f ./src/*~ ./src/*% ./src/*# ./src/.#*
	rm -f ../obj/*.o

clean-all: clean
	rm -f $(EXECUTALBE)
