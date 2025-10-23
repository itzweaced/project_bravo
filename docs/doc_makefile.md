# What is a Makefile?
- Acts like a Batch script
- Acts like a linker in Codeblocks or Visual Studio: linking files and libraries to compiler
- Can tell the compiler where to output the executable .exe
- On Windows with the Mingw Compiler, entering command <mingw32-make> into terminal compile the program, and then output the exe into a designated output folder.
- For Project Bravo the Makefile is located in the project's root directory. Once you enter <mingw32-make> into the command line, a .exe is outputted to the bin folder.
- You have to either name it "makefile" or "Makefile"
- If compiler catches an Error, a .exe will not be outputted and may delete previous exe located in bin.