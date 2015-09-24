#!/bin/bash

# Check that resources are in place for unit testing.

printf "Checking for resources...\n"

result=0

if [ -z "$(ls | grep '.ttf')" ]
then
	printf "* No usable font found.\n"
	result=1
fi

if [ -z "$(ls | grep '.wav')" ]
then
	printf "* No usable WAV fount.\n"
	result=1
fi

if [ result != 1 ]
then
	printf "Unit testing is ready to be run.\n"
fi

exit $result
