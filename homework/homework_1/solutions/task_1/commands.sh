wc -l ../../task_1/data.dat #Number of lines in "data.dat"
grep -E "dolor|dalor" ../../task_1/data.dat | wc -l # NUmber of lines that contain dolor/dalor
wc -w ../../task_1/data.dat #Number of words in "data.dat"
grep -o '\bmol[[:alpha:]]*' ../../task_1/data.dat | wc -l #Number of words starts with "mol" in "data.dat"