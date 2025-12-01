CC = gcc
Solution = day_1
SourceDir = .\\c

SolutionDir = $(SourceDir)\\solutions
TargetDir = .\\bin
DebugDir = .\\bin\\debug

SolutionFile = $(SolutionDir)\\$(Solution).c
MainFile = $(SourceDir)\\main.c
OutFile = prog.exe

clean:
	if not exist $(TargetDir) mkdir $(TargetDir)
	del /q $(TargetDir)\\*

clean_debug:
	if not exist $(DebugDir) mkdir $(DebugDir)
	del /q $(DebugDir)\\*

build:
	$(CC) $(MainFile) $(SolutionFile) -o $(TargetDir)\\$(OutFile)

debug:
	$(CC) $(MainFile) $(SolutionFile) -o $(DebugDir)\\$(OutFile)

all: clean build

all_debug: clean_debug debug
