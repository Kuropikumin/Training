#include <stdio.h>

typedef struct human {
	char* name;
	char  sex;
	int   age;
} human;

void returnHome(human miyoshi);

int main(int argc, char** args) {
	human h1;
	h1.name = "miyoshi";
	h1.sex  = 'm';
	h1.age  = 28;
	returnHome(h1);

	printf("argc : %d\n", argc);
	printf("args[0] : %s\n", *args);
	printf("args[1] : %s\n", *(args+1));
	printf("args size : %d\n", sizeof(args));
	printf("args[0] size : %d\n", sizeof(*args));

	return 0;

}

void returnHome(human miyoshi) {
	printf("%s : %c, %d\n", miyoshi.name, miyoshi.sex, miyoshi.age);
}
