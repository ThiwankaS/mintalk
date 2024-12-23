files = file1 file2

some_file : $(files)
	echo "look in to this variable" $(files)
	touch some_file

file1:
	touch file1.txt

file2:
	touch file2.txt

clean:
	rm -rf some_file file1.txt file2.txt
