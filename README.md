# Minishell

Minishell is a project that involves recoding a simple shell similar to Bash. It is capable of parsing commands, launching executables with arguments, and implementing several built-in functions.

## Final Grade
- **Overall**: 101/115
- **Mandatory Part**: 100/100
- **Bonus**: 1/15

## Features
- Executes commands from absolute, relative, or environment PATH (`/bin/ls`, `ls`)
- Supports command arguments and options
- Handles single and double quotes like Bash (except for multiline commands)
- Supports command separators (`;`), redirections (`>`, `>>`, `<`), and pipes (`|`)
- Environment variable expansion (`$HOME`, `$?` for return codes)
- Signal handling: 
  - `Ctrl-C` to interrupt
  - `Ctrl-\` to quit
  - `Ctrl-D` to send EOF
- Built-in commands:
  - `echo`
  - `pwd`
  - `cd`
  - `env`
  - `export`
  - `unset`
  - `exit`

## Installation
To compile Minishell, run:
```sh
make
```

## Usage
To launch Minishell, simply run:
```sh
./minishell
```

## Authors
- Mohamed Douzi

## License
This project is part of the 42 curriculum and follows its academic integrity rules.

