# Plons Library
Plons Library is a collection of frameworks for Anstro Pleuton's programs. This library contains several "engine"-like code for creating a graphical app or a game.

# Sections
This library is subdivided into sections:
- **Grapons** A GUI Library.
- **Playons** A Game Engine Library.

# Prerequisite
- Know to program in C++
- Know to program in C++23 (optional, recommended)
- Know to use third party C++ libraries
- Know to use CMake
- Know to use PhysX
- Know to use BGFX
- Know to use GLFW
- Know to use GLM
- Ability to withstand immense torture (yes, this is a requirement)

# Building - Linux
You do NOT want to understand how to build physx for this library (if you do, idk). Just run the following commands.
**NOTE: none of this is tested in ARM Linux**

 1. Setup:
    Clone this repository.
    ```bash
    git clone https://github.com/anstropleuton/plons_library
    cd plons_library
    ```
 2. Initialize dependencies:
    ```bash
    git submodule update --init --recursive # Hope your bandwidth does not suck!
    ```
 3. Build PhysX:
    This is where the torture truly begins, we need sub steps for this one.
     1. CD:
        ```bash
        cd deps/PhysX/physx
        ```
     2. Edit `source/compiler/cmake/linux/CMakeLists.txt` to replace `-Wall -Wextra -Werror -Wstrict-aliasing=2 -Weverything` and stuff (find '-Wall' throughout the file) with `-w`. If you do need warnings for whatever reason (there are about 0.3 million lines of warnings), you have to at least remove `-Werror` so they don't get converted to errors (and there are a lot of them because they don't know how to write clean cross-platform code).
     3. (Note: do this only if `whereis libcrypt.so.1` fails to find it) Symlink new `libcrypt.so.2` to `libcrypt.so.1` because PhysX uses it's own inferior package manager called `packman` which does half things right and so on. It downloads Python 3.10 from it's server instead of being a good person and using whatever the system has. This version of Python was built with old `glibc` which had `libcrypt.so.1` and so does not work with newer `libcrypt.so.2`.
        ```bash
        sudo ln -s /usr/lib/libcrypt.so.2 /usr/lib/libcrypt.so.1
        ```
     4. Finally, run the script:
        ```bash
        ./generate_projects.sh # Hope you have even more bandwidth!
        ```
     5. Build `debug` and/or `release`:
        ```bash
        cd compiler/linux-debug
        make -j4 # Change the number of threads if you like
        cd ../linux-release
        make -j4
        cd ../../../../.. # Back to the root directory
        ```
    And **we are done**. Now you can join Linus Torvalds club and yell FUCK YOU NVIDIA. [Where the torture?](#where-torture)
 4. Build the library:
    ```bash
    mkdir build && cd build
    cmake .. # This will also build the rest of the nice dependencies, or use system provided ones
    ```
 5. Set up path to this library:
    Maybe you can just do `add_library` to this project? Idk I am not very experienced in CMake yet.
 6. Include the library to include all functionality:
    ```cpp
    #include "plons_library.hpp"
    ```
 7. Go through [documentation](https://anstropleuton.github.io/plons_library) (or [header files](include/plons_library.hpp)) to get a grasp on what you can do using my library. You can check out [examples source files](examples/) for more usage information.

# Building - Windows
A lot less hassle considering they do stuff in windows.

 1. Install Visual Studio (They force you to).
    You can install Visual Studio 2022/2019 with "Desktop Development with C++" workload (if you want minimal setup, make sure to at least include MSVC, Windows SDK and CMake Tools) or you can install only the Build Tools of Visual Studio 2022/2019 which does not include the IDE (less bloat), with "Desktop Development with C++" workload (again, if you want minimal setup, make sure to at least include MSVC, Windows SDK and CMake Tools).
 2. Open "Developer Command Prompt for VS 2022" (or 2019) from start menu.
 3. CD to your preferred projects folder.
 4. Setup:
    Clone this repository.
    ```cmd
    git clone https://github.com/anstropleuton/plons_library
    cd plons_library
    ```
 5. Initialize dependencies:
    ```cmd
    REM Hope your bandwidth does not suck!
    git submodule update --init --recursive
    ```
 6. Build PhysX:
    This still requires sub steps so here we go.
     1. CD:
        ```cmd
        REM Make sure to use correct path, relative to where you cloned the repository
        cd deps\PhysX\physx
        ```
     2. Run the script:
        ```cmd
        REM Hope you have even more bandwidth!
        .\generate_projects.bat
        ```
     3. Build `debug` and/or `release`:
        ```cmd
        REM Replace this with vc16win64 if you are using Visual Studio 2019
        cd compiler/vc17win64
        msbuild PhysXSDK.sln /p:Configuration=Debug
        msbuild PhysXSDK.sln /p:Configuration=Release
        REM Back to the root directory
        cd ..\..\..\..\..
        ```
 7. Build the library:
    ```cmd
    mkdir build && cd build
    REM NOTE: Make sure to pass -DPLONS_LIBRARY_PLATFORM=vc16win64 if you are using Visual Studio 2019
    cmake ..
    ```
 8. Set up path to this library:
    Maybe you can just do `add_library` to this project? Idk I am not very experienced in CMake yet.
 9. Include the library to include all functionality:
    ```cpp
    #include "plons_library.hpp"
    ```
 7. Go through [documentation](https://anstropleuton.github.io/plons_library) (or [header files](include/plons_library.hpp)) to get a grasp on what you can do using my library. You can check out [examples source files](examples/) for more usage information.

# Documentations
Refer to the [documentation](https://anstropleuton.github.io/plons_library) (or [header files](include/plons_library.hpp)) to get a grasp on what you can do using my library.

# Changelog
Refer to the [Changelog](Changelog.md) for info about changes in each version.

# Contributing
Check out [Guidelines](Guidelines.md) before you submit your code! Make sure to create a branch with one task with the name of the category of your task (i.e., "features/", "bugfix/", etc.) your task before you change the code.

# Credits
Thanks to [jothepro](https://github.com/jothepro) for the stylesheet [Doxygen Awesome](https://github.com/jothepro/doxygen-awesome-css) for Doxygen.
Thanks to Nuno Pinheiro (can't find link) for the background [Elarun](background.png). But I did find a [KDE store link](https://store.kde.org/p/1162360/) to the background image. I think you could consider that. If KDE developers are here, I would appreciate your help to find a proper link to the author.
Thanks to NVIDIA and contributors for immense amount of pain but also for open sourcing PhysX!
Thanks to Бранимир Караџић and contributors for BGFX!
Thanks to Marcus Geelnard, Camilla Löwy and contributors for GLFW!
Thanks to G-Truc Creation and contributors for GLM!

# License
This project is licensed under the terms of MIT License, see [License](License.md).
**NOTE: Dependencies licensing terms varies, the MIT License mentioned for this project applies to everything in this project excluding everything in the `deps/` folder. Check out those folder for licensing terms, too.**

# Junk folder?
That folder is where I put my useless features. Don't use them please.

# Where Torture
What? You read torture in prerequisite and this all feels simple? Well, yes for you but, this is all that the *end user* needs to do. I had to go through a lot more. PhysX's build system is literally just a whole bunch of shell/batch scripts and a few python scripts (yes, they are mix-n-match-ed and they go back and forth from shell/batch to python which makes following what they are doing just impossible) and all that does is download unwanted and bloated large file dependencies (they could have just mentioned dependencies and said us to install it but no, they ought to be smelly) and temporarily sets up environment variables for those installed dependencies. And yes, as mentioned earlier, it downloads Python 3.10 instead of using whatever is available in the system, which doesn't even work because of the missing `libcrypt.so.1` in newer systems. But what's the actual problem? Not only are they not using a real package manager like `vcpkg` (which, btw they force you to use Visual Studio if you are using Windows so it would have been an option), but the scripts are not at all flexible, or it is not documented at all for me to see it's flexibility because I don't think it is at all (but also, I don't know much about shell/batch and python scripting so it was extra hard for me to follow). It not only sets those env variables and stuff but also freaking generates CMake cache files all by itself and does not allow you to do it? Really? You can't add PhysX as dependency for your project if it does that. Not like you can call CMake manually either because the command is like 3-5 lines long in my HD monitor. "PhysX uses CMake to generate build configuration files (e.g. Microsoft Visual Studio Solutions or Makefiles) for all supported platforms." This is just only ever slightly true, but it is mostly a stupid lie. I could NOT get it to cooperate. I cannot just do `add_subdirectory` to the PhysX path to make it work. It needs like 8 or so variables mandatorily set. It even relies on temporarily environment variables which just completely disappears when the script(s) exits so you can't even manually set them up either. Honestly, which fucking moron wrote this piece of shit? Instead of using `CMAKE_CURRENT_SOURCE_DIR`, they define their own `PHYSX_ROOT_PATH` or something. Along with 7 or so other variables that needs to be defined in order for it to work, instead of using CMake's built in ones like a normal person. Also, me having to remove `-Werror` because their code is not cross-platform clean and generate 0.3 million lines of warnings is just a cherry on top. They actually don't know build system. Period.
