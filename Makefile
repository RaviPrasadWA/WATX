#----------- BUILD OPTIONS ---------------------------
# PCB revision
PCBREV =

# LCD
# Values: DEFAULT, ST7565P, ST7565R, ERC12864FSF, ST7920
LCD = ST7920

# Enable JETI-Telemetry or FrSky Telemetry reception on UART0
# For this option you need to modify your hardware!
# More information at [insertURLhere]
# Values = STD, FRSKY, FRSKY_SPORT, JETI, NMEA, ARDUPILOT, MAVLINK, TELEMETREZ
EXT = STD

# GUI enabled
# Values = YES, NO
GUI = YES

# FAI mode
# Values = YES, NO, CHOICE
FAI = NO

# the latests deliveries for Turnigy 9x transmitters (since 2 years now, 2014) do not stop sending if no pulses are generated.
# This fact totally breaks the nice throttle and switch warning concept, because even we prevent sending pulses the
# transmitter module ignores this, and continues to send the last value or 0 at beginning. And 0 means in the middle of throttle -> 50%.
# To cope with this situation, we need a new concept how to handle throttle and switch warnings.
# if you have a 0 value (50% ) for throttle, while throttle warning is active, you should activate this switch
# Values = YES, NO
TURNIGY_TRANSMITTER_FIX = NO

# Enable heli menu
# Values = YES, NO
HELI = YES

# Enable templates menu
# Values = YES, NO
TEMPLATES = $(GUI)

# Enable navigation with Pots / Sticks / Rotary encoders
# Values = NO
#          POT1 (only POT1 available for fields modification),
#          POT2 (menus scroll),
#          POT3 (cursor down/up),
#          POTS (POT1, POT2, POT3),
#          STICKS
#          ROTENC (Rotary encoder)
NAVIGATION = NO

# Switches automatic selection
# Values = YES, NO
AUTOSWITCH = NO

# Stock sticks replaced by FrSky ones
# Values = YES, NO
FRSKY_STICKS = NO

# Sources automatic selection
# Values = YES, NO
AUTOSOURCE = NO

# Double keys support (+/- means invert, +/up means max, -/dwn means min, up/down means reset to default)
# Values = YES, NO
DBLKEYS = NO

# AUDIO Mods
# Values = YES, NO
AUDIO = NO

# VOICE Mods
# Values = YES, NO
VOICE = NO

# corrects different rounding for negative values. So instead of -99.9 you will see again -100.0
# Values = YES, NO
CORRECT_NEGATIVE_VALUES = YES

# adds additional code to prevent arithmetic overflows. MAX or MIN values stays. Not yet guaranteed!! Just improved
# Values = YES, NO
ARITHMETIC_OVERFLOW_CHECK = NO

# increases resolution for throttle statistics and throttle counting, in very rare cases.
# this will be only true if an output channel is used for throttle calculation, and this channel has changed limits, e.g. -90% to +80%
# if you use standard limits for throttle or directly the throttle stick you do not need to bother about this option
# not valid for ARM based transmitters like Taranis, They do not have this rounding issue at all
# Values = YES, NO
ACCURAT_THROTTLE_STATS = NO

# HAPTIC Mods
# Values = YES, NO
HAPTIC = NO

# SmartieParts 2.2 Backlight support (inverted)
# Values = YES, NO
SP22 = NO

# Fade Backlight using PWM
# Values = YES, NO
PWM_BACKLIGHT = NO

# SPLASH on START
# Values = YES, NO, FIXED
SPLASH = $(GUI)

# GRAPHICS (sliders / checkboxes / bold / batt graph)
GRAPHICS = YES
BOLD = YES
BATTGRAPH = NO

# FONT TYPE
# Values = STD, SQT5
FONT = STD

# PPM center adjustable
# Values = YES, NO
PPM_CENTER_ADJUSTABLE = NO

# PPM symmetrical limits
# Values = YES, NO
PPM_LIMITS_SYMETRICAL = NO

# PPM display unit
# Values = PERCENT_PREC1, PERCENT_PREC0, US
PPM_UNIT = PERCENT_PREC1

# OverrideCHxx functions enable
# Values = YES, NO
OVERRIDE_CHANNEL_FUNCTION = YES

# Dangerous functions available in Custom Functions (range test, bind, module off)
# Values = YES, NO
DANGEROUS_MODULE_FUNCTIONS = NO

# FrSky Hub
# Values = YES, NO
FRSKY_HUB = YES

# FrSky FAS current sensor offset compensation
# Values = YES, NO
FAS_OFFSET = NO

# WS HowHigh
# Values = YES, NO
WS_HOW_HIGH = YES

# Gauges in Telemetry screen
# Values = YES, NO
GAUGES = YES

# GPS
# Values = YES, NO
GPS = YES

# Vario
# Values = YES, NO
VARIO = YES

# RTCLOCK
# Values = YES, NO
# default = YES (means enabled when available)
RTCLOCK = YES

# Hardware volume
# Values = YES, NO
# default = YES (AR9X board doesn't have a hardware volume control as delivered but it can be fitted optionally)
HARDWARE_VOLUME = YES

# BLUETOOTH
# Values = YES, NO
BLUETOOTH = NO

# PXX (FrSky PCM) protocol
PXX = NO

# DSM2 (Spektrum) protocol
# Values = NO, SERIAL, PPM
DSM2 = NO

# HUBSAN protocol
# Values = NO, YES
HUBSAN = NO

# DSM/PPM TX caddy PCB (Gruvin)
# For auto-switching switching between DSM2/X and Fr-Sky transmitter modules
# Values = YES, NO
TX_CADDY = NO

#IR protocols (SILV / TRAC09 / PICZ / SWIFT)
IRPROTOS = NO

# TRANSLATIONS
# Values = cz, de, en, fi, fr, it, se, es, pl, pt, nl
TRANSLATIONS = EN

# TTS
# Values = en, fr, hu
TTS = $(TRANSLATIONS)

# UNITS
# Values = imperial, metric
UNITS = METRIC

# Default Tx Mode
# Values = NO / 1 / 2 / 3 / 4
DEFAULT_MODE = NO

# EEPROM_PROGRESS_BAR
# Values = YES, NO
EEPROM_PROGRESS_BAR = NO

# Shutdown confirmation (for boards which have soft power)
# Values = NO, YES
SHUTDOWN_CONFIRMATION = NO

# Activates the DEBUG Mode (all boards)
# On G9X V4 board, when VOICE=NO:
#  PORTH:7 --> Transition LOW to HIGH = start of setupPulses(). Transition HIGH to LOW = end of setupPulses().
#  PORTH:6 --> LOW->HIGH = start of mixer calcs. HIGH->LOW, end of mixer calcs.
# Values = YES, NO
DEBUG = NO

# Activate Command Line Interpreter
# Values = NO, YES
CLI = NO

# Activate writing of SPORT telemetry received data to sport.log file
# Values = YES, NO
SPORT_FILE_LOG = NO

# Timers Count
# Values = 1, 2, 3 (on ARM boards)
TIMERS = 2

# Flight Modes
# Values = YES, NO
FLIGHT_MODES = YES

# Curves
# Values = YES, NO
CURVES = YES

# Global Vars
# Values = YES, NO
GVARS = NO

# Enable another 3 positions switch to replace a pot
# Values = NO, POT1, POT2, POT3,
3POS = NO

# Lua interpreter embedded
# Values = NO, NO_MODEL_SCRIPTS, YES
LUA = NO

# Menu Lock modes
# Values = NO, READONLY, NOMENUS
MENUS_LOCK = NO

# USB options in the main image
# Values = JOYSTICK, MASSSTORAGE, SERIAL
# JOYSTICK: The TX will appear as a joystick
# MASSSTORAGE: The TX will appear as a drive
# SERIAL: The TX will appear as a serial port
USB = JOYSTICK

# Mixers monitor view added to Channels monitor one
# Values = NO, YES
# YES - Adds mixers output view to Channels monitor screen,
# pressing [ENT] switches between views.
# NO - classic Channels monitor
MIXERS_MONITOR = NO

# Use newlib-nano
# Values = NO, YES
NANO = NO

# Use custom bin based allocator for Lua
# Values = NO, YES
# YES - use our bin based allocator
# NO - use default Lua allocator
USE_BIN_ALLOCATOR = NO

# Enable trace of events into Trace Buffer for debugging purposes
# Activating any of these options also activates DEBUG and DEBUG_TRACE_BUFFER
# Values = NO, YES
#   TRACE_SD_CARD     SD card operations (read, write, etc)
#   TRACE_FATFS       FatFs file operations
#   TRACE_AUDIO       Audio processing (not yet implemented)
TRACE_SD_CARD = NO
TRACE_FATFS = NO
TRACE_AUDIO = NO

# Enable double buffering for LCD. Only for TARANIS PLUS and 9XE targets.
# Activating requires about 6kB of RAM, but it enables menus task to
# immediately start to compose a new LCD image while the current one is
# being written to LCD by DMA.
# If this option is NO, then first function that affects LCD buffer is
# delayed until DMA transfer is finished.
# Values = NO, YES
LCD_DUAL_BUFFER = NO

# Enable internal module PPM mode for Taranis
# Values = NO, YES
TARANIS_INTERNAL_PPM = NO

# Support for D16-EU only (no D8, no LR12 which are not EU compatible)
# Value = NO, YES
SUPPORT_D16_EU_ONLY = NO


# Treat compiler warnings as errors
# Values = NO, YES
WARNINGS_AS_ERRORS = NO

# Enable saving of Lua byte-code of all loaded scripts
# Values = NO, YES
LUA_COMPILER = NO

# Enable ADC jitter measurement
# Values = NO, YES
JITTER_MEASURE = NO

#------- END BUILD OPTIONS ---------------------------

# Define programs and commands.
SHELL = sh

IMG2LBM = -python ../util/img2lbm.py
BIN2LBM = -python ../util/bin2lbm.py
FONT2PNG = -python ../util/font2png.py
TRANSLATE = -python ../util/translate.py

VERSION_MAJOR = 2
VERSION_MINOR = 1
VERSION_REVISION = 9

VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_REVISION)$(OPENTX_VERSION_SUFFIX)

SRC =
CPPSRC =
INCDIRS = . translations
LUADEP =
DEBUG_TRACE_BUFFER = NO

GUIDIRECTORY = 9X
FLAVOUR = mega2560
ARCH = AVR
LCDSIZE = 128
TRGT = avr-
MCU = atmega2560
OPT = s
CPPDEFS = -DF_CPU=$(F_CPU)UL -DPCBMEGA2560 -DCPUM2560 -DEEPROM_RLC -DEEPROM_VARIANT=0
SDCARD = NO
BUZZER = YES
THR_TRACE = YES
PWRMANAGE = NO
INCDIRS = boards/mega2560
BOARDSRC = watx.cpp 
EEPROMSRC = eeprom_common.cpp
# INCDIRS += targets/mega2560 targets/stock $(FATFSDIR) $(FATFSDIR)/option
# BOARDSRC = main_avr.cpp targets/mega2560/board_mega2560.cpp
# EEPROMSRC = eeprom_common.cpp eeprom_rlc.cpp
# PULSESSRC = pulses/pulses_avr.cpp
# CPPSRC += debug.cpp
#BITMAPS += bitmaps/9X/splash.lbm bitmaps/9X/asterisk.lbm bitmaps/9X/about.lbm
GUIGENERALSRC += gui/$(GUIDIRECTORY)/menu_general_diagkeys.cpp gui/$(GUIDIRECTORY)/menu_general_diaganas.cpp

#EXTRABOARDSRC = targets/common_avr/adc_driver.cpp targets/stock/lcd_driver.cpp targets/common_avr/telemetry_driver.cpp
     
ifeq ($(PWRMANAGE), YES)
CPPDEFS += -DPWRMANAGE
endif

ifeq ($(SDCARD), YES)
EXTRABOARDSRC += $(FATFSDIR)/ff.c $(FATFSDIR)/fattime.c $(FATFSDIR)/option/ccsbcs.c targets/gruvin9x/diskio.cpp
CPPDEFS += -DSDCARD -DRTCLOCK
GUIGENERALSRC += gui/$(GUIDIRECTORY)/menu_general_sdmanager.cpp
CPPSRC += rtc.cpp sdcard.cpp logs.cpp targets/gruvin9x/rtc_driver.cpp
endif

ifeq ($(AUDIO), YES)
	CPPDEFS += -DAUDIO
	CPPSRC += audio_avr.cpp
	BUZZER = NO
else
	BUZZER = YES
endif

ifeq ($(BUZZER), YES)
CPPDEFS += -DBUZZER
CPPSRC += audio/buzzer.cpp
endif

ifeq ($(VOICE), YES)
CPPDEFS += -DVOICE
CPPSRC += targets/gruvin9x/somo14d.cpp
endif

ifeq ($(HAPTIC), YES)
CPPDEFS += -DHAPTIC
CPPSRC += haptic.cpp
endif

# Enable extra rotary encoders
ROTARY_ENCODERS = 2
CPPDEFS += -DROTARY_ENCODERS=${ROTARY_ENCODERS}
CPPDEFS += -DTIMERS=$(TIMERS)

CC      = $(TRGT)gcc
CPP     = $(TRGT)cpp
AS      = $(TRGT)as
OBJCOPY = $(TRGT)objcopy
OBJDUMP = $(TRGT)objdump
SIZE    = $(TRGT)size
NM      = $(TRGT)nm

REMOVE = rm -f
REMOVEDIR = rm -rf

SLEEP = sleep

# Processor frequency.
F_CPU = 16000000

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Target file name (without extension).
TARGET = watx

CPPFLAGS = -g$(DBGFMT)

ifeq ($(GUI), YES)
  GUISRC = gui/helpers.cpp gui/navigation.cpp gui/popups.cpp gui/widgets.cpp gui/menus.cpp gui/view_main.cpp gui/view_statistics.cpp
  GUISRC += gui/lcd.cpp gui/splash.cpp gui/fonts.cpp
  CPPDEFS += -DGUI
endif
INCDIRS += gui

DBGFMT = dwarf-2
MAJ_VER = ${shell sh -c "grep \"MAJ_VERS\" opentx.h | cut -d\  -f3 | egrep -o \"[[:digit:]]\""}
MIN_VER = ${shell sh -c "grep \"MIN_VERS\" opentx.h | cut -d\  -f3"}


MATH_LIB = -lm

#---------------- Linker Options ----------------
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
LDFLAGS = -Wl,-Map=$(TARGET).map,--cref
LDFLAGS += $(MATH_LIB)

CPPFLAGS += $(CPPDEFS)
CPPFLAGS += -Wall
CPPFLAGS += -fno-exceptions
CPPFLAGS += -Wno-strict-aliasing
CPPFLAGS += -Wformat -Wreturn-type -Wunused -Wuninitialized -Wunknown-pragmas -Wno-switch -Wtype-limits
INCFLAGS = $(patsubst %,-I%,$(INCDIRS))

CPPFLAGS += -DFLAVOUR=\"$(FLAVOUR)\"

GCCVERSIONGTE462 := $(shell expr 4.6.2 \<= `$(CC) -dumpversion`)
ifeq ($(GCCVERSIONGTE462),1)
	CPPFLAGS += -flto
endif

AVRCPPFLAGS += -fno-inline-small-functions

GCCVERSIONGTE470 := $(shell expr 4.7.0 \<= `$(CC) -dumpversion`)
ifeq ($(GCCVERSIONGTE470),1)
	AVRCPPFLAGS += -mstrict-X
endif

AVRCPPFLAGS = -mmcu=$(MCU) -I. -x c++ -O$(OPT) $(CPPFLAGS) $(INCFLAGS) $(GENDEPFLAGS) -fwhole-program


all: stamp_header watx.elf

# Concatenate all sources files in one big file to optimize size
# allsrc.cpp: Makefile $(BOARDSRC) $(CPPSRC) $(EXTRABOARDSRC)
# 	@rm -f allsrc.cpp
# 	for f in $(BOARDSRC) $(CPPSRC) $(EXTRABOARDSRC) ; do echo "# 1 \"$$f\"" >> allsrc.cpp; cat "$$f" >> allsrc.cpp; done

stamp_header:
	@echo "// Automatically generated file (Makefile) - do not edit" > stamp-watx.h
	@echo "#define DATE_STR \"`date +%Y-%m-%d | tr -d '\r\n'`\"" >> stamp-watx.h
	@echo "#define TIME_STR \"`date +%H:%M:%S | tr -d '\r\n'`\"" >> stamp-watx.h
	@echo "#define VERS_STR \"$(VERSION)\"" >> stamp-watx.h
	@echo "" >> stamp-watx.h
	@echo "#define VERSION_MAJOR     $(VERSION_MAJOR)" >> stamp-watx.h
	@echo "#define VERSION_MINOR     $(VERSION_MINOR)" >> stamp-watx.h
	@echo "#define VERSION_REVISION  $(VERSION_REVISION)" >> stamp-watx.h
	@echo "#define GIT_STR \"$(shell git rev-parse HEAD)\"" >> stamp-watx.h

watx.elf: watx.cpp
	@echo
	@echo $(MSG_COMPILING) $@
	$(CC) $(AVRCPPFLAGS) $< --output $@ $(LDFLAGS)