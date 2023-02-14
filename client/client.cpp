#include "coro_rpc/coro_rpc_client.hpp"
#include "service.h"
async_simple::coro::Lazy<void> call_rpc(coro_rpc::coro_rpc_client& client) {
  auto ec = co_await client.connect("127.0.0.1", "8801");
  if (ec != std::errc{}) {
    std::cout << "connect error" << std::endl;
    co_return;
  }
  auto ret = co_await client.call<hi>();
  if (!ret) {
    std::cout << "call error" << std::endl;
    co_return;
  }
  std::cout << "call success" << std::endl;
}

int main() {
  coro_rpc::coro_rpc_client client;
  async_simple::coro::syncAwait(call_rpc(client));
  return 0;
}