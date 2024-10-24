#
# Project: P26_ROVER
#

# Build process:
# 1) Connect via remote desktop to RPI
# 2) .bashrc should take you to project build directory
# 3) run 'clear && make'

define NEWLINE
endef

# Folders
PROJECT_ROOT=..
APP_DIR		= $(PROJECT_ROOT)/app
DRV_DIR		= $(PROJECT_ROOT)/drv
CLASS_DIR   = $(PROJECT_ROOT)/class
LIB_DIR		= $(PROJECT_ROOT)/lib
OUT_DIR		= $(PROJECT_ROOT)/out

DRV_LIST = \
pwtr \
light_ctrl \
steer_sys \
fan_ctrl \
buzzer \
tacho

APP_LIST = \
init \
os \
dummy_app \
ui \
veh

CLASS_LIST = \
pwm_channel

#assemble list of source files
SRC_LIST += $(wildcard $(LIB_DIR)/*.cpp)
SRC_LIST += $(foreach module, $(APP_LIST), 	$(wildcard $(APP_DIR)/$(module)/*.cpp))
SRC_LIST += $(foreach module, $(DRV_LIST), 	$(wildcard $(DRV_DIR)/$(module)/*.cpp))
SRC_LIST += $(foreach class,  $(CLASS_LIST),$(wildcard $(CLASS_DIR)/$(class)/*.cpp))

#assemble list of include directories
INCLUDE_LIST += $(foreach module, $(APP_LIST), 	-I$(wildcard $(APP_DIR)/$(module)))
INCLUDE_LIST += $(foreach module, $(DRV_LIST),  -I$(wildcard $(DRV_DIR)/$(module)))
INCLUDE_LIST += $(foreach class,  $(CLASS_LIST),-I$(wildcard $(CLASS_DIR)/$(class)))
INCLUDE_LIST += -I$(LIB_DIR)

#compiler
CC=g++
# MMCU=atmega328P
CFLAGS= -Wall -Os #-std=c99 -mmcu=$(MMCU)
# DEFINES = 	-D DUMMY_DEFINE_1 \

#default rule
all: clean p26_rover print_ok

#compile project P24 Rover
p26_rover: 
	$(info  ********************************************************************************************************* )
	$(info 	Building target: $@)

	$(info $(NEWLINE))
	$(info List of file to be build:)
	$(foreach file, $(SRC_LIST),  $(info $(file)))

	$(info $(NEWLINE))
	$(info List of file to be included:)
	$(foreach file, $(INCLUDE_LIST),  $(info $(file)))

	$(info $(NEWLINE))
	@$(CC) $(SRC_LIST) $(INCLUDE_LIST) -lwiringPi -lncurses $(CFLAGS) $(DEFINES) -o $(OUT_DIR)/$@
	$(info Finished building target: $@)
	$(info $(NEWLINE))

# make clean
clean:
	$(info  ********************************************************************************************************* )
	@rm -f $(OUT_DIR)/*
	$(info ### Clean finished! ###)
	$(info $(NEWLINE))

# just decoration
print_ok:
	$(info  ********************************************************************************************************* )
	@echo '					              ____'
	@echo '					            /____ `\'
	@echo '					           ||_  _`\ \'
	@echo '					     .-.   `|O, O  ||'
	@echo '					     | |    (/    -)\'
	@echo '					     | |    |`- ` |\`'
	@echo '					  __/  |    | _/  |'
	@echo '					 (___) \.  _.\__. `\___'
	@echo '					 (___)  )\/  \    _/  ~\.'
	@echo '					 (___) . \   `--  _   `\	'
	@echo '					  (__)-    ,/        (   |'
	@echo '					       `--~|         |   |'
	@echo '					           |         |   |'
	@echo '				******                             ******'
	@echo '				****  Finished building all targets  ****'
	@echo '				******                             ******'


