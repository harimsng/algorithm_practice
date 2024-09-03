#!/usr/bin/env bash

EXE=./bignumcal

for OP in "*" "-"
do
  echo "small number '$OP'"

  for i in $(seq 0 10)
  do
    for j in $(seq 0 10)
    do
      ANSWER=$($EXE $i "$OP" $j)
      SOLUTION=$(bc -Le "$i $OP $j")
      if [[ $ANSWER != $SOLUTION ]]; then
        echo "case $i $OP $j: $ANSWER != $SOLUTION"
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
  echo "small number '$OP' success"

  echo "large number '$OP'"

  LARGE_BASE=10000000000000000000000000000000000000000
  LARGE_STEP=500000000000000000000000000000000000000
  LARGE_END=12500000000000000000000000000000000000000
  COUNT=0
  for i in $(seq -f %.0f $LARGE_BASE $LARGE_STEP $LARGE_END)
  do
    for j in $(seq -f %.0f $LARGE_BASE $LARGE_STEP $LARGE_END)
    do
      ANSWER=$($EXE $i "$OP" $j)
      SOLUTION=$(bc -Le "$i $OP $j")
      if [[ $ANSWER != $SOLUTION ]]; then
        echo "case $i $OP $j: $ANSWER != $SOLUTION"
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
  echo "large number '$OP' success"
done
