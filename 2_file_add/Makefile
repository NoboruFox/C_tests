TARGET_FGETS = file_add_fgets
TARGET_FGETC = file_add_fgetc

SRC_FGETS = ${TARGET_FGETS}.c 
SRC_FGETC = ${TARGET_FGETC}.c

all: ${TARGET_FGETS} ${TARGET_FGETC} 

${TARGET_FGETS}: ${SRC_FGETS}
	gcc $^ -o $@ 

${TARGET_FGETC}: ${SRC_FGETC}
	gcc $^ -o $@ 

tests: test_fgets test_fgetc

test_fgetc: ${TARGET_FGETC}
	./test_script.sh $^

test_fgets: ${TARGET_FGETS}
	./test_script.sh $^

clean:
	rm -rf ${TARGET_FGETS} ${TARGET_FGETC}
