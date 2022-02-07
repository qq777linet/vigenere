#include <cs50.h>
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int shift(char c)
{
    int a = c;
    if (a >= 65 && a <= 90)
    {
        int b = a - 65;
        return b;
    }
    else if (a >= 97 && a <=122)
    {
        int b = a - 97;
        return b;
    } else return 0; 
}

int main(int argc, string argv[])
{
    if (argc == 2) 
    {
            string key = argv[1];
            int key_length = strlen(key);
            for (int i = 0; i < key_length; i++)
            {
                if (isalpha(key[i]))
                {

                }
                else
                {
                    goto LOOP1;
                }
            }
            string plaintext = get_string("plaintext: ");
            int length = strlen(plaintext);
            printf("ciphertext: ");
            for (int i = 0, j = 0; i<strlen(plaintext); i++)
            {
                char cx = plaintext[i];
                if (cx >= 65 && cx <= 90)
                    {
                        int kkey = shift(argv[1][j%3]);
                        j++;
                        int ix = cx + kkey;
                        if (ix>90)
                            {
                                ix = ix - 90 + 64;
                                char ccx = ix;
                                printf("%c",ccx);
                            }
                        else 
                            {
                                char ccx = ix;
                                printf("%c",ccx);  
                            }
                    } 
                else if (cx >= 97 && cx <= 122)
                    {
                        int kkey = shift(argv[1][j%3]);
                        j++;
                        int ix = cx + kkey ;
                        if (ix >122)
                            {
                                ix = ix - 122 + 96;
                                char ccx = ix;
                                printf("%c", ccx);
                            }
                        else 
                            {
                                char ccx = ix;
                                printf("%c", ccx);   
                            }
                    }
                else
                    {
                        printf("%c", cx);
                    }
            }
            printf ("\n");

    }
    
    else
    {
        LOOP1: ;
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}


