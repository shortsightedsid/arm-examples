include (CMakeForceCompiler)

if (NOT TOOLCHAIN_INSTALL_DIR)
     set(TOOLCHAIN_INSTALL_DIR "/opt/arm-unknown-eabi")
     message(STATUS "No TOOLCHAIN_INSTALL_DIR specified, using default: " ${TOOLCHAIN_INSTALL_DIR})
else ()
     message(STATUS "Using TOOLCHAIN_INSTALL_DIR: " ${TOOLCHAIN_INSTALL_DIR})
endif()

if (NOT CROSS_COMPILE)
    set(CROSS_COMPILE "arm-unknown-eabi")
    message(STATUS "No CROSS_COMPILE specified, using default: " ${CROSS_COMPILE})
endif()

set (TOOLCHAIN_BIN_DIR ${TOOLCHAIN_INSTALL_DIR}/bin)
set (TOOLCHAIN_INC_DIR ${TOOLCHAIN_INSTALL_DIR}/${CROSS_COMPILE}/include)
set (TOOLCHAIN_LIB_DIR ${TOOLCHAIN_INSTALL_DIR}/${CROSS_COMPILE}/lib)

set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_SYSTEM_PROCESSOR arm)

CMAKE_FORCE_C_COMPILER(${TOOLCHAIN_BIN_DIR}/${CROSS_COMPILE}-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(${TOOLCHAIN_BIN_DIR}/${CROSS_COMPILE}-g++ GNU)
set (CMAKE_ASM_COMPILER ${TOOLCHAIN_BIN_DIR}/${CROSS_COMPILE}-gcc)

set (CMAKE_OBJCOPY ${TOOLCHAIN_BIN_DIR}/${CROSS_COMPILE}-objcopy CACHE INTERNAL "objcopy tool")
set (CMAKE_OBJDUMP ${TOOLCHAIN_BIN_DIR}/${CROSS_COMPILE}-objdump CACHE INTERNAL "objdump tool")

set (C_CPU_FLAGS "-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -MD -DPART_TM4C1294NCPDT")
set (ASM_CPU_FLAGS "-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MD")

set (CMAKE_C_FLAGS "-nostdlib -nostartfiles -ffreestanding ${CMAKE_C_FLAGS} ${C_CPU_FLAGS}" CACHE INTERNAL "c compiler flags")
set (CMAKE_CXX_FLAGS "-nostdlib -nostartfiles -ffreestanding -fno-exceptions ${CMAKE_CXX_FLAGS} ${C_CPU_FLAGS}" CACHE INTERNAL "cxx compiler flags")
set (CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${ASM_CPU_FLAGS}" CACHE INTERNAL "asm compiler flags")
set (CMAKE_EXE_LINKER_FLAGS "" CACHE INTERNAL "linker flags")

set (CMAKE_C_FLAGS_DEBUG "-nostdlib -nostartfiles -ffreestanding ${CMAKE_C_FLAGS_DEBUG} -Og -g ${C_CPU_FLAGS}" CACHE INTERNAL "c compiler flags debug")
set (CMAKE_CXX_FLAGS_DEBUG "-nostdlib -nostartfiles -ffreestanding -fno-exceptions ${CMAKE_CXX_FLAGS_DEBUG} -Og -g ${C_CPU_FLAGS}" CACHE INTERNAL "cxx compiler flags debug")
set (CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -g ${ASM_CPU_FLAGS}" CACHE INTERNAL "asm compiler flags debug")
set (CMAKE_EXE_LINKER_FLAGS_DEBUG "" CACHE INTERNAL "linker flags debug")

set (CMAKE_C_FLAGS_RELEASE "-nostdlib -nostartfiles -ffreestanding ${CMAKE_C_FLAGS_RELEASE} -Os -flto ${C_CPU_FLAGS}" CACHE INTERNAL "c compiler flags release")
set (CMAKE_CXX_FLAGS_RELEASE "-nostdlib -nostartfiles -ffreestanding -fno-exceptions ${CMAKE_CXX_FLAGS_RELEASE} -Os -flto ${C_CPU_FLAGS}" CACHE INTERNAL "cxx compiler flags release")
set (CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} ${ASM_CPU_FLAGS}" CACHE INTERNAL "asm compiler flags release")
set (CMAKE_EXE_LINKER_FLAGS_RELEASE "-flto" CACHE INTERNAL "linker flags release")

set (CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_INSTALL_DIR}/${CROSS_COMPILE} ${EXTRA_FIND_PATH})
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

function (my_set_linker_params TARGET)
    if(NOT LINKER_SCRIPT)
        message(FATAL_ERROR "No linker script specified. Please specify linker script using LINKER_SCRIPT variable.")
    endif()
    configure_file(${LINKER_SCRIPT} ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.ld)
    
    get_target_property(TARGET_LD_FLAGS ${TARGET} LINK_FLAGS)
    if(TARGET_LD_FLAGS)
        set(TARGET_LD_FLAGS "-nostdlib -nostartfiles -ffreestanding -T${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.ld ${TARGET_LD_FLAGS}")
    else()
        set(TARGET_LD_FLAGS "-nostdlib -nostartfiles -ffreestanding -T${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.ld")
    endif()
    set_target_properties(${TARGET} PROPERTIES LINK_FLAGS ${TARGET_LD_FLAGS})
endfunction ()

function (my_set_target_properties TARGET)
    my_set_linker_params(${TARGET})
endfunction ()
