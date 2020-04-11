workspace(name = "alpaca_cpp_starter_template")

################################################################################
# General Initialization
################################################################################

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

################################################################################
# C++ Dependencies
################################################################################

# alpaca-trade-api-cpp is a C++ client library for the Alpaca Trading API.
http_archive(
    name = "com_github_marpaia_alpaca_trade_api_cpp",
    strip_prefix = "alpaca-trade-api-cpp-0.0.2",
    urls = ["https://github.com/marpaia/alpaca-trade-api-cpp/archive/v0.0.2.tar.gz"],
    sha256 = "65aa17318d356ff7cfc55e6510cebcf1ab94c3d7a3eb0f6175a197b503cb7dfe",
)
load("@com_github_marpaia_alpaca_trade_api_cpp//bazel:deps.bzl", "alpaca_deps")
alpaca_deps()
