# Contributor Guide

This document has the following sections:

- [Setup](#setup)
- [Build](#build)
- [Test](#test)
- [Develop](#develop)


## Setup

To build and test the code, you must have a working installation of [Bazel](https://www.bazel.build/). Bazel is an open-source build and test tool similar to Make, Maven, and Gradle. See the [Bazel Installation Instructions](https://docs.bazel.build/versions/master/install.html) for more information on installing Bazel on your system.

## Build

To build all targets in a subdirectory, run a command like the following:

```
bazel build //server/...
```

To build a specific target in a minimal way, specify an individual build target with a command like the following:

```
bazel build //server:server
```

## Test

To run all tests in a subdirectory, run a command like the following:

```
bazel test //server/...
```

To run a specific test, specify an individual test target:

```
bazel test //server:server_test
```

## Develop

### Formatting C++ Files

To format all C++ source files using [`clang-format`](https://clang.llvm.org/docs/ClangFormat.html), run the following:

```
find . -name "*.h" -or -name "*.cpp" | xargs clang-format -i
```
