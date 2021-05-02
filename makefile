OBJECTS = test.o 
CFLAGS = -g -Wall 
LDLIBS = -lm
INCLUDE = -I include 
TARGET = test
SOURCES = $(OBJECTS: %c = %o)

LIBDIR = lib
OBJDIR = obj
SOURCEDIR = src


#$(warning $(SOURCES))
$(TARGET) : $(addprefix obj/, $(notdir $(OBJECTS))) 
	$(CC) $(CFLAGS)  -o $@ $^  $(LDLIBS)

$(OBJDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) $(LDLIBS) $(INCLUDE) -o $@ -c $< 

$(OBJDIR)/%.o : $(LIBDIR)/%.c
	$(CC) $(CFLAGS) $(LDLIBS) $(INCLUDE) -o $@ -c $<
clean :
	rm -f $(TARGET) $(OBJDIR)/*
