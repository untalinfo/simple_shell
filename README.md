# simple_shell - Holberton School

<img src="https://i.ibb.co/M8S4nYh/shell.png" alt="shell" border="0">

Holberton School Shell (hsh), is a simple program of the line commands. This simple shell recreates basic and some more complex functionalities to result in our own Shell. This shell si developed in the programming language c.

# Table of Contents
1. [Requeriments](#requeriments-)
2. [How to use](#how-to-use-it-)
3. [Test](#test-%EF%B8%8F)
4. [Development environment](#development-environment-%EF%B8%8F)
5. [Authors](#authors%EF%B8%8F)

## Requeriments 📋

Simple Shell was built and tested in Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC.

## How to use it 🔧
Do you need clone this repository:
```
	git clone https://github.com/untalinfo/simple_shell
```
and then you can compile with this command:
```
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
after compilation you can excecute with this command:
```
	./hsh
```
## Test ⚙️
Some examples of how to used this simple shell:
```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$
$ pwd
/home/vagrant/simple_shell
$|
```
```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$ ls
AUTHORS   _fork.c   holberton.h   man_1_simple_shell   node.c   selector.c     test_ls
README.md   hack    hsh           messages.c           promp.c  strfuncions.c
$|
```
This shell version can also be tested in non-interactive mode:
```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo "/bin/ls" | ./hsh
AUTHORS   _fork.c   holberton.h   man_1_simple_shell   node.c   selector.c     test_ls
README.md   hack    hsh           messages.c           promp.c  strfuncions.c
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ |
```
```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ cat test_ls
/bin/ls
/bin/ls
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ cat test_ls | ./hsh
/bin/ls
/bin/ls
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ |
```
## Development environment 🛠️
This project has been tested on Ubuntu 14.06.6 LTS

* The tests are carried out in [virtualBox](https://www.virtualbox.com)
* Development environment manager [vagrant](https://www.vagrantup.com)

## Authors✒️
* Dairo Facundo Durarte - student at Holberton School
* Oscar Eduardo Info - student at Holberton School

You can also look at the list of all [contributors](https://github.com/untalinfo/simple_shell/graphs/contributors) who have participated in this project.
