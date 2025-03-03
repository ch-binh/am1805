# Install script for directory: C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "MinSizeRel")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/ncs/toolchains/ce3b5ff664/opt/zephyr-sdk/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/platform/target/nrf5340/nrf_common/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340/nrfx_config_nrf5340_application.h;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340/CMakeLists.txt;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340/config.cmake;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340/cpuarch.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340" TYPE FILE MESSAGE_NEVER FILES
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/nrfx_config_nrf5340_application.h"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/ns/CMakeLists.txt"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/config.cmake"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/cpuarch.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340/partition;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340/tests")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/nrf5340" TYPE DIRECTORY MESSAGE_NEVER FILES
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/partition"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/tests"
    )
endif()

