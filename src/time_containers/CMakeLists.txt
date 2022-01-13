add_library(time_containers_lib STATIC
FiscalYear.cpp
TimePeriod.cpp
)

target_link_libraries(time_containers_lib PUBLIC accounting_lib)
