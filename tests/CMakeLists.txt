find_package(GTest REQUIRED CONFIG)
find_package(nlohmann_json CONFIG REQUIRED)

add_library(template_proj 
"../Template/src/utils.cpp"
)

target_include_directories(template_proj PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../Template/include> 
    $<INSTALL_INTERFACE:include>                         
)

target_link_libraries(template_proj PUBLIC nlohmann_json::nlohmann_json)

add_subdirectory(unit_test)