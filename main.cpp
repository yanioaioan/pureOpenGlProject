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

// An array of 3 vectors which represents 3 vertices
static const GLfloat g_vertex_buffer_data[] = {
   -0.3f, -0.3f, 0.0f,
   0.3f, -0.3f, 0.0f,
   0.0f,  0.3f, 0.0f,
};

int main(int argc, char *argv[])
{


    //creation of the rendering window
    SDL_Window* window = NULL;
    //creation of OpenGL context
    SDL_GLContext openglContext;
    //SDL init
    SDL_Init( SDL_INIT_VIDEO );
    //Use OpenGL 3.3
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );

    //create opengl window
    window = SDL_CreateWindow( "test opengl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );


    //create a valid opengl context
    openglContext = SDL_GL_CreateContext( window );

    //First you need to create a valid OpenGL rendering context and call glewInit() to initialize the extension entry points.
    //initialize glew after SDL_CreateWindow & SDL_GL_CreateContext otherwise it crashes
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      /* Problem: glewInit failed, something is seriously wrong. */
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));


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



    return 0;
}
