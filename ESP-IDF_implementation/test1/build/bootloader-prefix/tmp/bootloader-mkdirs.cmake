# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/sarang/.espressif/v6.0/esp-idf/components/bootloader/subproject"
  "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader"
  "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader-prefix"
  "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader-prefix/tmp"
  "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader-prefix/src/bootloader-stamp"
  "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader-prefix/src"
  "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/sarang/GPS_telemetry/ESP-IDF_implementation/test1/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
