cmake_minimum_required(VERSION 3.0)

project(otp-client C)

add_library(TOTP STATIC library/cotp.c)
add_library(OTP STATIC library/otp.c)
add_library(Clipboard STATIC library/clipboard.c)

add_compile_definitions(BASE32_SECRET=${SECRET})

include_directories("./include")

set(SOURCE_FILES main.c)
add_executable(otp-client ${SOURCE_FILES})

target_link_libraries(TOTP crypto)
target_link_libraries(TOTP m)
target_link_libraries(OTP TOTP)
target_link_libraries(OTP Clipboard)
target_link_libraries(otp-client OTP)

install(TARGETS otp-client DESTINATION /bin)
