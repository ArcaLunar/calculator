# Calculator
A custom calculator which supports expression evaluations, and implements a simple variable system.

## How to use?
Run in the terminal using `gcc main.c -o a -lm` and then `./a`

`>>>>>` is intended to mock Python interactive UI, which might be a little more user-friendly.

## Supported Operation
 - `+`: addition
 - `-`: subtraction
 - `*`: multiplication
 - `/`: float division
 - `^`: power
 - `()`: braces
 - and **variable system** (variables must be **initialized** before using, otherwise default 0)

## Updates
### 2023.11.14

Fix bugs when encountering lots of braces

Fix logic of identifying negative numbers

### 2023.11.13

Divide project into `.h`s and `.c`s, easier to maintain.

Add CMake

### 2023.10

Fix bugs when encountering negative numbers.
