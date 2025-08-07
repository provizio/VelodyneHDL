cmake_minimum_required(VERSION 2.8.7)

# VelodyneHDL Driver
project(VelodyneHDL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost)
find_package(libpcap)
find_package(Threads)

add_library(boost_system ALIAS Boost::system)
add_library(boost_thread ALIAS Boost::thread)

add_library(PacketDriver SHARED PacketDriver.cpp)
target_link_libraries(PacketDriver
  boost_system
)
target_include_directories(PacketDriver PUBLIC .)
set_target_properties(PacketDriver PROPERTIES PUBLIC_HEADER "PacketDriver.h")
install(TARGETS PacketDriver
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

add_library(PacketDecoder SHARED PacketDecoder.cpp)
target_link_libraries(PacketDecoder
  boost_system
)
target_include_directories(PacketDecoder PUBLIC .)
set_target_properties(PacketDecoder PROPERTIES PUBLIC_HEADER "PacketDecoder.h")
install(TARGETS PacketDecoder
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

add_library(PacketBundler SHARED PacketBundler.cpp)
target_link_libraries(PacketBundler
)
target_include_directories(PacketBundler PUBLIC .)
set_target_properties(PacketBundler PROPERTIES PUBLIC_HEADER "PacketBundler.h")
install(TARGETS PacketBundler
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

add_library(PacketBundleDecoder SHARED PacketBundleDecoder.cpp)
target_link_libraries(PacketBundleDecoder
  boost_system
)
target_include_directories(PacketBundleDecoder PUBLIC .)
set_target_properties(PacketBundleDecoder PROPERTIES PUBLIC_HEADER "PacketBundleDecoder.h")
install(TARGETS PacketBundleDecoder
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

add_executable(test_PacketDriver tests/test_PacketDriver.cpp)
target_link_libraries(test_PacketDriver
  PacketDriver
  pcap
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_PacketDecoder tests/test_PacketDecoder.cpp)
target_link_libraries(test_PacketDecoder
  PacketDriver
  PacketDecoder
  pcap
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_PacketWriter tests/test_PacketWriter.cpp)
target_link_libraries(test_PacketWriter
  PacketDriver
  pcap
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
  boost_system
  boost_thread
  pcap
  ${CMAKE_THREAD_LIBS_INIT}
)
install(TARGETS PacketFileSender
        RUNTIME DESTINATION bin
)
