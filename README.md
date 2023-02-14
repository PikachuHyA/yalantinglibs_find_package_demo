# yalantinglibs_find_package_demo

To build the project, you must install yalantinglibs first.
Otherwise, an error occurred.

```
CMake Error at CMakeLists.txt:15 (find_package):
  By not providing "Findyalantinglibs.cmake" in CMAKE_MODULE_PATH this
  project has asked CMake to find a package configuration file provided by
  "yalantinglibs", but CMake did not find one.

  Could not find a package configuration file provided by "yalantinglibs"
  with any of the following names:

    yalantinglibsConfig.cmake
    yalantinglibs-config.cmake

  Add the installation prefix of "yalantinglibs" to CMAKE_PREFIX_PATH or set
  "yalantinglibs_DIR" to a directory containing one of the above files.  If
  "yalantinglibs" provides a separate development package or SDK, be sure it
  has been installed.
```


And you have to use CMake to manage your project.

## Install yaLanTingLibs

Currently, only build from sources supported.
Install from package manager (e.g. conan and vcpkg) is WIP.

use the following instructions

- clone yaLanTingLibs
```shell
git clone https://github.com/alibaba/yalantinglibs.git
cd yalantinglibs
```

- build yaLanTingLibs
```shell
mkdir build && cd build
cmake ..
make -j
```
- install yaLanTingLibs

```shell
# sudo if needed
make install 
```

## Use yaLanTingLibs
write `CMakeLists.txt` and use find_package

```
cmake_minimum_required(VERSION 3.15)

project(awesome-solution LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# it's very important to set the compiler flags
# if you use gcc/g++
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines")
    if (CMAKE_CXX_COMPILER_VERSION MATCHES "12.*")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-maybe-uninitialized")
    endif()
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(Threads REQUIRED)
find_package(yalantinglibs REQUIRED)
# add your server
target_link_libraries(your_server PRIVATE yalantinglibs::coro_rpc)
```

the full demo is here: https://github.com/PikachuHyA/yalantinglibs_find_package_demo

## Reference

- [CMake find_package Document](https://cmake.org/cmake/help/latest/command/find_package.html?highlight=find_package)
- [use yaLanTingLibs with CMake find_package demo code](https://github.com/PikachuHyA/yalantinglibs_find_package_demo)
- [use yaLanTingLibs as Git Submodule demo code](https://github.com/PikachuHyA/yalantinglibs_as_submodule_demo)

