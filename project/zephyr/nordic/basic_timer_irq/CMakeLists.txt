# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(set_alarm_interrupt_out)

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/inc)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/../../../../inc)


FILE(GLOB app_sources src/*.c)
FILE(GLOB lib_sources ../../../../src/*.c)

target_sources(app PRIVATE ${app_sources})
target_sources(app PRIVATE ${lib_sources})