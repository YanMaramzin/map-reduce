#!/bin/sh
BINARY_HOME=./bin
INPUT_HOME=./input
INPUT=${INPUT_HOME}/AB_NYC_2019.csv

cat ${INPUT} | mapper_mean | sort -k1 | reducer_mean > output
cat output
