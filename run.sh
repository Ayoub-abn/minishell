#!/bin/bash

make && clear && valgrind --leak-check=full --show-leak-kinds=all ./minishell
# valgrind 
