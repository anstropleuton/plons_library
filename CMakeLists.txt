cmake_minimum_required(VERSION 3.30)

project(PlonsLibrary
    VERSION 1.0.0.0
    DESCRIPTION "Plons Library is a collection of utils for Anstro Pleuton's programs."
    HOMEPAGE_URL "https://anstropleuton.github.io/plons_library/"
    LANGUAGES CXX
)

option(BUILD_SHARED_LIBS "Build Plons Library as shared library" OFF)
option(BUILD_TESTS "Build Plons Library tests" OFF)
option(BUILD_EXAMPLES "Build Plons Library usage examples" OFF)

if(NOT DEFINED PLONS_LIBRARY_PHYSX_PATH)
    set(PLONS_LIBRARY_PHYSX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps/PhysX")
endif()

if(NOT DEFINED PLONS_LIBRARY_BGFX_PATH)
    set(PLONS_LIBRARY_BGFX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps/bgfx.cmake")
endif()

if(NOT DEFINED PLONS_LIBRARY_GLFW_PATH)
    set(PLONS_LIBRARY_GLFW_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw")
endif()

if(NOT DEFINED PLONS_LIBRARY_GLM_PATH)
    set(PLONS_LIBRARY_GLM_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps/glm")
endif()

if(NOT DEFINED PLONS_LIBRARY_PLATFORM)
    if(WIN32)
        set(PLONS_LIBRARY_PLATFORM "vc17win64") # You can directly set it to vc16win64 if you are using Visual Studio 2019
    elseif(UNIX)
        if(ARM)
            set(PLONS_LIBRARY_PLATFORM "linux-aarch64")
        else()
            set(PLONS_LIBRARY_PLATFORM "linux")
        endif()
    endif()
endif()

set(PLONS_LIBRARY_IS_GCC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(PLONS_LIBRARY_IS_MSVC_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/include/plons_library_config.hpp.in" plons_library_config.hpp)

set(PLONS_LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/tmp.cpp"
)
set(PLONS_LIBRARY_INCLUDES_DIRECTORIES
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}"
)

add_library(plons_library ${PLONS_LIBRARY_SOURCES})
target_include_directories(plons_library PUBLIC ${PLONS_LIBRARY_INCLUDES_DIRECTORIES})
target_compile_features(plons_library PUBLIC cxx_std_23)
target_compile_options(plons_library PRIVATE
    $<${PLONS_LIBRARY_IS_GCC_LIKE_CXX}:-Wall;-Wextra;-Wshadow;-Wformat=2>
    $<${PLONS_LIBRARY_IS_MSVC_CXX}:-W3> # I don't know what I am doing with MSVC
)

# Add PhysX
# Use their own outdated piece of shit to get the bin path
cmake_policy(PUSH)
cmake_policy(SET CMP0153 OLD)
include("${PLONS_LIBRARY_PHYSX_PATH}/physx/source/compiler/cmake/modules/GetCompilerAndPlatform.cmake")
GetPlatformBinName(PLATFORM_BIN_NAME "64")
cmake_policy(POP)

target_include_directories(plons_library PUBLIC "${PLONS_LIBRARY_PHYSX_PATH}/physx/include")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(plons_library PUBLIC _DEBUG)
    target_link_directories(plons_library PUBLIC "${PLONS_LIBRARY_PHYSX_PATH}/physx/bin/${PLATFORM_BIN_NAME}/debug")
else()
    target_compile_definitions(plons_library PUBLIC NDEBUG)
    target_link_directories(plons_library PUBLIC "${PLONS_LIBRARY_PHYSX_PATH}/physx/bin/${PLATFORM_BIN_NAME}/release")
endif()

if(PLONS_LIBRARY_PLATFORM STREQUAL "vc16win64" OR PLONS_LIBRARY_PLATFORM STREQUAL "vc17win64")
    target_link_libraries(plons_library PUBLIC
        freeglut
        PhysXCommon_64
        PhysXCooking_64
        PhysXDevice64
        PhysXFoundation_64
        PhysXGpu_64
        PhysX_64
        PVDRuntime_64
    )
elseif(PLONS_LIBRARY_PLATFORM STREQUAL "linux" OR PLONS_LIBRARY_PLATFORM STREQUAL "linux-aarch64") # TODO: Test with linux-aarch64 (I don't own one)
    target_link_libraries(plons_library PUBLIC
        PhysXCharacterKinematic_static_64
        PhysXCommon_static_64
        PhysXCooking_static_64
        PhysXExtensions_static_64
        PhysXFoundation_static_64
        PhysXGpu_64
        PhysXPvdSDK_static_64
        PhysX_static_64
        PhysXVehicle2_static_64
        PhysXVehicle_static_64
        PVDRuntime_64
        SnippetRender_static_64
        SnippetUtils_static_64
    )
endif()

# Add BGFX
# Just look how simple this is compared to pHySx
find_package(bgfx QUIET)
if(NOT bgfx_FOUND)
    message("bgfx not found, adding subdirectory ${PLONS_LIBRARY_BGFX_PATH}")
    add_subdirectory(${PLONS_LIBRARY_BGFX_PATH})
else()
    message("bgfx found, using it instead")
endif()
target_link_libraries(plons_library PUBLIC bgfx bimg bx)

# Add GLFW
find_package(glfw3 QUIET)
if(NOT glfw3_FOUND)
    message("glfw3 not found, adding subdirectory ${PLONS_LIBRARY_GLFW_PATH}")
    add_subdirectory(${PLONS_LIBRARY_GLFW_PATH})
else()
    message("glfw3 found, using it instead")
endif()
target_link_libraries(plons_library PUBLIC glfw)

# Add GLM
find_package(glm QUIET)
if(NOT glm_FOUND)
    message("glm not found, adding subdirectory ${PLONS_LIBRARY_GLM_PATH}")
    add_subdirectory(${PLONS_LIBRARY_GLM_PATH})
else()
    message("glm found, using it instead")
endif()
target_link_libraries(plons_library PUBLIC glm)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
