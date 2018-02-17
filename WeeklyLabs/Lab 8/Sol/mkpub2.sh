#!/bin/sh
# mkpub

for i in $*
do
if test -d $i
then
   chmod 755 $i
   echo "Directory '$i' is now made public."
elif test -f $i
then
   chmod 644 $i
   echo "File '$i' is now made public."
else
   echo "File '$i' does not exist."
fi
done

