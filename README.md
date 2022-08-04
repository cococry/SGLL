# SGLL - Simple GL Library
<image src="git-assets/sgll_logo.png" alt="logo" width=460px></image>

## Overview
SGLL is a simple abstraction over boilerplate code that is used by any general [OpenGL](https://de.wikipedia.org/wiki/OpenGL) program. The API contains 
classes for IO- and display management (Keyboard, Mouse) and a OpenGL Texture- And Shader class. A few utility features are also in the API. This Library is desinged
to start your OpenGL project easily without needing to worry about any boilterplate that could take pretty long to implement and lowers motivation. The API does not
contain high level features of some sort. The main focus is IO and Windowing. The Library is developed in C++ using the Visual Studio 2022 IDE. The Build at the time
is only setup for Visual Studio building. The plan is to port the library to clang and gcc.

***

## 🛬 Building

*VISUAL STUDIO REQUIRED* First, Link your project to the [SGLL.lib file](https://github.com/cococry/SGLL/blob/main/lib/SGLL.lib). This will give you core access to
the library. Now, setup include paths to include from SGLL. Set a additional include directory for the [libraries include directory](https://github.com/cococry/SGLL/tree/main/SGLL/include/sgll). Finally, include all the c++ files in the [libraries source folder](https://github.com/cococry/SGLL/tree/main/SGLL/src) to the build of your project.

That's it! 

## 💥Features

- Keyboard IO  
- Mouse IO 
- Windowing Class 
- Defined Mouse Codes
- Defined Key Codes
- OpenGL Shader Class
- OpenGL Texture Class
- File Utility Methods
- Logging at different Log Levels

## Notes

The majority of the Display class implementation was made by use of the [GLFW](https://github.com/GLFW/GLFW) library for windowing. Same for IO, GLFW was used for the
low level implementation. For accessing OpenGL Functions, the library [glad](https://github.com/Dav1dde/glad) was used. The logging class is a abstraction of the [spdlog](https://github.com/gabime/spdlog) library. And lastly, [stb_image](https://github.com/nothings/stb) is used for loading textures.

***

## 🧾 Brief documentation

- **Display Class**

The Display class is a abstraction over the GLFWWindow struct. It contatins API to intialize, deintialize and handle the GLFW Window. It also contains API to change the way the window behaves at runtime and functionally to get and set variables that make up the Window.

```C
 SGLL::Display display = SGLL::Display(1920, 1080, "My SGLL Window");
 
 display.setVsync(true);
 
 SGLL_INFO("Window is {0}x{1} pixels big", display.getWidth(), display.getHeight());
 
 while(!display.closeRequested)
{
  display.pollEvents();
  display.swapBuffers();
}

```

- **Keyboard Input**

The API of Keyboard Input in SGLL conains querying states of keys. Examples are testing if a key was pressed in the last frame, if a key is currently pressed or if a key was released. The is done by binding a callback function to GLFWs key callback that handles the key states.

```C
if(SGLL::Keyboard::isKeyPressed(SGLL::Key::W)
{
  SGLL_ERROR("Key W is currently pressed");
}
else if(SGLL::Keyboard::wentKeyDown(SGLL::Key::A)
{
  SGLL_WARN("A Key went down!");
}
else if(SGLL::Keyboard::isKeyReleased(SGLL::Key::S)
{
  SGLL_TRACE("The S key has been released");
}
else if(SGLL::Keyboard::keyChanged(SGLL::Key::D)
{
  SGLL_CRITICAL("The state of the D key was changed);
}
```

- **Mouse Input**

The API of for Mouse Input in SGLL contains a lot of methods for checking all kinds of states and variables of the mouse. Containing checking the position of the mouse, checking button states, querying the mouse wheel and even more. The is made by binding callback functions to GLFW. Those a contain Button state callback, a Mouse wheel callback and a cursor position callback.

```C
if(SGLL::Mouse::isButtonPressed(SGLL::MouseCode::ButtonLeft)
{
  SGLL_INFO("The left mouse button is being pressed!");
}
else if(SGLL::Mouse::isButtonReleased(SGLL::MouseCode::ButtonLeft)
{
  SGLL_ERROR("The left mouse button was released.");
}

SGLL_INFO("Mouse position is: {0}x{1}", SGLL::Mouse::getXPos(), SGLL::Mouse::getYPos());
```

- **Logging**

The Logging API contains macros for logging at different log levels. Those Levels are: Debug, Trace, Info, Warn, Error and Critical. The logging is done
with [spdlog](https://github.com/gabime/spdlog).

```C
SGLL_DEBUG("Hello debug. 12 + 5 = {0}", 17);
SGLL_TRACE("Hello trace. Mouse Position: {0}x{1}", SGLL::Mouse::getXPos(), SGLL::Mouse::getYPos());
SGLL_INFO("Hello info");
SGLL_WARN("Hello warn");
SGLL_ERROR("Hello error");
SGLL_CRITICAL("Hello critical");
```

- **Textures**

SGLL Also contains API to load textures into OpenGL memory. This is contained by the texture class. The actual parsing and file loading is done with [stb_image](https://github.com/nothings/stb).


```C
SGLL::Texture texture = SGLL::Texture("assets/textures/grass.png");

texture.bind();
texture.activate();

SGLL_INFO("Texture size: {0}x{1}", texture.getWidth(), texture.getHeight());
```

- **Shaders**

The Shader API is an abstraction over the OpenGL Shader program. It contains loading shader files from vertex, fragment and optionally geometry shaders and compiling
them. The API also contains methods to upload uniforms to the shader of 10 different variable types.


```C
SGLL::Shader shader = SGLL::Shader("assets/shaders/vertex_shader.glsl", "assets/shaders/fragment_shader.glsl", "assets/shaders/geometry_shader.glsl");

shader.bind();
shader.setMatrix4f("u_ViewProjectionMatrix", viewProjectionMatrix);
shader.setVector3f("uViewPos", camera.position);
shader.unbind();
```

- **Loading File Contents**

SGLL also has functionallity for loading up text files and storing its contents in strings.


```C

std::string fileContent = SGLL::FileUtil::getFileContents("assets/files/diary.txt");

SGLL_INFO("My diary: {0}", fileContent);
```

***
