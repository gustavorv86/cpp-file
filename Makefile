SHELL=/bin/bash

########## DIRECTORIES ##########

SRCDIR=src

BUILDDIR=build

DISTDIR=dist

TARGET_LIB=${DISTDIR}/libfile.so
TARGET_TEST=${DISTDIR}/main_test_libfile

BUILDOBJS=
BUILDOBJS+=${BUILDDIR}/file.o
BUILDOBJS+=${BUILDDIR}/file_exception.o
BUILDOBJS+=${BUILDDIR}/main.o

########## COMPILER AND LINKER ############

#CXX=/opt/rh/devtoolset-2/root/usr/bin/g++
CXX=/usr/bin/g++

INCLUDEDIRS=
INCLUDEDIRS+=-I${SRCDIR}/io

CXXFLAGS=
CXXFLAGS+=-std=gnu++11
CXXFLAGS+=-ggdb
CXXFLAGS+=-Wall -Wextra
CXXFLAGS+=${INCLUDEDIRS}

CXXFLAGS_RELEASE=-std=gnu++11 -O3 -Wall -Wextra ${INCLUDEDIRS}

LDFLAGS=

########## RULES ##########
.PHONY: clean all

all: make_dirs ${TARGET_LIB} ${TARGET_TEST}

make_dirs:
	@mkdir -p ${BUILDDIR}
	@mkdir -p ${DISTDIR}

clean: 
	@rm -rf ${BUILDDIR}
	@rm -rf ${DISTDIR}

${BUILDDIR}/file.o: ${SRCDIR}/io/file.h ${SRCDIR}/io/file.cpp
	@echo -e "\n>\t"$@
	${CXX} ${CXXFLAGS} -fPIC -c ${SRCDIR}/io/file.cpp -o ${BUILDDIR}/file.o

${BUILDDIR}/file_exception.o: ${SRCDIR}/io/file_exception.h ${SRCDIR}/io/file_exception.cpp
	@echo -e "\n>\t"$@
	${CXX} ${CXXFLAGS} -fPIC -c ${SRCDIR}/io/file_exception.cpp -o ${BUILDDIR}/file_exception.o

${BUILDDIR}/main_test.o: ${SRCDIR}/main_test.cpp
	@echo -e "\n>\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/main_test.cpp -o ${BUILDDIR}/main_test.o

${TARGET_LIB}: ${BUILDDIR}/file.o ${BUILDDIR}/file_exception.o
	${CXX} -shared -o ${TARGET_LIB} ${BUILDDIR}/file.o ${BUILDDIR}/file_exception.o

${TARGET_TEST}: ${BUILDDIR}/main_test.o ${TARGET_LIB}
	@echo -e "\n>\t"$@
	${CXX} ${CXXFLAGS} -no-pie -L${DISTDIR} $(BUILDDIR)/main_test.o -o ${TARGET_TEST} ${LDFLAGS} -lfile
	
