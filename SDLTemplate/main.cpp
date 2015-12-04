//
//  main.m
//  SDLTest2
//
//  Created by Steve Richey on 12/9/14.
//  Copyright (c) 2014 Float Mobile Learning. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

// Global variables
SDL_Window   *window;
SDL_Renderer *renderer;
SDL_Surface  *bitmap;
SDL_Texture  *texture;

// Method for error handling. Outputs an error message and the SDL Error, quits SDL, destroys everything.
int logerror(const std::string message) {
    // destroy renderer if it exists
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    
    // destroy window if it exists
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    
    // destroy bitmap if it exists
    if (bitmap != nullptr) {
        SDL_FreeSurface(bitmap);
    }
    
    // destroy texture if it exists
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
    
    // log error
    std::cout << message << ": " << SDL_GetError() << std::endl;
    
    // quit SDL
    SDL_Quit();
    
    // return this to flag as failed
    return 1;
}

// Helper function to load a bitmap
SDL_Surface* loadbitmap(const std::string path) {
    std::string fullpath = "Resources/" + path;
    SDL_Surface *bitmap = SDL_LoadBMP(fullpath.c_str());
    return bitmap;
}

// Entry point
int main(int argc, const char * argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return logerror("SDL_Init Error");
    }
    
    // Create a window
    window = SDL_CreateWindow("SDL 2 Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    
    // Verify the window was created
    if (window == nullptr) {
        return logerror("SDL_CreateWindow Error");
    }
    
    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    // Verify the renderer
    if (renderer == nullptr) {
        return logerror("SDL_CreateRenderer Error");
    }
    
    bitmap = loadbitmap("float.bmp");
    
    // Verify the bitmap
    if (bitmap == nullptr) {
        return logerror("SDL_LoadBMP Error");
    }
    
    texture = SDL_CreateTextureFromSurface(renderer, bitmap);
    
    SDL_FreeSurface(bitmap);
    
    if (texture == nullptr) {
        return logerror("SDL_CreateTextureFromSurface Error");
    }
    
    // Clear the renderer
    SDL_RenderClear(renderer);
    
    // Render the texture
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    
    // Present the updated screen
    SDL_RenderPresent(renderer);
    
    // Wait 5 seconds
    SDL_Delay(5000);
    
    // Clean up
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
