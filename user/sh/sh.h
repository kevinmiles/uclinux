#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* Need a way to have void used for ANSI, nothing for K&R. */
#ifndef _ANSI
#undef _VOID
#define _VOID
#endif

/* -------- sh.h -------- */
/*
 * shell
 */

#define	LINELIM	2100
#define	NPUSH	8	/* limit to input nesting */

#define	NOFILE	20	/* Number of open files */
#define	NUFILE	10	/* Number of user-accessible files */
#define	FDBASE	10	/* First file usable by Shell */

/*
 * values returned by wait
 */
#define	WAITSIG(s) ((s)&0177)
#define	WAITVAL(s) (((s)>>8)&0377)
#define	WAITCORE(s) (((s)&0200)!=0)

/*
 * library and system defintions
 */
#ifdef __STDC__
typedef void xint;	/* base type of jmp_buf, for not broken compilers */
#else
typedef char * xint;	/* base type of jmp_buf, for broken compilers */
#endif

/*
 * shell components
 */
/* #include "area.h" */
/* #include "word.h" */
/* #include "io.h" */
/* #include "var.h" */

#define	QUOTE	0200

#define	NOBLOCK	((struct op *)NULL)
#define	NOWORD	((char *)NULL)
#define	NOWORDS	((char **)NULL)
#define	NOPIPE	((int *)NULL)

/*
 * Description of a command or an operation on commands.
 * Might eventually use a union.
 */
struct op {
	int	type;	/* operation type, see below */
	char	**words;	/* arguments to a command */
	struct	ioword	**ioact;	/* IO actions (eg, < > >>) */
	struct op *left;
	struct op *right;
	char	*str;	/* identifier for case and for */
};

#define	TCOM	1	/* command */
#define	TPAREN	2	/* (c-list) */
#define	TPIPE	3	/* a | b */
#define	TLIST	4	/* a [&;] b */
#define	TOR	5	/* || */
#define	TAND	6	/* && */
#define	TFOR	7
#define	TDO	8
#define	TCASE	9
#define	TIF	10
#define	TWHILE	11
#define	TUNTIL	12
#define	TELIF	13
#define	TPAT	14	/* pattern in case */
#define	TBRACE	15	/* {c-list} */
#define	TASYNC	16	/* c & */

/*
 * actions determining the environment of a process
 */
#define	BIT(i)	(1<<(i))
#define	FEXEC	BIT(0)	/* execute without forking */

/*
 * flags to control evaluation of words
 */
#define	DOSUB	1	/* interpret $, `, and quotes */
#define	DOBLANK	2	/* perform blank interpretation */
#define	DOGLOB	4	/* interpret [?* */
#define	DOKEY	8	/* move words with `=' to 2nd arg. list */
#define	DOTRIM	16	/* trim resulting string */

#define	DOALL	(DOSUB|DOBLANK|DOGLOB|DOKEY|DOTRIM)

Extern	char	**dolv;
Extern	int	dolc;
Extern	int	exstat;
Extern  char	gflg;
Extern  int	talking;	/* interactive (talking-type wireless) */
Extern  int	execflg;
Extern  int	multiline;	/* \n changed to ; */
Extern  struct	op	*outtree;	/* result from parser */

Extern	xint	*failpt;
Extern	xint	*errpt;

struct	brkcon {
	jmp_buf	brkpt;
	struct	brkcon	*nextlev;
} ;
Extern	struct brkcon	*brklist;
Extern	int	isbreak;

/*
 * redirection
 */
struct ioword {
	short	io_unit;	/* unit affected */
	short	io_flag;	/* action (below) */
	char	*io_name;	/* file name */
};
#define	IOREAD	1	/* < */
#define	IOHERE	2	/* << (here file) */
#define	IOWRITE	4	/* > */
#define	IOCAT	8	/* >> */
#define	IOXHERE	16	/* ${}, ` in << */
#define	IODUP	32	/* >&digit */
#define	IOCLOSE	64	/* >&- */

#define	IODEFAULT (-1)	/* token for default IO unit */

Extern	struct	wdblock	*wdlist;
Extern	struct	wdblock	*iolist;

/*
 * parsing & execution environment
 */
extern struct	env {
	char	*linep;
	struct	io	*iobase;
	struct	io	*iop;
	xint	*errpt;
	int	iofd;
	struct	env	*oenv;
} e;

/*
 * flags:
 * -e: quit on error
 * -k: look for name=value everywhere on command line
 * -n: no execution
 * -t: exit after reading and executing one command
 * -v: echo as read
 * -x: trace
 * -u: unset variables net diagnostic
 */
extern	char	*flag;

extern	char	*null;	/* null value for variable */
extern	int	intr;	/* interrupt pending */

Extern	char	*trap[NSIG+1];
Extern	char	ourtrap[NSIG+1];
Extern	int	trapset;	/* trap pending */

extern	int	heedint;	/* heed interrupt signals */

Extern	int	yynerrs;	/* yacc */

Extern	char	line[LINELIM];
extern	char	*elinep;

/*
 * other functions
 */
#ifdef __STDC__
int (*inbuilt(char *s ))(void);
#else
int (*inbuilt())();
#endif

#ifdef __STDC__
#define _PROTOTYPE(x,y) x y
#endif

_PROTOTYPE(char *rexecve , (char *c , char **v , char **envp ));
_PROTOTYPE(char *space , (int n ));
_PROTOTYPE(char *strsave , (char *s , int a ));
_PROTOTYPE(char *evalstr , (char *cp , int f ));
_PROTOTYPE(char *putn , (int n ));
_PROTOTYPE(char *my_itoa , (unsigned u , int n ));
_PROTOTYPE(char *unquote , (char *as ));
_PROTOTYPE(struct var *lookup , (char *n ));
_PROTOTYPE(int rlookup , (char *n ));
_PROTOTYPE(struct wdblock *my_glob , (char *cp , struct wdblock *wb ));
_PROTOTYPE(int subgetc , (int ec , int quoted ));
_PROTOTYPE(char **makenv , (void));
_PROTOTYPE(char **eval , (char **ap , int f ));
_PROTOTYPE(int setstatus , (int s ));
_PROTOTYPE(int waitfor , (int lastpid , int canintr ));

_PROTOTYPE(void onintr , (int s )); /* SIGINT handler */

_PROTOTYPE(int newenv , (int f ));
_PROTOTYPE(void quitenv , (void));
_PROTOTYPE(void err , (char *s ));
_PROTOTYPE(int anys , (char *s1 , char *s2 ));
_PROTOTYPE(int any , (int c , char *s ));
_PROTOTYPE(void next , (int f ));
_PROTOTYPE(void setdash , (void));
_PROTOTYPE(void onecommand , (void));
_PROTOTYPE(void runtrap , (int i ));
_PROTOTYPE(void xfree , (char *s ));
_PROTOTYPE(int letter , (int c ));
_PROTOTYPE(int digit , (int c ));
_PROTOTYPE(int letnum , (int c ));
_PROTOTYPE(int gmatch , (char *s , char *p ));

/*
 * error handling
 */
_PROTOTYPE(void leave , (void)); /* abort shell (or fail in subshell) */
_PROTOTYPE(void fail , (void));	 /* fail but return to process next command */
_PROTOTYPE(void warn , (char *s ));
_PROTOTYPE(void sig , (int i ));	 /* default signal handler */

/* -------- var.h -------- */

struct	var {
	char	*value;
	char	*name;
	struct	var	*next;
	char	status;
};
#define	COPYV	1	/* flag to setval, suggesting copy */
#define	RONLY	01	/* variable is read-only */
#define	EXPORT	02	/* variable is to be exported */
#define	GETCELL	04	/* name & value space was got with getcell */

Extern	struct	var	*vlist;		/* dictionary */

Extern	struct	var	*homedir;	/* home directory */
Extern	struct	var	*prompt;	/* main prompt */
Extern	struct	var	*cprompt;	/* continuation prompt */
Extern	struct	var	*path;		/* search path for commands */
Extern	struct	var	*shell;		/* shell to interpret command files */
Extern	struct	var	*ifs;		/* field separators */

_PROTOTYPE(int yyparse , (void));
_PROTOTYPE(struct var *lookup , (char *n ));
_PROTOTYPE(void setval , (struct var *vp , char *val ));
_PROTOTYPE(void nameval , (struct var *vp , char *val , char *name ));
_PROTOTYPE(void export , (struct var *vp ));
_PROTOTYPE(void ronly , (struct var *vp ));
_PROTOTYPE(int isassign , (char *s ));
_PROTOTYPE(int checkname , (char *cp ));
_PROTOTYPE(int assign , (char *s , int cf ));
_PROTOTYPE(void putvlist , (int f , int out ));
_PROTOTYPE(int eqname , (char *n1 , char *n2 ));
_PROTOTYPE(static char *findeq, (char *cp ));
_PROTOTYPE(int execute , (struct op *t , int *pin , int *pout , int act ));

/* -------- io.h -------- */
/* io buffer */
struct iobuf {
  unsigned id;				/* buffer id */
  char buf[512];			/* buffer */
  char *bufp;				/* pointer into buffer */
  char *ebufp;				/* pointer to end of buffer */
};

/* possible arguments to an IO function */
struct ioarg {
	char	*aword;
	char	**awordlist;
	int	afile;		/* file descriptor */
	unsigned afid;		/* buffer id */
	long	afpos;		/* file position */
	struct iobuf *afbuf;	/* buffer for this file */
};
Extern struct ioarg ioargstack[NPUSH];
#define AFID_NOBUF	(~0)
#define AFID_ID		0

/* an input generator's state */
struct	io {
	int	(*iofn)(_VOID);
	struct	ioarg	*argp;
	int	peekc;
	char	prev;		/* previous character read by readc() */
	char	nlcount;	/* for `'s */
	char	xchar;		/* for `'s */
	char	task;		/* reason for pushed IO */
};
Extern	struct	io	iostack[NPUSH];
#define	XOTHER	0	/* none of the below */
#define	XDOLL	1	/* expanding ${} */
#define	XGRAVE	2	/* expanding `'s */
#define	XIO	3	/* file IO */

/* in substitution */
#define	INSUB()	(e.iop->task == XGRAVE || e.iop->task == XDOLL)

/*
 * input generators for IO structure
 */
_PROTOTYPE(int nlchar , (struct ioarg *ap ));
_PROTOTYPE(int strchar , (struct ioarg *ap ));
_PROTOTYPE(int qstrchar , (struct ioarg *ap ));
_PROTOTYPE(int filechar , (struct ioarg *ap ));
_PROTOTYPE(int herechar , (struct ioarg *ap ));
_PROTOTYPE(int linechar , (struct ioarg *ap ));
_PROTOTYPE(int gravechar , (struct ioarg *ap , struct io *iop ));
_PROTOTYPE(int qgravechar , (struct ioarg *ap , struct io *iop ));
_PROTOTYPE(int dolchar , (struct ioarg *ap ));
_PROTOTYPE(int wdchar , (struct ioarg *ap ));
_PROTOTYPE(void scraphere , (void));
_PROTOTYPE(void freehere , (int area ));
_PROTOTYPE(void gethere , (void));
_PROTOTYPE(void markhere , (char *s , struct ioword *iop ));
_PROTOTYPE(int herein , (char *hname , int xdoll ));
_PROTOTYPE(int run , (struct ioarg *argp , int (*f)(_VOID)));

/*
 * IO functions
 */
_PROTOTYPE(int eofc , (void));
_PROTOTYPE(int getc , (int ec ));
_PROTOTYPE(int readc , (void));
_PROTOTYPE(void unget , (int c ));
_PROTOTYPE(void ioecho , (int c ));
_PROTOTYPE(void prs , (char *s ));
_PROTOTYPE(void putc , (int c ));
_PROTOTYPE(void prn , (unsigned u ));
_PROTOTYPE(void closef , (int i ));
_PROTOTYPE(void closeall , (void));

/*
 * IO control
 */
_PROTOTYPE(void pushio , (struct ioarg *argp , int (*fn)(_VOID)));
_PROTOTYPE(int remap , (int fd ));
_PROTOTYPE(int openpipe , (int *pv ));
_PROTOTYPE(void closepipe , (int *pv ));
_PROTOTYPE(struct io *setbase , (struct io *ip ));

extern	struct	ioarg	temparg;	/* temporary for PUSHIO */
#define	PUSHIO(what,arg,gen) ((temparg.what = (arg)),pushio(&temparg,(gen)))
#define	RUN(what,arg,gen) ((temparg.what = (arg)), run(&temparg,(gen)))

/* -------- word.h -------- */
#ifndef WORD_H
#define	WORD_H	1
struct	wdblock {
	short	w_bsize;
	short	w_nword;
	/* bounds are arbitrary */
	char	*w_words[1];
};

_PROTOTYPE(struct wdblock *addword , (char *wd , struct wdblock *wb ));
_PROTOTYPE(struct wdblock *newword , (int nw ));
_PROTOTYPE(char **getwords , (struct wdblock *wb ));
#endif

/* -------- area.h -------- */

/*
 * storage allocation
 */
_PROTOTYPE(char *getcell , (unsigned nbytes ));
_PROTOTYPE(void garbage , (void));
_PROTOTYPE(void setarea , (char *cp , int a ));
_PROTOTYPE(int getarea , (char *cp ));
_PROTOTYPE(void freearea , (int a ));
_PROTOTYPE(void freecell , (char *cp ));

Extern	int	areanum;	/* current allocation area */

#define	NEW(type) (type *)getcell(sizeof(type))
#define	DELETE(obj)	freecell((char *)obj)
_PROTOTYPE(char *memcopy, (char *ato, char *from, int nb ));
/* _PROTOTYPE(int (*a3), (char *, char *)); 
_PROTOTYPE(int (*func), (char *, char *)); */
_PROTOTYPE(int collect, (int c, int c1 ));
_PROTOTYPE(int dobreak, (struct op *t ));
_PROTOTYPE(int dochdir, (struct op *t ));
_PROTOTYPE(int docontinue, (struct op *t ));
_PROTOTYPE(int dodot, (struct op *t ));
_PROTOTYPE(int doeval, (struct op *t ));
_PROTOTYPE(int doexec, (struct op *t ));
_PROTOTYPE(int doexit, (struct op *t ));
_PROTOTYPE(int doexport, (struct op *t ));
_PROTOTYPE(int dolabel, (void));
_PROTOTYPE(int dologin, (struct op *t ));
_PROTOTYPE(int doread, (struct op *t ));
_PROTOTYPE(int doreadonly, (struct op *t ));
_PROTOTYPE(int doset, (struct op *t ));
_PROTOTYPE(int doshift, (struct op *t ));
_PROTOTYPE(int dotimes, (void));
_PROTOTYPE(int dotrap, (struct op *t ));
_PROTOTYPE(int doumask, (struct op *t ));
_PROTOTYPE(int dowait, (struct op *t ));
_PROTOTYPE(int dual, (int c ));
_PROTOTYPE(int getn, (char *as ));
_PROTOTYPE(int getsig, (char *s ));
_PROTOTYPE(int iosetup, (struct ioword *iop, int pipein, int pipeout ));
_PROTOTYPE(int main, (int argc, char **argv ));
_PROTOTYPE(int newfile, (char *s ));
_PROTOTYPE(static char **copyw, (void));
_PROTOTYPE(static char **pattern, (void));
_PROTOTYPE(static char **wordlist, (void));
_PROTOTYPE(static char *blank, (int f ));
_PROTOTYPE(static char *cclass, (char *p, int sub ));
_PROTOTYPE(static char *findeq, (char *cp ));
_PROTOTYPE(static char *generate, (char *start1, char *end1, char *middle, char *end ));
_PROTOTYPE(static char *tree, (unsigned size ));
_PROTOTYPE(static int anyspcl, (struct wdblock *wb ));
_PROTOTYPE(static int brkcontin, (char *cp, int val ));
_PROTOTYPE(static int dollar, (int quoted ));
_PROTOTYPE(static int expand, (char *cp, struct wdblock **wbp, int f ));
_PROTOTYPE(static int forkexec, (struct op *t, int *pin, int *pout, int act, char **wp, int *pforked ));
_PROTOTYPE(static int grave, (int quoted ));
_PROTOTYPE(static int synio, (int cf ));
_PROTOTYPE(static int xstrcmp, (char *p1, char *p2 ));
_PROTOTYPE(static int xxchar, (struct ioarg *ap ));
_PROTOTYPE(static int yylex, (int cf ));
_PROTOTYPE(static struct ioword **copyio, (void));
_PROTOTYPE(static struct ioword *io, (int u, int f, char *cp ));
_PROTOTYPE(static struct op **find1case, (struct op *t, char *w ));
_PROTOTYPE(static struct op *andor, (void));
_PROTOTYPE(static struct op *block, (int type, struct op *t1, struct op *t2, char **wp ));
_PROTOTYPE(static struct op *c_list, (void));
_PROTOTYPE(static struct op *caselist, (void));
_PROTOTYPE(static struct op *casepart, (void));
_PROTOTYPE(static struct op *command, (int cf ));
_PROTOTYPE(static struct op *dogroup, (int onlydone ));
_PROTOTYPE(static struct op *elsepart, (void));
_PROTOTYPE(static struct op *findcase, (struct op *t, char *w ));
_PROTOTYPE(static struct op *list, (struct op *t1, struct op *t2 ));
_PROTOTYPE(static struct op *namelist, (struct op *t ));
_PROTOTYPE(static struct op *nested, (int type, int mark ));
_PROTOTYPE(static struct op *newtp, (void));
_PROTOTYPE(static struct op *pipeline, (int cf ));
_PROTOTYPE(static struct op *simple, (void));
_PROTOTYPE(static struct op *thenpart, (void));
_PROTOTYPE(static void badid, (char *s ));
_PROTOTYPE(static void brkset, (struct brkcon *bc ));
_PROTOTYPE(static void diag, (int ec ));
_PROTOTYPE(static void echo, (char **wp ));
_PROTOTYPE(static void musthave, (int c, int cf ));
_PROTOTYPE(static void rdexp, (char **wp, void (*f)(), int key));
_PROTOTYPE(static void readhere, (char **name, char *s, int ec ));
_PROTOTYPE(static void word, (char *cp ));
_PROTOTYPE(static void zzerr, (void));
/*_PROTOTYPE(void (*f), (int));
 _PROTOTYPE(void (*qflag), (int)); */
_PROTOTYPE(void glob0, (char *a0, unsigned int a1, int a2, int (*a3)(char *, char *)));
_PROTOTYPE(void glob1, (char *base, char *lim ));
_PROTOTYPE(void glob2, (char *i, char *j ));
_PROTOTYPE(void glob3, (char *i, char *j, char *k ));
_PROTOTYPE(void globname, (char *we, char *pp ));
_PROTOTYPE(void initarea, (void));
_PROTOTYPE(void pushio, (struct ioarg *argp, int (*fn)()));
_PROTOTYPE(void setsig, (int n, void (*f)()));
_PROTOTYPE(void tempname, (char *tname ));
_PROTOTYPE(void varput, (char *s, int out ));
_PROTOTYPE(void yyerror, (char *s ));
_PROTOTYPE(void *dupstate, (void));

