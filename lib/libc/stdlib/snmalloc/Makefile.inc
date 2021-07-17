.PATH: ${LIBC_SRCTOP}/stdlib/snmalloc

SNMALLOCSRCS:= malloc.cc

SYM_MAPS+=${LIBC_SRCTOP}/stdlib/snmalloc/Symbol.map

CXXFLAGS+=-I${SRCTOP}/contrib/snmalloc/src
CXXFLAGS+=-I${SRCTOP}/contrib/snmalloc/src/override
CXXFLAGS+=-std=c++17 -mcx16 -fno-exceptions -fno-rtti
CXXFLAGS+=-DSNMALLOC_USE_THREAD_CLEANUP -DSNMALLOC_PLATFORM_HAS_GETENTROPY
CXXFLAGS+=-ftls-model=initial-exec
SHARED_CXXFLAGS+=-fomit-frame-pointer
STATIC_CXXFLAGS+=-fomit-frame-pointer
PO_CXXFLAGS+=-fno-omit-frame-pointer
CXXFLAGS+=-DNDEBUG
CXXFLAGS+=-DSNMALLOC_EXPORT="__attribute__((weak))"

.for src in ${SNMALLOCSRCS}
MISRCS+=snmalloc_${src}
CLEANFILES+=snmalloc_${src}
snmalloc_${src}: ${SRCTOP}/contrib/snmalloc/src/override/${src} .NOMETA
	ln -sf ${.ALLSRC} ${.TARGET}
.endfor
