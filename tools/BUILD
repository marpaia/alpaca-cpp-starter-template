load("@com_github_marpaia_alpaca_trade_api_cpp//bazel:deps.bzl", "ALPACA_DEPS")

cc_binary(
    name = "view_open_positions",
    srcs = ["view_open_positions.cpp"],
    deps = ["@com_github_marpaia_alpaca_trade_api_cpp//alpaca:alpaca"] + ALPACA_DEPS,
)

cc_binary(
    name = "run_stream_handler",
    srcs = ["run_stream_handler.cpp"],
    deps = ["@com_github_marpaia_alpaca_trade_api_cpp//alpaca:alpaca"] + ALPACA_DEPS,
)

cc_binary(
    name = "check_if_market_is_open",
    srcs = ["check_if_market_is_open.cpp"],
    deps = ["@com_github_marpaia_alpaca_trade_api_cpp//alpaca:alpaca"] + ALPACA_DEPS,
)

cc_binary(
    name = "view_account_info",
    srcs = ["view_account_info.cpp"],
    deps = ["@com_github_marpaia_alpaca_trade_api_cpp//alpaca:alpaca"] + ALPACA_DEPS,
)
