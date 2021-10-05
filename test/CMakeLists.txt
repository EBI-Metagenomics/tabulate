find_package(hope REQUIRED)

function(tbl_add_test name srcs)
  add_executable(${name} ${srcs})
  target_link_libraries(${name} PRIVATE TBL::tbl)
  target_link_libraries(${name} PRIVATE HOPE::hope)
  target_compile_options(${name} PRIVATE ${WARNING_FLAGS})
  target_compile_features(${name} PRIVATE c_std_11)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

tbl_add_test(tbl_3x_ed tbl_3x_ed.c)
