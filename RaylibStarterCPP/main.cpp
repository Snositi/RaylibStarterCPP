/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

unsigned int ElfHash(unsigned char* data)
{
    unsigned int hash = 0;
    unsigned int x = 0;
    
    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        hash = (hash << 4) + *i;
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    return (hash & 0x7FFFFFFF);
}

unsigned int myHash(unsigned char* info)
{
    //create a value to return
    unsigned int hash = 0;
    //create a counter for the for loop
    int x = 0;
    //for each character in info that is not '\0'
    for (unsigned char* i = info; *i != '\0'; ++i)
    {
        //set the value to return to the value to return times 0602 plus the value of the info at this iteration
        hash = (hash * 0602) + info[x];
        //iterate the counter so this for loop loops to the next value in the info char arr
        x++;
    }
    //once all characters have been applied to the info, return the value initialized at the start
    return hash;
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    int checkSum = 0;
    unsigned char* input = new unsigned char[0];

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        std::cin >> input;
        checkSum = myHash(input);
        //----------------------------------------------------------------------------------        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(checkSum));

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}