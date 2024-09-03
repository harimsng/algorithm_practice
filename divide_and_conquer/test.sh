#!/usr/bin/env bash

EXE=./subtraction

echo "small number subtraction"

for i in $(seq 0 25)
do
  for j in $(seq 0 25)
  do
    ANSWER=$($EXE $i $j)
    SOLUTION=$(bc -e "$i - $j")
    if [[ $ANSWER != $SOLUTION ]]; then
      echo "case $i - $j: $ANSWER != $SOLUTION"
      exit 1
    fi
  done
  echo -n "."
  TEMP=$(($i % 10 == 0))
  if [[ $TEMP == "1" ]]; then
    printf "\r          \r"
  fi
done

printf "\r          \r"
echo "small number subtraction success"

echo "large number subtraction"

LARGE_BASE=10000000000000000000000000000000000000000
LARGE_STEP=50000000000000000000000000000000000000
LARGE_END=12500000000000000000000000000000000000000
COUNT=0
for i in $(seq -f %.0f $LARGE_BASE $LARGE_STEP $LARGE_END)
do
  for j in $(seq -f %.0f $LARGE_BASE $LARGE_STEP $LARGE_END)
  do
    ANSWER=$($EXE $i $j)
    SOLUTION=$(bc -e "$i - $j")
    if [[ $ANSWER != $SOLUTION ]]; then
      echo "case $i - $j: $ANSWER != $SOLUTION"
      exit 1
    fi
  done
  echo -n "."
  TEMP=$(($COUNT % 10 == 0))
  if [[ $TEMP == "1" ]]; then
    printf "\r          \r"
  fi
  COUNT=$(($COUNT + 1))
done

printf "\r          \r"
echo "large number subtraction success"
