## Makefile.am for DirectFB/gfxdrivers/cyber5k

INCLUDES = \
	-I$(top_builddir)/include	\
	-I$(top_srcdir)/include \
	-I$(top_builddir)/lib	\
	-I$(top_srcdir)/lib	\
	-I$(top_srcdir)/systems	\
	-I$(top_srcdir)/src

cyber5k_LTLIBRARIES = libdirectfb_cyber5k.la

if BUILD_STATIC
cyber5k_DATA = $(cyber5k_LTLIBRARIES:.la=.o)
endif

cyber5kdir = $(MODULEDIR)/gfxdrivers

libdirectfb_cyber5k_la_SOURCES = \
	cyber5k.c	\
	cyber5k.h	\
	cyber5k_overlay.h \
	cyber5k_overlay.c \
	cyber5k_underlay.c \
	cyber5k_alpha.c \
	cyber5k_alpha.h \
	regs.h		\
	mmio.h

libdirectfb_cyber5k_la_LDFLAGS = \
	-export-dynamic		\
	-avoid-version		\
	$(DFB_LDFLAGS)

libdirectfb_cyber5k_la_LIBADD = \
	$(top_builddir)/lib/direct/libdirect.la \
	$(top_builddir)/src/libdirectfb.la


include $(top_srcdir)/rules/libobject.make

