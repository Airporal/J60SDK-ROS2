cmake_minimum_required(VERSION 3.8)
project(j60controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(j60interfaces REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/j60controller)
add_library(deep_motor_sdk STATIC src/deep_motor_sdk.cpp)
target_include_directories(deep_motor_sdk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# set(SRC_FILES
#   src/j60reader.cpp
#   src/Mymaster.cpp
#   src/reader.cpp
#   src/j60master.cpp  # 如果需要，可以取消注释
# )

add_executable(j60master src/j60master.cpp src/Mymaster.cpp)
target_link_libraries(j60master deep_motor_sdk)
target_include_directories(j60master PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(j60master PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  j60master
  "rclcpp"
  "j60interfaces"
)

install(TARGETS j60master
  DESTINATION lib/${PROJECT_NAME})


add_executable(j60reader src/j60reader.cpp src/reader.cpp)
target_include_directories(j60reader PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(j60reader PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  j60reader
  "rclcpp"
  "j60interfaces"
)
install(TARGETS j60reader
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
