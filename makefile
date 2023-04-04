OBJECTS = test.o 
CFLAGS = -g -Wall 
LDLIBS =
INCLUDE = -I include 
TARGET = test
SOURCES = $(OBJECTS: %c = %o)

LIBDIR = lib
OBJDIR = obj
SOURCEDIR = src
BINDIR = bin



all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET) : $(addprefix obj/, $(notdir $(OBJECTS))) 
	@if [ ! -d $(BINDIR) ]; then\
		mkdir $(BINDIR);\
	fi
	$(CC) $(CFLAGS)  -o $@ $^  $(LDLIBS)

$(OBJDIR)/%.o : $(SOURCEDIR)/%.c
	@if [ ! -d $(OBJDIR) ]; then\
		mkdir $(OBJDIR);\
	fi;
	$(CC) $(CFLAGS) $(LDLIBS) $(INCLUDE) -o $@ -c $< 

$(OBJDIR)/%.o : $(LIBDIR)/%.c
	@if [ ! -d $(OBJDIR) ]; then\
		mkdir $(OBJDIR);\
	fi;
	$(CC) $(CFLAGS) $(LDLIBS) $(INCLUDE) -o $@ -c $<
	

clean :
	rm -f bin/$(TARGET) $(OBJDIR)/*
