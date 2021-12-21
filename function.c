
char *readfile(char *filename , int *readsize)
{
	File *fp = fopen(filename , "rb");
	if (fp == NULL)
	   return NULL;

	int size;
	char *buffer;
	
	// get file size
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	//  Allocate memory as much as file size + NULL space and initialize to 0
	buffer = malloc(size + 1);
	memset(buffer , 0 , size+1);
	
	// read file
	
	if (fread(buffer, size, 1, fp) <1 )
	{
		*readsize =0;
		free(buffer);
		fclose(fp);
		return NULL;

	}
	
	*readsize = size;
	fclose(fp);
	return buffer;
}

void parseJSON(char *doc, int size, JSON *json)
{
	int tokenIndex = 0;
	int pos = 0;
	
	if (doc[pos] ! '{')
		return;

	pos++;

	while (pos < size)
	{
		switch (doc[pos])
		{
		case '"' :
		{
			//문자열의 시작위치를 구함 . 맨앞의 " 를 제거하기 위해 +1 
			char *begin = doc + pos + 1;

			//문자열의 끝 위치를 구함. 다음 "의 위치
			char *end = strchr(begin, '"');
			if (end == NULL)
				break;
			
			int stringLength = end - begin; // 문자열의 실제 길이는 끝 위치 - 시작위치

			// 토큰 배열에 문자열저장
			// 토큰 종류는 문자열
			json->tokens[tokenIndex].type = TOKEN_STRING;
			// 문자열 길이 + NULL 공간만큼 메모리 할당
			json->tokens[tokenIndex].string = malloc(stringLength + 1);
			// 할당한 메모리를 0으로 초기화
			memset(json->tokens[tokenIndex].string , 0 , stringLength + 1);

			// 문서에서 문자열을 토큰에저장
			// 문자열 시작위치에서 문자열 길이만큼만 복사
			memcpy(json->tokens[tokenIndex].string , begin , stringLength);

			tokenIndex++;

			pos = pos + stringLength + 1;

		}

		break;
		}

		pos++; // 다음 문자로
	}

}
