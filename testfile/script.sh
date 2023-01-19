#!/bin/bash
if [ $# -ne 1 ]; then
    echo "Error: One argument expected."
    exit 1
fi
filename=$1
if [ ! -f $filename ]; then
    echo "File Not Found"
    exit 1
fi
cd ../antman && make re > /dev/null
./antman ../testfile/$filename > ../testfile/compressed$filename
make fclean > /dev/null
cd ../giantman && make re > /dev/null
./giantman ../testfile/compressed$filename > ../testfile/decompressed$filename
make fclean > /dev/null
cd ../testfile > /dev/null
diff $filename decompressed$filename
sizefile=$(stat -c%s $filename)
sizecompfile=$(stat -c%s compressed$filename)
pourccomp=$(((sizecompfile*100) / sizefile))
echo "The file was compressed and reduced to $pourccomp% of its original size."
