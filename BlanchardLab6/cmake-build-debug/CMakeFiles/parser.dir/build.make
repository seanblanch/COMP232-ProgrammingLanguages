# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sean1\Desktop\BlanchardLab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

CMakeFiles/parser.dir/src/main.c.obj: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/src/main.c.obj: CMakeFiles/parser.dir/includes_C.rsp
CMakeFiles/parser.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/parser.dir/src/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\parser.dir\src\main.c.obj   -c C:\Users\sean1\Desktop\BlanchardLab6\src\main.c

CMakeFiles/parser.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/src/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sean1\Desktop\BlanchardLab6\src\main.c > CMakeFiles\parser.dir\src\main.c.i

CMakeFiles/parser.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/src/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sean1\Desktop\BlanchardLab6\src\main.c -o CMakeFiles\parser.dir\src\main.c.s

CMakeFiles/parser.dir/src/parser.c.obj: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/src/parser.c.obj: CMakeFiles/parser.dir/includes_C.rsp
CMakeFiles/parser.dir/src/parser.c.obj: ../src/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/parser.dir/src/parser.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\parser.dir\src\parser.c.obj   -c C:\Users\sean1\Desktop\BlanchardLab6\src\parser.c

CMakeFiles/parser.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/src/parser.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sean1\Desktop\BlanchardLab6\src\parser.c > CMakeFiles\parser.dir\src\parser.c.i

CMakeFiles/parser.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/src/parser.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sean1\Desktop\BlanchardLab6\src\parser.c -o CMakeFiles\parser.dir\src\parser.c.s

CMakeFiles/parser.dir/src/eval.c.obj: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/src/eval.c.obj: CMakeFiles/parser.dir/includes_C.rsp
CMakeFiles/parser.dir/src/eval.c.obj: ../src/eval.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/parser.dir/src/eval.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\parser.dir\src\eval.c.obj   -c C:\Users\sean1\Desktop\BlanchardLab6\src\eval.c

CMakeFiles/parser.dir/src/eval.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/src/eval.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sean1\Desktop\BlanchardLab6\src\eval.c > CMakeFiles\parser.dir\src\eval.c.i

CMakeFiles/parser.dir/src/eval.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/src/eval.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sean1\Desktop\BlanchardLab6\src\eval.c -o CMakeFiles\parser.dir\src\eval.c.s

CMakeFiles/parser.dir/src/scanner_ad_hoc.c.obj: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/src/scanner_ad_hoc.c.obj: CMakeFiles/parser.dir/includes_C.rsp
CMakeFiles/parser.dir/src/scanner_ad_hoc.c.obj: ../src/scanner_ad_hoc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/parser.dir/src/scanner_ad_hoc.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\parser.dir\src\scanner_ad_hoc.c.obj   -c C:\Users\sean1\Desktop\BlanchardLab6\src\scanner_ad_hoc.c

CMakeFiles/parser.dir/src/scanner_ad_hoc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/src/scanner_ad_hoc.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sean1\Desktop\BlanchardLab6\src\scanner_ad_hoc.c > CMakeFiles\parser.dir\src\scanner_ad_hoc.c.i

CMakeFiles/parser.dir/src/scanner_ad_hoc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/src/scanner_ad_hoc.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sean1\Desktop\BlanchardLab6\src\scanner_ad_hoc.c -o CMakeFiles\parser.dir\src\scanner_ad_hoc.c.s

# Object files for target parser
parser_OBJECTS = \
"CMakeFiles/parser.dir/src/main.c.obj" \
"CMakeFiles/parser.dir/src/parser.c.obj" \
"CMakeFiles/parser.dir/src/eval.c.obj" \
"CMakeFiles/parser.dir/src/scanner_ad_hoc.c.obj"

# External object files for target parser
parser_EXTERNAL_OBJECTS =

parser.exe: CMakeFiles/parser.dir/src/main.c.obj
parser.exe: CMakeFiles/parser.dir/src/parser.c.obj
parser.exe: CMakeFiles/parser.dir/src/eval.c.obj
parser.exe: CMakeFiles/parser.dir/src/scanner_ad_hoc.c.obj
parser.exe: CMakeFiles/parser.dir/build.make
parser.exe: CMakeFiles/parser.dir/linklibs.rsp
parser.exe: CMakeFiles/parser.dir/objects1.rsp
parser.exe: CMakeFiles/parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable parser.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\parser.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: parser.exe

.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\parser.dir\cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sean1\Desktop\BlanchardLab6 C:\Users\sean1\Desktop\BlanchardLab6 C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug C:\Users\sean1\Desktop\BlanchardLab6\cmake-build-debug\CMakeFiles\parser.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser.dir/depend

