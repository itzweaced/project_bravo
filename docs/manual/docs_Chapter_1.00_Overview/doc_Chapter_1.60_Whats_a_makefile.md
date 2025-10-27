# NAVIGATION
- [Table of Contents](..\Table_of_Contents.md)

# CHAPTER
1.60


# TITTLE
What is a Makefile?


# DESCRIPTION
A Makefile is located in the base directory. Its a file that tells the compiler how to link the file inside the project and 3rd party libraries used.

# HIGHLIGHTS
- Acts like a Batch script
- Acts like a linker in Codeblocks or Visual Studio: linking files and libraries to compiler
- Can tell the compiler where to output the executable .exe
- On Windows with the Mingw Compiler, entering command mingw32-make into terminal compile the program, and then output the exe into a designated output folder.
- For Project Bravo the Makefile is located in the project's root directory. Once you enter mingw32-make into the command line, a .exe is outputted to the bin folder.
- You have to either name it "makefile" or "Makefile"
- If compiler catches an Error, a .exe will not be outputted and may delete previous exe located in bin.


# BODY



