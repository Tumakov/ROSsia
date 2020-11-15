cmake_minimum_required(VERSION 3.0.2)
project(lab1)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/my_super_package1.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
