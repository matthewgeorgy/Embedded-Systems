# Embedded-Systems
Source code for TEJ3M1 Robot (Gr.11 Computer Engineering)

Here is a video showcasing the actual robot itself: https://youtu.be/aZE8ZVy-puc

Here you can find the source code that was written for my embedded systems group project.
There are 3 folders:
- c
- lst
- map

"c" contains the actual source code that was written in C. These are the actual
files that we wrote, and there are clearly many of them. This project was 1.5 months 
long, requiring us to write different source codes to accomplish different tasks. 
Hence, the source code for one file might look completely different from the source
code in another file.

"lst" contains the assembly code (compiled from the C source code files). 
Not all of the C files have a corresponding .lst file, and not all .lst files
were written by me or my group members.

"map" contains the linker files for the compiler(???). I think that's what it is
just from looking at it, but we never actually directly accessed and modified 
these file while working on the project.


You'll notice that some of the code is quite hideous (eg. several if/else if 
statements instead of a switch statement). This is the class where we first
learned C and did any kind of programming. Furthermore, the lessons we 
followed were simple and didn't cover various topics. The focus of the 
project was more so understanding how to directly access and talk to 
hardware, rather than writing optimal, fast, and efficient code.
