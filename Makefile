CC = gcc
CFLAGS = -Wall -Werror
DFLAGS = -g -DDEBUG

SRCD = src
BIND = bin
BLDD = build
INCD = include

STD := -std=gnu11
CFLAGS += $(STD)

ALL_SRCF = $(wildcard $(SRCD)/*.c)
ALL_OBJF := $(patsubst $(SRCD)/%,$(BLDD)/%,$(ALL_SRCF:.c=.o))

EXEC = sort

all: setup $(EXEC)

debug: CFLAGS += $(DFLAGS)
debug: all

setup:
	mkdir -p $(BIND) $(BLDD)

clean:
	rm -r $(BLDD) $(BIND)

$(EXEC): $(ALL_OBJF)
	$(CC) $^ -o $(BIND)/$@ 

$(BLDD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) -I $(INCD) -c -o $@ $<

init:
	mkdir -p $(SRCD) $(INCD)

