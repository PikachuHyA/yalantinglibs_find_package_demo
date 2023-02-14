#include "coro_rpc/coro_rpc_server.hpp"
#include "service.h"
#include "coro_rpc/rpc_connection.hpp"
void hi() {
  std::cout << "call hi" << std::endl;
}
int main() {
  coro_rpc::coro_rpc_server server(2, 8801);
  server.regist_handler<hi>();
  auto ec = server.start();
  return ec == std::errc{};
}