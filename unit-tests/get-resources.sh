#!/bin/bash

RESOURCE_FILE_NAME="hume_test_resources.zip"

if [ -z $1 ]
then
	printf "No source specified.\n"
	exit 1
fi

# Download package.
wget --quiet -O $RESOURCE_FILE_NAME $1

if [ $? != "0" ]
then
   printf "Failed to downloads resources.\n"
   exit 1
fi

unzip -q $RESOURCE_FILE_NAME
printf "Resources for unit testing obtained.\n"

exit 0
