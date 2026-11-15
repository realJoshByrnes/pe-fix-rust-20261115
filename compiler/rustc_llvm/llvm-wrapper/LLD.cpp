#include "lld/Common/Driver.h"

LLD_HAS_DRIVER(elf)
LLD_HAS_DRIVER(wasm)
LLD_HAS_DRIVER(mingw)

extern "C" int RustRunLld(int argc, char **argv) {
    llvm::ArrayRef<const char *> args(argv, argv + argc);
    auto r = lld::lldMain(args, llvm::outs(), llvm::errs(),
                         {{lld::Gnu, &lld::elf::link}, {lld::Wasm, &lld::wasm::link},
                          {lld::MinGW, &lld::mingw::link}});
    return r.retCode;
}
