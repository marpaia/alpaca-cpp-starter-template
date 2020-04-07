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

  // Get a list of all of our positions.
  auto get_positions_response = client.getPositions();
  if (auto status = get_positions_response.first; !status.ok()) {
    std::cerr << "Error getting positions information: " << status.getMessage() << std::endl;
    return status.getCode();
  }
  auto positions = get_positions_response.second;

  // Print a summary of the currently held positions
  std::cout << "Found " << positions.size() << " positions" << std::endl;
  for (const auto& position : positions) {
    std::cout << "  - " << position.qty << " shares in " << position.symbol << " worth $" << position.lastday_price
              << " each / $" << position.market_value << " in total" << std::endl;
  }

  return 0;
}