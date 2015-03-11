COMP=g++
EDL=g++
EXE=ParseurLutin
CPPFLAGS=-Wall
EDLFLAGS=-o
ECHO=echo
INT=main.h automate.h
REAL=$(INT:.h=.cpp)
OBJ=$(REAL:.cpp=.o)
CLEAN=clean


.PHONY : $(CLEAN)

$(EXE) : $(OBJ)
	$(ECHO) EDL de $(EXE)
	$(EDL) $(LIBPATH) $(OBJ) $(EDLFLAGS) $(EXE) $(LIBS)


%.o : %.cpp
	$(ECHO) compilation de $<
	$(COMP) $(CPPFLAGS) -c $<

clean :
	$(ECHO) effacement
	rm -f *.o core
