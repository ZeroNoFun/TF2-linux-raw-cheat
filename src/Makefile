NAME=Zand
RELEASE="0.0a"
COMMIT="$(shell git rev-parse HEAD || echo)"

CFLAGS+=-march=native -O3
CFLAGS+=-Wall -Wextra -Wshadow -Wformat -Wconversion -Wdouble-promotion
CFLAGS+=-pipe
CFLAGS+=-m32
CFLAGS+=-fPIC

ifdef $(DEBUG)
CFLAGS+=-ftrapv -g
endif # DEBUG

CMACROS+=-D __RELEASE__=$(RELEASE)
CMACROS+=-D __COMMIT__=$(COMMIT)

LDLIBS+=-lm
LDLIBS+=-lstdc++
LDLIBS+=-ldl
LDLIBS+=-shared
	
AMALG=.amalg.c
#SRC=main.cpp
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
OUT=$(NAME).so

.PHONY: default all amalg depend test clean

default all: $(OUT)

amalg: $(AMALG)
	@$(CXX) $(CMACROS) $(CFLAGS) $(LDLIBS) -o $(OUT) $^

depend:
	@$(CXX) -E -MM $(SRC) > Makefile.dep

test:
	@$(MAKE) -C tests

clean:
	@rm -f $(OUT) $(AMALG) $(OBJ)
	@touch *.in


$(OUT): $(OBJ)
	@$(CXX) $(CFLAGS) $(LDLIBS) -o $@ $^

%.o: %.cpp
	@$(CXX) $(CMACROS) $(CFLAGS) -o $@ -c $<

$(AMALG): $(SRC)
	@cat $^ > $@

-include Makefile.dep
include gen.mk