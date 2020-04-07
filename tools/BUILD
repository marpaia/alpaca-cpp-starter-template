cc_binary(
    name = "view_open_positions",
    srcs = [
        "view_open_positions.cpp",
    ],
    deps = [
        "@com_github_google_boringssl//:ssl",
        "@com_github_gflags_gflags//:gflags",
        "@com_github_google_glog//:glog",
        "@com_github_madler_zlib//:zlib",
        "@com_github_marpaia_alpaca-trade-api-cpp//alpaca:alpaca",
        "@com_github_tencent_rapidjson//:rapidjson",
        "@com_github_unetworking_uwebsockets//:uwebsockets",
        "@com_github_yhirose_cpp-httplib//:httplib",
    ],
    defines = [
        "NDEBUG",
    ]
)