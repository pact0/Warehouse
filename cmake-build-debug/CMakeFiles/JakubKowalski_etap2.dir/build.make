# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\JakubKowalski_etap2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\JakubKowalski_etap2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\JakubKowalski_etap2.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\JakubKowalski_etap2.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\JakubKowalski_etap2.dir\flags.make

CMakeFiles\JakubKowalski_etap2.dir\main.cpp.obj: CMakeFiles\JakubKowalski_etap2.dir\flags.make
CMakeFiles\JakubKowalski_etap2.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\JakubKowalski_etap2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JakubKowalski_etap2.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\JakubKowalski_etap2.dir\main.cpp.obj /FdCMakeFiles\JakubKowalski_etap2.dir\ /FS -c D:\Documents\JakubKowalski_etap2\main.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JakubKowalski_etap2.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\JakubKowalski_etap2.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\JakubKowalski_etap2\main.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JakubKowalski_etap2.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\JakubKowalski_etap2.dir\main.cpp.s /c D:\Documents\JakubKowalski_etap2\main.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.obj: CMakeFiles\JakubKowalski_etap2.dir\flags.make
CMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.obj: ..\Produkt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\JakubKowalski_etap2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/JakubKowalski_etap2.dir/Produkt.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.obj /FdCMakeFiles\JakubKowalski_etap2.dir\ /FS -c D:\Documents\JakubKowalski_etap2\Produkt.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JakubKowalski_etap2.dir/Produkt.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\JakubKowalski_etap2\Produkt.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JakubKowalski_etap2.dir/Produkt.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.s /c D:\Documents\JakubKowalski_etap2\Produkt.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.obj: CMakeFiles\JakubKowalski_etap2.dir\flags.make
CMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.obj: ..\Magazyn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\JakubKowalski_etap2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/JakubKowalski_etap2.dir/Magazyn.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.obj /FdCMakeFiles\JakubKowalski_etap2.dir\ /FS -c D:\Documents\JakubKowalski_etap2\Magazyn.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JakubKowalski_etap2.dir/Magazyn.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\JakubKowalski_etap2\Magazyn.cpp
<<

CMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JakubKowalski_etap2.dir/Magazyn.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.s /c D:\Documents\JakubKowalski_etap2\Magazyn.cpp
<<

# Object files for target JakubKowalski_etap2
JakubKowalski_etap2_OBJECTS = \
"CMakeFiles\JakubKowalski_etap2.dir\main.cpp.obj" \
"CMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.obj" \
"CMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.obj"

# External object files for target JakubKowalski_etap2
JakubKowalski_etap2_EXTERNAL_OBJECTS =

JakubKowalski_etap2.exe: CMakeFiles\JakubKowalski_etap2.dir\main.cpp.obj
JakubKowalski_etap2.exe: CMakeFiles\JakubKowalski_etap2.dir\Produkt.cpp.obj
JakubKowalski_etap2.exe: CMakeFiles\JakubKowalski_etap2.dir\Magazyn.cpp.obj
JakubKowalski_etap2.exe: CMakeFiles\JakubKowalski_etap2.dir\build.make
JakubKowalski_etap2.exe: CMakeFiles\JakubKowalski_etap2.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\JakubKowalski_etap2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable JakubKowalski_etap2.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\JakubKowalski_etap2.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\JakubKowalski_etap2.dir\objects1.rsp @<<
 /out:JakubKowalski_etap2.exe /implib:JakubKowalski_etap2.lib /pdb:D:\Documents\JakubKowalski_etap2\cmake-build-debug\JakubKowalski_etap2.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\JakubKowalski_etap2.dir\build: JakubKowalski_etap2.exe

.PHONY : CMakeFiles\JakubKowalski_etap2.dir\build

CMakeFiles\JakubKowalski_etap2.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\JakubKowalski_etap2.dir\cmake_clean.cmake
.PHONY : CMakeFiles\JakubKowalski_etap2.dir\clean

CMakeFiles\JakubKowalski_etap2.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Documents\JakubKowalski_etap2 D:\Documents\JakubKowalski_etap2 D:\Documents\JakubKowalski_etap2\cmake-build-debug D:\Documents\JakubKowalski_etap2\cmake-build-debug D:\Documents\JakubKowalski_etap2\cmake-build-debug\CMakeFiles\JakubKowalski_etap2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\JakubKowalski_etap2.dir\depend

