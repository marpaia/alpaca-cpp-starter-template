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

  // Get our account information.
  auto account_response = client.getAccount();
  if (auto status = account_response.first; !status.ok()) {
    std::cerr << "Error getting account information: " << status.getMessage() << std::endl;
    return status.getCode();
  }
  auto account = account_response.second;

  // Check if our account is restricted from trading.
  if (account.trading_blocked) {
    std::cout << "Account is currently restricted from trading." << std::endl;
  }

  // Check how much money we can use to open new positions.
  std::cout << "$" << account.buying_power << " is available as buying power." << std::endl;

  return 0;
}