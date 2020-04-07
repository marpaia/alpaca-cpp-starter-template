# Alpaca C++ Starter Template

This repository is a template project which aims to provide a useful starting point for C++-based algorithmic trading services powered by [Alpaca](https://alpaca.markets) using the [Bazel](https://www.bazel.build/) build system.

Alpaca is a modern platform for algorithmic trading. You can use the Alpaca API to communicate with Alpaca’s brokerage service. The API allows your trading algorithm to access real-time price data, place orders, maintain watchlists, manage your portfolio, and more. In order to start trading with Alpaca API, please sign up at https://alpaca.markets/.

Bazel is an open-source build and test tool similar to Make, Maven, and Gradle. Bazel supports projects in multiple languages and builds outputs for multiple platforms. Bazel supports large codebases across multiple repositories, and large numbers of users. See the [Bazel Installation Instructions](https://docs.bazel.build/versions/master/install.html) for more information on installing Bazel on your system.

## Defining Envrionment Variables

Consider creating a file called `.env` with content like the following:

```bash
export APCA_API_KEY_ID="<Alpaca API Key ID>"
export APCA_API_SECRET_KEY="<Alpaca API Secret Key>"
export APCA_API_BASE_URL=paper-api.alpaca.markets
export APCA_API_DATA_URL=data.alpaca.markets
```

Then, you can configure this file to be sourced automatically into your shell with a tool like [dotenv](https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins/dotenv) or you can manually `source .env` before running any programs that youu build.

## Building and Running Binaries

You can use Bazel to run tools directly!

```
$ bazel run //tools:view_open_positions
INFO: Analyzed target //tools:view_open_positions (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //tools:view_open_positions up-to-date:
  bazel-bin/tools/view_open_positions
INFO: Elapsed time: 0.115s, Critical Path: 0.00s
INFO: 0 processes.
INFO: Build completed successfully, 1 total action
INFO: Build completed successfully, 1 total action
Found 2 positions
  - 331 shares in NFLX worth $379.96 each / $125832.96 in total
  - 2 shares in AAPL worth $262.47 each / $532 in total
```

Or you can build a tool and run it directly:

```
$ bazel build //tools:view_open_positions
INFO: Analyzed target //tools:view_open_positions (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //tools:view_open_positions up-to-date:
  bazel-bin/tools/view_open_positions
INFO: Elapsed time: 0.118s, Critical Path: 0.00s
INFO: 0 processes.
INFO: Build completed successfully, 1 total action
$ ./bazel-bin/tools/view_open_positions
Found 2 positions
  - 331 shares in NFLX worth $379.96 each / $125832.96 in total
  - 2 shares in AAPL worth $262.47 each / $532 in total
```