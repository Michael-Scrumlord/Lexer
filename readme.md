# Lexer / Scanner

## Project 1
## Created by Michael Daza

- [Installation]
- [Usage]

## Installation

Run the included executable 'Lexer-Scanner.exe' from within the Lexer folder. 
The only real trick is that the output.txt file and the input_scode.txt file have to be in the same directory and at the same level as the executable. 

## Usage

The input_scode.txt file contains the code to be tokenized. In theory, you are able to modify the code within this file and run the same executable mentioned above and achieve the same results.

The program writes to the output.txt file and appends each write - so be aware that this file only gets bigger. It's easy to remove the append and the program will still function normally.

The program can be scaled to include some additional keywords, particulary in the lexemeMap map defined in the beginning, where additional keywords or other tokens can be added.