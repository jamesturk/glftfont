// This file is distributed along with GLFT_Font and is in the public domain.
// Compiled with g++ GLFT_Font.cpp test.cpp -o test -Wall -pedantic 
//                     -lglfw -lGL -lfreetype
//
// $Id: test.cpp,v 1.1.1.1 2005/07/18 22:19:16 cozman Exp $

#include <GL/glfw.h>
#include "GLFT_Font.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cerr << "Usage: test file.  Where file is a valid font\n";
    }
    else
    {
        glfwInit();
        glfwOpenWindow(800, 600, 8, 8, 8, 8, 0, 0, GLFW_WINDOW);
        
        GLFT_Font f;
        f.open(argv[1],24);
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 800, 600, 0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glDisable(GL_LIGHTING);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        
        do
        {
            glClear(GL_COLOR_BUFFER_BIT);
    
            f.drawText(0, 0, "drawText");
            f.drawText(f.calcStringWidth("drawText"), f.getHeight(), 
                        "drawText 0x%X", 250);
            f.beginDraw(200, 200) << "beginDraw: " << 10 << f.endDraw();
   
            glfwSwapBuffers();
            
        } while(glfwGetWindowParam(GLFW_OPENED) && 
                glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS);
    
        glfwCloseWindow();
        glfwTerminate();
    }
}

