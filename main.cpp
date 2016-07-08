#include <GL/glew.h>
#include "GL/gl.h"
#include <GL/glu.h>

//pure opengl / with optional SDL lib use for windowing/context management

//Lines 25-59 are optional (this means you can use gl..Functions without these lines as long as you include.
//However, in most apps you need to have a windowing system management in place
// and that's when SDL,QT,GLFW etc libs come into place)


#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


#include <iostream>

int main(int argc, char *argv[])
{
    if(glewInit())
    {
        std::cout<<"glew init"<<std::endl;
    }

    //creation of the rendering window
    SDL_Window* window = NULL;
    //creation of OpenGL context
    SDL_GLContext openglContext;
    //SDL init
    SDL_Init( SDL_INIT_VIDEO );
    //Use OpenGL 3.3
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );

    //create opengl window
    window = SDL_CreateWindow( "test opengl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    //create a valid opengl context
    openglContext = SDL_GL_CreateContext( window );

    SDL_Event e;
    bool exit=false;
    while(!exit)
    {
        while(SDL_PollEvent( &e ) != 0  )
        {
           if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE )
           {
               exit = true;
           }

            //Clear color buffer
            glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glClearColor( .4f, .4f, .1f, 1 );

            //swap the the sdl window update our screen
            SDL_GL_SwapWindow( window );
        }
    }


    GLuint *unitilializedBuffer;//gl integer
    glGenBuffers(1, unitilializedBuffer);
    glDeleteBuffers(1,unitilializedBuffer);

    return 0;
}
