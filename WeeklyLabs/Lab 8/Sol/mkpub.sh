#!/bin/sh

if test -d $1
then
   chmod 755 $1
   echo "Directory '$1' is now made public."
   #ls -l $1
elif test -f $1
then
   chmod 644 $1
   echo "File '$1' is now made public."
   #ls -l $1
else
   echo "File '$1' does not exist."
fi 




