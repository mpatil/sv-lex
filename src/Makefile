XOBJ = main.o sub1.o sub2.o sub3.o header.o wcio.o parser.o getopt.o lsearch.o

LOBJ = allprint.o libmain.o reject.o yyless.o yywrap.o \
	allprint_w.o reject_w.o yyless_w.o reject_e.o yyless_e.o

LIBDIR = /home/verif/.sandbox/BNFC/try_lex/bin
BINDIR = /home/verif/.sandbox/BNFC/try_lex/bin
CC = gcc
INSTALL = install

WFLAGS = -DEUC -DJLSLEX -DWOPTION
EFLAGS = -DEUC -DJLSLEX -DEOPTION
CFLAGS = -Wno-multichar -Wno-format

LEXDIR = $(LIBDIR)

.c.o: ; $(CC) -c $(CFLAGS) $(CPPFLAGS) $(WARN) -DFORMPATH='"$(LEXDIR)"' $<

all: lex

lex: $(XOBJ)
	$(CC) $(LDFLAGS) $(XOBJ) $(LIBS) -o lex

allprint_w.o: allprint.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(WARN) $(WFLAGS) allprint.c -o $@

reject_w.o: reject.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(WARN) $(WFLAGS) reject.c -o $@

yyless_w.o: yyless.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(WARN) $(WFLAGS) yyless.c -o $@

reject_e.o: reject.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(WARN) $(EFLAGS) reject.c -o $@

yyless_e.o: yyless.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(WARN) $(EFLAGS) yyless.c -o $@

parser.c: parser.y
	/usr/bin/yacc parser.y
	@mv y.tab.c parser.c

install: all
	test -d $(ROOT)$(BINDIR) || mkdir -p $(ROOT)$(BINDIR)
	test -d $(ROOT)$(LEXDIR) || mkdir -p $(ROOT)$(LEXDIR)
	$(INSTALL) -c -m 755 lex $(ROOT)$(BINDIR)/lex
	$(INSTALL) -c -m 644 ncform $(ROOT)$(LEXDIR)/ncform
	$(INSTALL) -c -m 644 nceucform $(ROOT)$(LEXDIR)/nceucform
	$(INSTALL) -c -m 644 nrform $(ROOT)$(LEXDIR)/nrform

clean:
	rm -f lex libl.a $(XOBJ) $(LOBJ) parser.c core log *~

mrproper: clean

allprint.o: allprint.c
header.o: header.c ldefs.c
ldefs.o: ldefs.c
libmain.o: libmain.c
main.o: main.c once.h ldefs.c sgs.h
reject.o: reject.c
sub1.o: sub1.c ldefs.c
sub2.o: sub2.c ldefs.c
sub3.o: sub3.c ldefs.c search.h
yyless.o: yyless.c
yywrap.o: yywrap.c
lsearch.o: search.h
