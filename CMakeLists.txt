cmake_minimum_required(VERSION 3.0)

project(door-server C)

add_library(TOTP STATIC library/cotp.c)
add_library(OTP STATIC library/otp.c)

include_directories("./include")

set(SOURCE_FILES main.c)
add_executable(door-server ${SOURCE_FILES})

target_link_libraries(TOTP crypto)
target_link_libraries(TOTP m)
target_link_libraries(OTP TOTP)
target_link_libraries(door-server OTP)

install(TARGETS door-server DESTINATION /bin)
