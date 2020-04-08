# simple_shell - Holberton School

<img src="https://i.ibb.co/M8S4nYh/shell.png" alt="shell" border="0">

Holberton School Shell (hsh), is a simple program of the line commands. This simple shell recreates basic and some more complex functionalities to result in our own Shell. This shell si developed in the programming language c.

### Requeriments 📋

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
AUTHORS   _fork.c   holberton.h   man_1_simple_shell   node.c   selector.c
README.md   hack    hsh           messages.c           promp.c  strfuncions.c
$|
```
## Development environment 🛠️
This project has been tested on Ubuntu 14.06.6 LTS

* The tests are carried out in [virtualBox](https://www.virtualbox.com) 
* Development environment manager [vagrant](https://www.vagrantup.com)

## Authors✒️
* Dairo Facundo Durarte - student at Holberton School
* Oscar Eduardo Info - student at Holberton School

You can also look at the list of all [contributors](https://github.com/untalinfo/simple_shell/graphs/contributors) who have participated in this project.
