#!/bin/bash

# Check that resources are in place for unit testing.

printf "Checking for resources...\n"

result=0

if [ -z "$(ls | grep '.ttf')" ]
then
	printf "* No usable font found.\n"
	result=1
fi

exit $result
