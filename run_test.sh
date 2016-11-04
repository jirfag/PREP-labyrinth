#!/bin/bash -x
printenv
mkdir -p build || exit 1
cd build
cmake .. -DCMAKE_CXX_COMPILER=${COMPILER:-g++} || exit 1
make VERBOSE=1 V=99 || exit 1
rm -f lab.txt
wget http://52.59.17.78:81/lab_data/lab.txt || exit 1
./labyrinth lab.txt >log.txt || exit 2
Total steps: 293, time: 124 mcs
STAT=$(cat log.txt | perl -lne '/steps: (\d+), time: (\d+) mcs/ && print "elapsed_mcs=$2&steps=$1"')
curl -XPOST http://52.59.17.78:81/maze_results -d "user=${TRAVIS_REPO_SLUG}&${STAT}"
