CCFLAGS = -I ../../libs/allegro5/include/ -I /usr/include $(INCLUDEDIRS) -std=c++11
LIBDIR = -L ../../libs/allegro5/lib -L /usr/lib
INCLUDEDIRS = -I ../../include/
OBJDIR = ../../obj/testObjs/
LNFLAGS = -lcppunit -ldl -lallegro -lallegro_primitives -lallegro_font -lallegro_audio -lallegro_ttf -lallegro_acodec -lallegro_dialog -lallegro_image
OBJECTS = CollisionDetection.o SideScrollerTestFixture.o ObjectDimensions.o test.o
OBJS = $(addprefix $(OBJDIR), $(OBJECTS))
EXECUTALBE = ../../tests

$(EXECUTALBE): $(OBJS)
	g++ $(LIBDIR) -o $@ $^ $(LNFLAGS)

$(OBJDIR)%.o : %.cpp
	g++ -c -o $@ $< $(CCFLAGS)

clean:
	rm -f ../../include/*~ ../../include/*% ../../include/*# ../../include/.#*
	rm -f ../../src/*~ ../../src/*% ../../src/*# ../../src/.#*
	rm -f ../../obj/testObjs/*.o

clean-all: clean
	rm -f $(EXECUTALBE)
