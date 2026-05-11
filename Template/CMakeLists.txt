set(OpenCV_ROOT "${VCPKG_INSTALLED_DIR}/x64-windows/share/opencv4")
find_package(OpenCV REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(Template 
    "main.cpp" 
    "src/template.cpp" 
    "src/utils.cpp" 
    "include/utils.h"
    "include/template.h"
)

target_link_libraries(Template PRIVATE 
    ${OpenCV_LIBS} 
    nlohmann_json::nlohmann_json
)

set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)

set(INPUT_FILES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Assets)
set(OUTPUT_DIR $<TARGET_FILE_DIR:Template>)

add_custom_command(TARGET Template POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${INPUT_FILES_DIR} ${OUTPUT_DIR}/Assets
)