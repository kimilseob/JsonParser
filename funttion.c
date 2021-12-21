
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
