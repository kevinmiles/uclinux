
EXEC = diald
OBJS = diald.o options.o modem.o filter.o slip.o lock.o \
	ppp.o dev.o proxyarp.o fsm.o timer.o firewall.o \
	parse.o buffer.o proxy.o route.o bufio.o killpg.o util.o
FLTFLAGS += -s 12288

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS) -lutil

romfs:
	$(ROMFSINST) /bin/$(EXEC)

clean:
	-rm -f $(EXEC) *.elf *.gdb *.o

$(OBJS): config.h diald.h firewall.h fsm.h version.h timer.h bufio.h

