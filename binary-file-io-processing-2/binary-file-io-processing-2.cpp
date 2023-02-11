#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

//defining variables
#define HEIGHT 500
#define WIDTH 750
#define MARGIN 15
#define ALPHA 0.3int
FILE* file_id1, * file_id2;
unsigned char  data[HEIGHT][WIDTH], outdata[HEIGHT][WIDTH];
int i, j;

int main()
{
    //opening input file
    file_id1 = fopen("D:\\unesco750-1.raw", "rb");
    if (file_id1 == NULL)
    {
        printf("Error: Could not open input file\n");
        return 0;
    }

    //reading input file
    fread(data, sizeof(unsigned char), HEIGHT * WIDTH, file_id1);
    fclose(file_id1);

    //processing file
    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < WIDTH; j++)
            if (i < MARGIN || i >= HEIGHT - MARGIN || j < MARGIN || j >= WIDTH - MARGIN)
                outdata[i][j] = (unsigned char)(0.3 * data[i][j] + (1 - 0.3) * 128);
            else
                outdata[i][j] = data[i][j];

    //creating and opening output file
    file_id2 = fopen("D:\\output.raw", "wb");
    if (file_id2 == NULL)
    {
        printf("Error: Could not open output file\n");
        return 0;
    }

    //writing data to output file
    fwrite(outdata, sizeof(unsigned char), HEIGHT * WIDTH, file_id2);
    fclose(file_id2);

    printf("Success: File processed\n");
    return 1;
}