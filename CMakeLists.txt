cmake_minimum_required(VERSION 3.5)

# VelodyneHDL Driver
project(VelodyneHDL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Threads)
find_package(Boost REQUIRED COMPONENTS system thread)
find_package(libpcap REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

add_library(PacketDriver STATIC PacketDriver.cpp)
target_link_libraries(PacketDriver
  Boost::system
)

add_library(PacketDecoder STATIC PacketDecoder.cpp)
target_link_libraries(PacketDecoder
)

add_library(PacketBundler STATIC PacketBundler.cpp)
target_link_libraries(PacketBundler
)

add_library(PacketBundleDecoder STATIC PacketBundleDecoder.cpp)
target_link_libraries(PacketBundleDecoder
)

add_executable(test_PacketDriver tests/test_PacketDriver.cpp)
target_link_libraries(test_PacketDriver
  PacketDriver
  libpcap::libpcap
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_PacketDecoder tests/test_PacketDecoder.cpp)
target_link_libraries(test_PacketDecoder
  PacketDriver
  PacketDecoder
  libpcap::libpcap
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_PacketWriter tests/test_PacketWriter.cpp)
target_link_libraries(test_PacketWriter
  PacketDriver
  libpcap::libpcap
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_PacketBundler tests/test_PacketBundler.cpp)
target_link_libraries(test_PacketBundler
  PacketDriver
  PacketBundler
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_PacketBundleDecoder tests/test_PacketBundleDecoder.cpp)
target_link_libraries(test_PacketBundleDecoder
  PacketDriver
  PacketBundler
  PacketBundleDecoder
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(PacketFileSender PacketFileSender.cxx)
target_link_libraries(PacketFileSender
  Boost::system
  Boost::thread
  libpcap::libpcap
  ${CMAKE_THREAD_LIBS_INIT}
)
