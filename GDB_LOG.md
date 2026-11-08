# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:
break hangman::hangman
run
n
bt


Backtrace inside `Hangman::Hangman` (paste it):
#0  Hangman::Hangman (this=0x7fffffffe1a0, title="Hangman") at /home/ubuntu/cosc1437/lab12/src/hangman.cpp:128
#1  0x0000555555557764 in main () at /home/ubuntu/cosc1437/lab12/app/main.cpp:49


Backtrace inside `Game::Game` (paste it):
#0  Game::Game (this=0x7fffffffe1a0, title="Hangman") at /home/ubuntu/cosc1437/lab12/src/game.cpp:5
#1  0x000055555555e1c7 in Hangman::Hangman (this=0x7fffffffe1a0, title="")
    at /home/ubuntu/cosc1437/lab12/src/hangman.cpp:129
#2  0x0000555555557764 in main () at /home/ubuntu/cosc1437/lab12/app/main.cpp:49


Where `finish` returned to:
finish returned execution back to the Hangman::Hangman constructor body right after the base constructor finished initializing.

When you used finish while inside Game::Game, GDB ran until that base constructor completed and brought you back to the next line inside the derived Hangman constructor.

Order of destructor breakpoints when the program ended:
Hangman::~Hangman (Derived class destructor runs first)
Game::~Game (Base class destructor runs second)

Construction order and destruction order, as read from the backtraces:
The backtraces prove that construction happens from the base up—main() calls Hangman::Hangman, which immediately chains to and executes Game::Game first. Conversely, destruction happens in the exact reverse order, cleaning up the derived class first (Hangman::~Hangman) and the base class second (Game::~Game).


### What a base pointer shows

`print hangman` (paste it):

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:
