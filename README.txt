Assembler README

This is an assembler for Hack assembly language, written by Allen Nelson.

Note: For some reason, the native encoding of the assembly files provided by
the book, fail to load properly. The fix for this is to first copy/paste the
contents of the files into a new text file, and run the assembler on that file.

Compile with the following:
clang++ -std=c++11 -stdlib=libc++ -o assembler assembler.cpp

Usage:
./assembler <inputfile> [optional <outputfile>]