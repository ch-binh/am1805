# Install script for directory: C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/interface/include/tfm_ioctl_core_api.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/interface/include" TYPE FILE MESSAGE_NEVER FILES "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/services/include/tfm_ioctl_core_api.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/interface/src/tfm_ioctl_core_ns_api.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/interface/src" TYPE FILE MESSAGE_NEVER FILES "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/services/src/tfm_ioctl_core_ns_api.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/config_nordic_nrf_spe.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core" TYPE FILE MESSAGE_NEVER FILES "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/config_nordic_nrf_spe.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/ext/driver/Driver_Common.h;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/ext/driver/Driver_Flash.h;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/ext/driver/Driver_USART.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/ext/driver" TYPE FILE MESSAGE_NEVER FILES
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_Common.h"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_Flash.h"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_USART.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/startup.c;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/startup_nrf5340.c;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/nrfx_glue.c;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/pal_plat_test.c;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/pal_plat_test.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core" TYPE FILE MESSAGE_NEVER FILES
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/startup.c"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/startup_nrf5340.c"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/nrfx_glue.c"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/pal_plat_test.c"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/pal_plat_test.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/startup.h;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/target_cfg.h;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/nrfx_config.h;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/CMakeLists.txt;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/config.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core" TYPE FILE MESSAGE_NEVER FILES
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/startup.h"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/target_cfg.h"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/nrfx_config.h"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/ns/CMakeLists.txt"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/config.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/native_drivers;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/cmsis_drivers;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/common;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/nrfx;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/services;D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core/tests")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/common/core" TYPE DIRECTORY MESSAGE_NEVER FILES
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/native_drivers"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/cmsis_drivers"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/common"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/nrfx"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/services"
    "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/tests"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/linker_scripts/tfm_common_ns.ld")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/ACD/Projects/BSKT/Projects/lib/am1805/project/zephyr/nordic/set_timer_interrupt_out/bd/tfm/api_ns/platform/linker_scripts" TYPE FILE MESSAGE_NEVER FILES "C:/ncs/v2.7.0/modules/tee/tf-m/trusted-firmware-m/platform/ext/common/gcc/tfm_common_ns.ld")
endif()

