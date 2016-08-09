/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>

FILE * openfile(index) 
{
    //create filename
    char filename[7];
    sprintf(filename,"%03d.jpg", index);
    //create and open JPG file
    FILE* file = fopen(filename, "a");
    return file;
}

int main(int argc, char* argv[])
{
    //declare image file pointer
    FILE* img;
    //open memory card
    FILE* memcard = fopen("card.raw", "r");
    if(memcard == NULL)
    {
        printf("Could not open memory card\n");
        return 2;
    }

    //store 512 bytes at a time in buffer
    unsigned char buffer[512];
    //count how many JPGs have been found
    int count = 0;
    //for checking purposes
    int imgopen = 0;

    //until EOF is reached
    while(fread(&buffer, 512, 1, memcard) == 1)
    {
        //check if first 3 bytes match JPG signature
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] <= 0xef && buffer[3] >= 0xe0))
        {
            //first JPG found
            if(count == 0)
            {
                //get pointer to open JPG file
                img = openfile(count);
                if(img == NULL)
                {
                    printf("could not open %03d.jpg", count);
                    return 3;
                }
                count++;
                //indicate that img file is open
                imgopen = 1;
            }
            
            else
            {
                fclose(img);
                //get pointer to open JPG file
                img = openfile(count);
                if(img == NULL)
                {
                    printf("could not open %03d.jpg", count);
                    return 3;
                }
                count++;
            }
        }
        
        //keep writing buffers to file until next JPG or EOF is found
        if(imgopen == 1)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }

    //close memcard
    fclose(memcard);
    //close img file
    fclose(img);
    //exit the program
    return 0;
}