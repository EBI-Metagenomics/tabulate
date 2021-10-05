cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(
  tabulate
  VERSION 0.0.1
  LANGUAGES C)

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(external/cmake-boilerplate/cbp.cmake)
cbp_set_rpath()

add_library(
  tbl
  src/3x_ed.c
  src/row_flex.c)
add_library(TBL::tbl ALIAS tbl)

cbp_hide_functions(tbl)
cbp_set_warning_flags()
cbp_ci_build_option()
cbp_generate_export_header(tbl EXPORT_FILE)

target_include_directories(
  tbl
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set_target_properties(tbl PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(tbl PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
target_compile_features(tbl PRIVATE c_std_11)
target_compile_definitions(
  tbl PRIVATE $<$<BOOL:${WIN32}>:_CRT_NONSTDC_NO_DEPRECATE>)
target_compile_definitions(tbl PRIVATE $<$<BOOL:${WIN32}>:__extension__>)
target_compile_options(tbl PRIVATE ${WARNING_FLAGS})
target_compile_options(tbl PRIVATE "-fverbose-asm")

cbp_install(tbl MERGED)
install(FILES ${EXPORT_FILE} ${VERSION_FILE} DESTINATION include/tbl)

enable_testing()
add_subdirectory(test)
