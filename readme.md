# [sdl-xcode-template](https://github.com/gowithfloat/sdl-xcode-template)

While investigating [SDL 2.0](http://libsdl.org/) for an upcoming project, we found that there was not a good starting point for an SDL project in Xcode.

This repository is meant to serve as an example of a **Hello World** project in SDL using Xcode. You should be able to clone this repository and get going right away, provided that you have the SDL2 framework installed (see below).

The code in `main.cpp` is largely based on [this SDL tutorial](http://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-1-hello-world/) and covers creating a window, a renderer, and displaying a bitmap.

# Installing SDL 2 on OS X

As of the time of this writing, the SDL 2 framework available for download from the official site will not work due to a [code signing error](https://bugzilla.libsdl.org/show_bug.cgi?id=2058). Until then, you can build the framework yourself in Xcode. It only takes a few steps (which we got thanks to [this](http://stackoverflow.com/a/22373199) StackOverflow answer).

1. Install [mercurial](http://mercurial.selenic.com/) if you don't have it already.
2. From the terminal, run `hg clone http://hg.libsdl.org/SDL` to clone the SDL source.
3. Open `XCode/SDL/SDL.xcodeproj` in Xcode.
4. Compile the framework.
5. In the left-hand navigation pane, open `Products`, right-click `SDL2.framework`, and select `Show in finder`.
6. Copy this file (`SDL2.framework`) to `/Library/Frameworks`.

After all that, you should be able to compile this project with no problem. If it succeeded, you should see a `Hello world` image in a 640x480 window for about 5 seconds.

# License

&copy; 2014 [Float](http://gowithfloat.com/). Shared under an [MIT license](https://en.wikipedia.org/wiki/MIT_License). See [license.md](./license.md) for details.
