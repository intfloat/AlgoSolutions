# Read from the file file.txt and output the tenth line to stdout.

# get the number of lines in file.txt, need to use -f8 option on Mac
LINE=`wc -l file.txt | cut -d' ' -f1 `
if [ "$LINE" -gt 9 ]; then
    head -n 10 file.txt | tail -n 1
fi
