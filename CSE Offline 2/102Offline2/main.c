#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "utils.h"

Image *read_PPM(char *filename)
{
    /* opens a PPM file, constructs an Image object and returns a pointer to it.
    Use fopen(), fscanf(), fprintf(), and fclose().*/

    FILE *fp;
    //open PPM file for reading
    fp = fopen(filename, "rb");
    if (!fp)
    {
        printf("Unable to open file '%s'\n", filename);
        exit(1);
    }

    //read image format
    char format[5];
    if (!fgets(format, sizeof(format), fp))
    {
        printf("File format error\n");
        exit(1);
    }

    //check the image format
    if (format[0] != 'P' || format[1] != '3')
    {
        printf("Invalid image format (must be 'P3')\n");
        exit(1);
    }

    //alloc memory form image
    Image *img;
    img = (Image *)malloc(sizeof(Image));
    if (!img)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }

    //read image size information
    if (fscanf(fp, "%d %d", &img->cols, &img->rows) != 2)
    {
        printf("Invalid image size (error loading '%s')\n", filename);
        exit(1);
    }

    int rgb;
    //read rgb component
    if (fscanf(fp, "%d", &rgb) != 1)
    {
        printf("Invalid rgb component (error loading '%s')\n", filename);
        exit(1);
    }

    //check rgb component depth
    if (rgb != 255)
    {
        printf("'%s' does not have 8-bits components\n", filename);
        exit(1);
    }
    while (fgetc(fp) != '\n');


    //memory allocation for pixel data
    img->image = (Color **) malloc(img->rows * sizeof(Color *));
    int i;
    for(i = 0; i < img->rows; i++)
    {
        img->image[i] = (Color *) malloc(img->cols * sizeof(Color));
    }
    if (!img)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }

    //read pixel data from file
    for(i = 0; i < img->rows; i++)
    {
        int j;
        for(j = 0; j < img->cols; j++)
        {
            if (fscanf(fp, "%d %d %d", &img->image[i][j].R, &img->image[i][j].G, &img->image[i][j].B) != 3)
            {
                printf("Error loading image '%s'\n", filename);
                exit(1);
            }
        }
    }

    fclose(fp);
    return img;
}

void write_PPM(Image *img, char *filename)
{
    /* takes an Image object and writes to filename in PPM format.*/
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp)
    {
        printf("Unable to open file '%s'\n", filename);
        exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P3\n");

    //image size
    fprintf(fp, "%d %d\n",img->cols,img->rows);

    // rgb component depth
    fprintf(fp, "%d\n", 255);

    // pixel data
    int i;
    for(i = 0; i < img->rows; i++)
    {
        int j;
        for(j = 0; j < img->cols; j++)
        {
            fprintf(fp, "%d %d %d ", img->image[i][j].R, img->image[i][j].G, img->image[i][j].B);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void free_image(Image *img)
{
    /* takes an Image object and frees all the memory associated with it.
    This involves not only calling free on image but also on the appropriate
    members of it.
    */
    free(img);
    free(img->image);
}


Color *evaluate_one_pixel(Image *img, int row, int col)
{
    /* Takes an Image object and returns what color the pixel at the given row/col
    should be in the secret image. This function should not change image*/
    Color *clr;
    if(img->image[row][col].B % 2 == 0)
    {
        clr->R = 0;
        clr->G = 0;
        clr->B = 0;
    }
    else
    {
        clr->R = 255;
        clr->G = 255;
        clr->B = 255;
    }
    return clr;
}

Image *get_secret_image(Image *img)
{
    /* takes an Image object, and constructs the secret image from it by extracting
    the LSB of the B channel. You should call evaluate_one_pixel() here. */
    int i;
    if(img)
    {
        for(i=0; i<img->rows; i++)
        {
            int j;
            for(j = 0; j<img->cols; j++)
            {
                Color clr = *evaluate_one_pixel(img, i, j);
                img->image[i][j] = clr;
            }
        }
    }
}

int main()
{
    /* Call read_PPM(), write_PPM(), free_image(), get_secret_image() in some order
    to obtain the hidden message.*/
    Image *tempImage;
    tempImage = read_PPM("DennisRitchie.ppm");
    get_secret_image(tempImage);
    write_PPM(tempImage, "DennisRitchie2.ppm");
    free_image(tempImage);
    printf("Press 'Enter' to finish process...");
    getchar();
    return 0;
}

