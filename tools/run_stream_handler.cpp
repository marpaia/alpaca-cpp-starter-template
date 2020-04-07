#include <iostream>

#include "alpaca/config.h"
#include "alpaca/streaming.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;
  FLAGS_minloglevel = 2;

  // Parse the configuration from the environment
  auto env = alpaca::Environment();
  if (auto status = env.parse(); !status.ok()) {
    std::cerr << "Error parsing environment: " << status.getMessage() << std::endl;
    return status.getCode();
  }

  // Log trade updates
  std::function<void(alpaca::stream::DataType data)> on_trade_update = [=](alpaca::stream::DataType data) {
    rapidjson::Document d;
    d.Parse(data.c_str());
    rapidjson::StringBuffer s;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);
    d.Accept(writer);
    std::cout << "Got trade update: " << s.GetString() << std::endl;
  };

  // Log account updates
  std::function<void(alpaca::stream::DataType data)> on_account_update = [=](alpaca::stream::DataType data) {
    rapidjson::Document d;
    d.Parse(data.c_str());
    rapidjson::StringBuffer s;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);
    d.Accept(writer);
    std::cout << "Got account update: " << s.GetString() << std::endl;
  };

  // Create and run the stream handler
  auto handler = alpaca::stream::Handler(on_trade_update, on_account_update);

  std::cout << "Starting the stream handler" << std::endl;
  if (auto status = handler.run(env); !status.ok()) {
    std::cerr << "Error running stream handler: " << status.getMessage() << std::endl;
    return status.getCode();
  }

  return 0;
}
