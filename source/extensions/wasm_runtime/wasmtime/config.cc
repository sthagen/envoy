#include "envoy/registry/registry.h"

#include "extensions/common/wasm/wasm_runtime_factory.h"

#include "include/proxy-wasm/wasmtime.h"

namespace Envoy {
namespace Extensions {
namespace Common {
namespace Wasm {

class WasmtimeRuntimeFactory : public WasmRuntimeFactory {
public:
  WasmVmPtr createWasmVm() override { return proxy_wasm::createWasmtimeVm(); }

  absl::string_view name() override { return "envoy.wasm.runtime.wasmtime"; }
  absl::string_view shortName() override { return "wasmtime"; }
};

#if defined(ENVOY_WASM_WASMTIME)
REGISTER_FACTORY(WasmtimeRuntimeFactory, WasmRuntimeFactory);
#endif

} // namespace Wasm
} // namespace Common
} // namespace Extensions
} // namespace Envoy
