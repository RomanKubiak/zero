CC=gcc
CFLAGS=-c -Wall -std=c99 -I. -DMPACK -DMPACK_DEBUG -DMPACK_STDIO -D_DEBUG
LDFLAGS=-levent -lwiringPi
SOURCES=main.c udp_server.c http_server.c mpack/mpack.c serial.c utils.c messages.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=zero_head

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f zero_head
