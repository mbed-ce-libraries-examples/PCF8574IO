#[[https://github.com/mbed-ce/mbed-os/wiki/MbedOS-configuration#libraries-in-your-application]]

#[[ Set name of library in lowcase]]
set(INTERNAL_LIBRARY_NAME "pcf8574io")

#[[ Here fill all .cpp files]]
add_library(${INTERNAL_LIBRARY_NAME} STATIC PCF8574IO.cpp)

#[[ Include .h files]]
target_include_directories(${INTERNAL_LIBRARY_NAME} INTERFACE .)

#[[Link library to mbed-core-flags but if the library needs to use RTOS
 features, then have to be add also mbed-rtos-flags]]
target_link_libraries(${INTERNAL_LIBRARY_NAME} PUBLIC mbed-core-flags)