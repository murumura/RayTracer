INCLUDE_DIR := include
INCLUDE_FILE := $(wildcard $(INCLUDE_DIR)/*.hh)

SRCDIR = src
SRC      := $(wildcard $(SRCDIR)/*.cc)         

format:
	clang-format \
	-style=\
	"{BasedOnStyle: Google,BreakBeforeBraces: Stroustrup, IndentWidth: 4, IndentCaseLabels: false, TabWidth: 4, UseTab: ForIndentation, ColumnLimit: 0}"\
	 -i $(SRC) $(INCLUDE_FILE) 
