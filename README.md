# Simple Shell (hsh)

## Table of Contents
* [Introduction](#introduction)
* [Environment](#environment)
* [Usage](#usage)
* [Features](#features)
* [Installation](#installation)
* [Usage Examples](#usage-examples)
* [Contributing](#contributing)
* [License](#license)

## introduction

The Simple Shell (hsh) is a minimalistic Unix shell implementation developed in C. It provides a command-line interface for users to interact with their operating system, execute commands, and manage processes. hsh aims to offer a lightweight and efficient shell experience while adhering to standard Unix shell conventions.

## environment
This project was developed and tested on ubuntu 20.04 runing on top of android version 11, and has also been tested on ubuntu 22.04.

## usage
To use the Simple Shell (hsh), open your terminal and navigate to the directory containing the hsh executable. You can run the shell by executing the following command:

* $ ./hsh
Once the shell is running, you can enter commands and interact with your system as you would with any other shell.

## features
* Command Execution: hsh allows you to execute a wide range of system commands and scripts.

* Built-in Commands: The shell supports built-in commands such as cd for changing directories.

* Environmental Variables: You can access and modify environment variables as needed.

* Error Handling: hsh provides informative error messages and returns appropriate exit codes.

## installation
To compile the Simple Shell (hsh), you can use the following command:

 ```$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -o hsh *.c```

Ensure that you have GCC (GNU Compiler Collection) installed on your system.
The -Wall and other flags enable strict error checking to maintain code quality.

## usage examples

* Running a Command:
```
$ ./hsh
($) ls
file1.txt  file2.txt  directory/

```
 * Changing Directory:
```
 $ ./hsh
 ($) cd directory/
```
* Accessing Environment Variables:
```
$ ./hsh
($) echo $HOME
/home/user
```
## contributing
Contributions to the Simple Shell project are welcome! If you'd like to contribute, please follow these guidelines:

* Report bugs or issues by opening a GitHub issue.

* Submit feature requests or improvements through pull requests.

* Ensure your code adheres to the coding style and conventions of the project.

## license
This project is licensed under the MIT License.