# CORAL TV — PlayStation 2 homebrew entertainment launcher
# Requires PS2SDK and gsKit. See docs/BUILD.md.

EE_BIN = coral-tv.elf
EE_OBJS = src/main.o \
          src/core/logger.o \
          src/graphics/renderer.o \
          src/graphics/text.o

# The ps2dev image installs gsKit in $GSKIT; CMake installs use $PS2SDK/ports.
ifeq ($(GSKIT),)
GSKIT = $(PS2SDK)/ports
endif

EE_INCS += -Iinclude -I$(GSKIT)/include
EE_CFLAGS += -Wall -Wextra
EE_LDFLAGS += -L$(GSKIT)/lib
EE_LIBS = -lgskit -ldmakit -lpad -lm

all: $(EE_BIN)
	$(EE_STRIP) --strip-all $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS)

rebuild: clean all

.PHONY: all clean rebuild

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
