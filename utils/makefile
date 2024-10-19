#
# Project: P26_ROVER
#

# Build process:
# 1) Connect via remote desktop to RPI
# 2) .bashrc should take you to project build directory
# 3) run 'clear && resync && make'

define NEWLINE
endef

# Folders
PROJECT_ROOT=..
APP_DIR		= $(PROJECT_ROOT)/app
OS_DIR		= $(PROJECT_ROOT)/os
MCAL_DIR	= $(PROJECT_ROOT)/mcal
OUT_DIR		= $(PROJECT_ROOT)/out
LIB_DIR		= $(PROJECT_ROOT)/lib

APP_MODULES = \
dummy_app \
ui \
light_ctrlr \
steer_sys_drv \
pwtr_drv \
veh \
buzzer

#assemble list of source files
SRC_LIST += $(wildcard $(MCAL_DIR)/*.cpp)
SRC_LIST += $(wildcard $(OS_DIR)/*.cpp)
SRC_LIST += $(wildcard $(LIB_DIR)/*.cpp)
SRC_LIST += $(foreach module, $(APP_MODULES), $(wildcard $(APP_DIR)/$(module)/*.cpp))

#assemble list of include directories
INCLUDE_LIST += $(foreach module, $(APP_MODULES), -I$(wildcard $(APP_DIR)/$(module)))
INCLUDE_LIST += -I$(OS_DIR)
INCLUDE_LIST += -I$(MCAL_DIR)
INCLUDE_LIST += -I$(LIB_DIR)

#compiler
CC=g++
# MMCU=atmega328P
CFLAGS= -Wall -Os #-std=c99 -mmcu=$(MMCU)
# DEFINES = 	-D DUMMY_DEFINE_1 \

# include ../config/global_config.cfg
# include ../config/diag_config.cfg

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


