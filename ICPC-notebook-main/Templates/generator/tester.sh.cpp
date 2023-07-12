#!/bin/bash
echo "" > main.txt
echo "" > naive.txt
g++ -std=c++17 -o main main.cpp
g++ -std=c++17 -o naive naive.cpp
g++ -std=c++17 -o gen gen.cpp
((i = 1))
while diff main.txt naive.txt -Bb
do
  echo $i
  ((i++))
  ./gen > test.txt
  ./main < test.txt > main.txt
  ./naive < test.txt > naive.txt
done
