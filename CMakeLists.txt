cmake_minimum_required(VERSION 3.19)

# Задаем имя проекта
project(qtprojecttemplate VERSION 0.1 LANGUAGES CXX)

if(POLICY CMP0177)
    cmake_policy(SET CMP0177 NEW)
endif()

# Задаем переменные и настройки
include(${PROJECT_SOURCE_DIR}/cmake/settings.cmake.in)

# Задаем исходные файлы для сборки проекта
include(${PROJECT_SOURCE_DIR}/cmake/src.cmake.in)

# Задаем настройки сборки программы
include(${PROJECT_SOURCE_DIR}/cmake/conf.cmake.in)

# Задаем настройки для сборки проекта Qt6
include(${PROJECT_SOURCE_DIR}/cmake/qt6.cmake.in)

# Задаем targets для библиотеки
include(${PROJECT_SOURCE_DIR}/cmake/targets.cmake.in)
