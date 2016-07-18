#include <cstdio>

int main() {
	char c;
	bool opening = true;

	while (scanf("%c", &c) != EOF) {
		if (c != '"') printf("%c", c);
		else {
			printf("%s", opening ? "``" : "''");
			opening = !opening;
		}
	}
	return 0;
}