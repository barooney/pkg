TITLE_ID = XVITAPKGX
TARGET   = pkg
JSON_SRCS = $(wildcard json/*.c) 
VU_SRCS  = $(wildcard vu/*.c)
SRCS     = main.c $(VU_SRCS) $(JSON_SRCS)
OBJS     = $(addsuffix .o, $(SRCS))

LIBS = -lvita2d -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub \
	-lSceCommonDialog_stub -lfreetype -lpng -ljpeg -lz -lm -lc -ljansson

CC       = arm-vita-eabi-gcc
CXX      = arm-vita-eabi-g++
CFLAGS   = -Wl,-q -Wall -O3 -I.
STRIP    = arm-vita-eabi-strip
CXXFLAGS = -Wl,-q -Wall -O3 -I. -std=c++0x
ASFLAGS  = $(CFLAGS)

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin $@

eboot.bin: $(TARGET).velf
	vita-make-fself $< $@

%.velf: %.elf
	vita-elf-create $< $@

%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

%.c.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

%.png.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) \
		eboot.bin param.sfo

vpksend: $(TARGET).vpk
	curl -T $(TARGET).vpk ftp://$(PSVITAIP):1337/ux0:/
	@echo "Sent."

send: eboot.bin
	curl -T eboot.bin ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE_ID)/
	@echo "Sent."
