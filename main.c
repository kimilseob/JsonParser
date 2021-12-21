#include "function.h"

int main()
{
	int size; // 문서 크기
	char *doc = readfile("example.json", &size);
	if(doc == NULL)
		return -1;

	JSON json = { 0, };

	parseJSON(doc, size, &json);

	printf("Title: %s\n", json.tokens[0].string);
	printf("Genre: %s\n", json.tokens[1].string);
	printf("Genre: %s\n", json.tokens[2].string);
	printf("Title: %s\n", json.tokens[3].string);
	printf("Director: %s\n", json.tokens[4].string);
	printf("Title: %s\n", json.tokens[5].string);

	freeJSON(&json);

	free(doc);
	return 0;

}
