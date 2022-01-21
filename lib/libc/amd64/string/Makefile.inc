
MDSRCS+= \
	amd64_archlevel.c \
	bcmp.S \
	memcmp.S \
	memmove.S \
	memset.S \
	stpcpy.S \
	strcat.S \
	strchrnul.S \
	strcmp.S \
	strlen.S \
	strcpy.c

.if ${MK_SNMALLOC_MEMCPY} == "no"
SRCS+= memcpy.c
.endif
