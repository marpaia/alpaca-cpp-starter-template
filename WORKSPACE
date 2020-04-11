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
    strip_prefix = "alpaca-trade-api-cpp-master",
    urls = ["https://github.com/marpaia/alpaca-trade-api-cpp/archive/master.tar.gz"],
)
load("@com_github_marpaia_alpaca_trade_api_cpp//bazel:deps.bzl", "alpaca_deps")
alpaca_deps()
