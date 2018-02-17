#!/bin/sh
# phone

echo -n "Enter the name to search: "
read aname
grep -i $aname phone_book.txt

