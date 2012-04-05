Name:		Dylan Symons
Student #:	100184844
----------------------------

Assignment: [lab07] Keyboard LEDs
----------------------------

Description:
----------------------------
This program has two parts:
   1) A driver, used to control the keyboard lock
      key LEDs, contained in the directory 'driver/'
   2) A userspace program used to flash the LEDs
      in the morse code translation of a uesr-
      specified message

Included files:
----------------------------

- COPYING
- INSTALL
- Makefile.am
- Makefile.in
- README
- aclocal.m4
- config.h.in
- configure
- configure.ac
- depcomp
- doc/
    - lmorse.6
    - myleds.4
- etc/
    - lmorse_translations
- install-sh
- missing
- module/
    - Makefile
    - myleds.c
    - myleds.h
- mymakefile
- readme.txt
- src/
    - Makefile.am
    - Makefile.in
    - arg_parsing.c
    - arg_parsing.h
    - driver_control.c
    - driver_control.h
    - led_morse.c
    - led_morse.h
    - table.c
    - table.h
    - text_output.c
    - text_output.h

Running my solution:
----------------------------
To run the solution, the driver needs to be
installed, a makefile generated, the program compiled,
and finally run. Good luck!

1) To install the driver, execute (including quotes):
> cd module
> su -c "make; make install"
> cd ..

2) To build the makefile:
> ./configure

3.1) To compile and run, with 'HELLO WORLD' being output:
> make
> make run

3.2) To compile and run, with your own message output:
> make
> src/lmorse <message>

Compiler:
----------------------------
gcc version 4.5.2

Assumptions:
----------------------------

Conclusions/Remarks:
----------------------------
- There have been some things I've wanted to learn about
  lately, which I did for this assignment. Namely, making
  manpages and the GNU Autoconf package. If you want to
  view the manpages, run `su -c "make install"` and then
  `man myleds` or `man lmorse`, for the driver and program
  manpages, respectively. The lmorse one has some command line
  options that can be used, amongst other things.
  Getting Autoconf to work right, while maintaining specifics
  such as being able to execute `make run` took a fair big of
  learning, but this is a school assignment and thus a perfect
  opportunity for such. Hopefully I did everything right, and
  it works on computers other than my own.

Errors/Bugs:
----------------------------
- The hash table I used to store the english-to-morse translations
  has a fixed length, and each translation itself also has a fixed
  length. If the user specifies their own translations file, and their
  file contains more than I allowed, the program will be unusable
  unless recompiled. To increase the number of allowable translations,
  make the program with `make "CFLAGS=-D NUM_CHARACTERS=<x>"`, which
  will allow 'x' different character translations.
  On a side note, the 'hash table' actually isn't even really a hash
  table, just an array indexed by ASCII code. That's one of the next
  things I'd like to work on, making it both more dynamic and efficient.

