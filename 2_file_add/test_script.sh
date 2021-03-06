FILENAME=$1

if [ -z "$FILENAME" ]; then
       echo "You must specify filename"
       exit 1
fi

# Create a ro file and try to launch program with it
touch written_file.txt
chmod a=r written_file.txt
errormessage=$( ./$FILENAME written_file.txt 2>&1)
RETVAL=$?
	case $RETVAL in
		0)
			echo "program has failed the test, opened ro file"
		;;
		13)
			:
		;;
		*)
			echo "program has failed the test: $errormessage"
		;;
	esac
# Create a new file and write strings in it
touch original_file.txt
chmod a=rw original_file.txt
echo abc > original_file.txt
echo 123 >> original_file.txt
echo fgh >> original_file.txt
# Change access mode of a test file to rw  
chmod a=rw written_file.txt
# To make sure that strings are added, not overwritten:
echo abc > written_file.txt
errormessage=$( ./$FILENAME written_file.txt <<-EOF 2>&1 > /dev/null
123
fgh
EOF
)
RETVAL=$?
	if [ $RETVAL -ne 0 ]; then
		echo "program has failed the test: $errormessage"
	fi
# Compare original file to written 
diff original_file.txt written_file.txt
	if [ $? -ne 0 ]; then 
		echo "program has failed the test"
	else 
		echo "program has passed the test"
	fi

rm written_file.txt
rm original_file.txt
