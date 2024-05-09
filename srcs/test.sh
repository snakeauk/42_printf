#!/bin/bash

cc -Wall -Wextra -Werror *.c *.h
./a.out $1
