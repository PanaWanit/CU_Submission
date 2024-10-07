#!/bin/bash
# chmod +x run.sh
g++ -Wall -O2 -std=c++17 "$1" -o "${1%.*}" && ./"${1%.*}"
