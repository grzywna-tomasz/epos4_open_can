add_library(freertos_config INTERFACE)

target_include_directories(freertos_config SYSTEM
INTERFACE
    inc
)

set( FREERTOS_HEAP "4" CACHE STRING "" FORCE)
set( FREERTOS_PORT "GCC_ARM_CM3" CACHE STRING "" FORCE)

target_compile_definitions(freertos_config
  INTERFACE
    projCOVERAGE_TEST=0
)