#include <iostream>

#include "alpaca/alpaca.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;
  FLAGS_minloglevel = 2;

  // Parse the configuration from the environment
  auto env = alpaca::Environment();
  if (auto status = env.parse(); !status.ok()) {
    std::cerr << "Error parsing config from environment: " << status.getMessage() << std::endl;
    return status.getCode();
  }

  // Create an API client object
  auto client = alpaca::Client(env);

  // Check if the market is open now.
  auto clock_response = client.getClock();
  if (auto status = clock_response.first; !status.ok()) {
    std::cerr << "Error getting clock information: " << status.getMessage() << std::endl;
    return status.getCode();
  }
  auto clock = clock_response.second;

  if (clock.is_open) {
    std::cout << "The market is open." << std::endl;
  } else {
    std::cout << "The market is closed." << std::endl;
  }

  return 0;
}