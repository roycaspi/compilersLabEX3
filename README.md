# Compilers Lab Exercise 3

## Overview

This repository contains the third exercise for the Compilers Lab course. The project involves implementing a simple compiler using tools like Flex and Bison to parse and interpret a custom language.

## Features

- **Lexical Analysis**: Utilizes Flex (`sle_la.l`) to define lexical tokens.
- **Syntax Analysis**: Employs Bison (`lps.y`) to define grammar rules and parsing logic.
- **Intermediate Code Generation**: Generates intermediate code for the parsed input.
- **Execution**: Supports execution of the intermediate code to perform computations.

## Repository Structure

- `sle_la.l`: Flex file defining the lexical analyzer.
- `lps.y`: Bison file defining the grammar and parser.
- `lps_tab.c` and `lps_tab.h`: Generated parser source and header files.
- `lex.yy.c`: Generated lexical analyzer source file.
- `CMakeLists.txt`: Build configuration for CMake.
- `bison/`: Directory containing Bison executable and related files.
- `flex.exe`: Flex executable.
- `.gitignore`: Specifies files to ignore in version control.

## Prerequisites

- **CMake**: Ensure CMake is installed to build the project.
- **Flex**: Lexical analyzer generator.
- **Bison**: Parser generator.

## Building the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/roycaspi/compilersLabEX3.git
   cd compilersLabEX3
   ```

2. **Generate Parser and Lexer**:
   ```bash
   bison -d lps.y -o lps_tab.c
   flex -o lex.yy.c sle_la.l
   ```

3. **Build with CMake**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

   This will produce the executable for the compiler.

## Usage

After building, you can run the compiler with an input file containing code in the custom language:

```bash
./compiler_executable input_file.txt
```

Replace `compiler_executable` with the actual name of the generated executable and `input_file.txt` with your source code file.

## Example

Given an input file `example.txt`:

```
BEGIN
  x := 5;
  y := x * 2;
  PRINT y;
END
```

Running the compiler:

```bash
./compiler_executable example.txt
```

Expected output:

```
10
```

## Notes

- Ensure that `bison` and `flex` are properly installed and accessible in your system's PATH.
- The provided `bison.exe` and `flex.exe` are for convenience but may not be compatible with all systems.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments

- [Flex](https://github.com/westes/flex): The Fast Lexical Analyzer.
- [Bison](https://www.gnu.org/software/bison/): The Yacc-compatible Parser Generator.
