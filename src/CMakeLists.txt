# Copyright (c) 2025 Nathan Greenfield. All rights reserved

# Require CMAKE 3.20 or higher
cmake_minimum_required(VERSION 3.20)

# If you create new headers files, add them to these list!
set(HEADER_FILES
    SMCDoubleList.hpp
    movie.h
)

# If you create new cpp files, add them to these list!
set(SOURCE_FILES
    movie.cpp
)

# Don't change this
add_library(src ${SOURCE_FILES} ${HEADER_FILES})

