cmake_minimum_required(VERSION 3.23..4)
project(Qemu-wrapper VERSION 1.0 DESCRIPTION "Wrapper to set cpu for qemu" LANGUAGES C)
set(CPU "cortex-a72" CACHE STRING "The cpu option to pass to qemu")
add_executable(qemu-aarch64-wrapper qemu-wrapper.c)
target_compile_options(qemu-aarch64-wrapper PRIVATE -DCPU="${CPU}" PRIVATE -DARCH="aarch64")
add_executable(qemu-arm-wrapper qemu-wrapper.c)
target_compile_options(qemu-arm-wrapper PRIVATE -DCPU="${CPU}" PRIVATE -DARCH="arm")

