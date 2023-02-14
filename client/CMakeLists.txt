add_executable(client client.cpp)
target_link_libraries(client PRIVATE yalantinglibs::coro_rpc)