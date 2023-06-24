CC = gcc

CFILES := $(shell find . -name '*.c' -exec basename {} \;)

ODIR = obj
OBJ := $(patsubst %, $(ODIR)/%, $(CFILES:.c=.o))
HEADER_DEPS := $(CFILES:.c=.c.d)
CFLAGS = -g
-include $(HEADER_DEPS)

$(ODIR)/%.o: src/**/%.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: src/%.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

cingle: $(OBJ)
	$(CC) $(OBJ) -o $@

$(ODIR):
	mkdir -p $@

.PHONY : clean 
clean: 
	rm -f $(ODIR)/*.o