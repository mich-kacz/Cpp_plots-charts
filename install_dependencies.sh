apt-get install libsdl2-image-dev 
cd /usr/lib/x86_64-linux-gnu/cmake/ 
rm -r sdl2_image
mkdir sdl2_image 
cd sdl2_image
touch sdl2_image-config.cmake 

echo 'set(prefix "/usr")
set(exec_prefix "${prefix}")
set(libdir "${prefix}/lib/x86_64-linux-gnu")
set(SDL2_IMAGE_PREFIX "/usr")
set(SDL2_IMAGE_EXEC_PREFIX "/usr")
set(SDL2_IMAGE_INCLUDE_DIRS "${prefix}/include/SDL2_image")
set(SDL2_IMAGE_LIBRARIES "-lSDL2_image")'>> sdl2_image-config.cmake 

apt-get install libsdl2-ttf-dev 
cd /usr/lib/x86_64-linux-gnu/cmake/ 
rm -r sdl2_ttf
mkdir sdl2_ttf 
cd sdl2_ttf
touch sdl2_ttf-config.cmake 

echo 'set(prefix "/usr")
set(exec_prefix "${prefix}")
set(libdir "${prefix}/lib/x86_64-linux-gnu")
set(SDL2_TTF_PREFIX "/usr")
set(SDL2_TTF_EXEC_PREFIX "/usr")
set(SDL2_TTF_INCLUDE_DIRS "${prefix}/include/SDL2_ttf")
set(SDL2_TTF_LIBRARIES "-lSDL2_ttf")'>> sdl2_ttf-config.cmake 
