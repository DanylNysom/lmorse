## Process this file with automake to produce Makefile.in
SUBDIRS = src
dist_man_MANS = doc/lmorse.6 doc/myleds.4
etcdir = $(prefix)/etc
dist_etc_DATA = etc/lmorse_translations
dist-hook:
	mkdir $(distdir)/module
	cp module/Makefile module/myleds.c module/myleds.h $(distdir)/module
run: all
	src/lmorse HELLO WORLD
