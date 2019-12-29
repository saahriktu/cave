ifeq ($(prefix),)
	prefix=/usr/local
endif
ifeq ($(shell which $(CC)),)
	CC=gcc
endif
all:
	$(CC) $(CFLAGS) -o cave cave.c
	strip -S cave
install:
	if [ ! -d "$(DESTDIR)$(prefix)/games" ]; then mkdir -p $(DESTDIR)$(prefix)/games; fi
	install -m755 cave $(DESTDIR)$(prefix)/games
clean:
	rm cave
