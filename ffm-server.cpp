#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>
#include <thrift/stdcxx.h>

#include "ffm.h"
#include "gen-cpp/ffm_service_types.h"
#include "gen-cpp/FFMPredictor.h"
#include <vector>
#include <iostream>


using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;


using boost::shared_ptr;

using namespace std;
using namespace ffm;

class FFMPredictorHandler : virtual public FFMPredictorIf {
  private:
  ffm_model model;
  public:
    FFMPredictorHandler() {
      //load the ffm model
      string model_path ="/Users/caonannan/programs/github/libffm/model";
      model = ffm_load_model(model_path);
    }

    void ping() {
      printf("ping\n");
    }

    double predict(const std::vector<Node> & features) {
      vector<ffm_node> x;
      x.clear();
      int size = features.size();
      for( int i = 0; i < size; i ++ ) {
        ffm_node N;
        N.f = features[i].field;
        N.j = features[i].feature;
        N.v = features[i].value;

        x.push_back(N);
      }
      ffm_float y_bar = ffm_predict(x.data(), x.data()+x.size(), model);
      printf("predict\n");
      return y_bar;
    }
};

int main(int argc, char **argv) {
  /*
  std::string model_path = "/Users/caonannan/programs/github/libffm/model";
  TThreadedServer server(
    stdcxx::make_shared<FFMPredictorProcessor>(stdcxx::make_shared<FFMPredictorHandler>()),
    stdcxx::make_shared<TServerSocket>(9090), //port
    stdcxx::make_shared<TBufferedTransportFactory>(),
    stdcxx::make_shared<TBinaryProtocolFactory>()); */

  
  // if you don't need per-connection state, do the following instead
  TThreadedServer server(
    stdcxx::make_shared<FFMPredictorProcessor>(stdcxx::make_shared<FFMPredictorHandler>()),
    stdcxx::make_shared<TServerSocket>(9090), //port
    stdcxx::make_shared<TBufferedTransportFactory>(),
    stdcxx::make_shared<TBinaryProtocolFactory>());


  /**
   * Here are some alternate server types...

  // This server only allows one connection at a time, but spawns no threads
  TSimpleServer server(
    stdcxx::make_shared<CalculatorProcessor>(stdcxx::make_shared<CalculatorHandler>()),
    stdcxx::make_shared<TServerSocket>(9090),
    stdcxx::make_shared<TBufferedTransportFactory>(),
    stdcxx::make_shared<TBinaryProtocolFactory>());

  const int workerCount = 4;

  stdcxx::shared_ptr<ThreadManager> threadManager =
    ThreadManager::newSimpleThreadManager(workerCount);
  threadManager->threadFactory(
    stdcxx::make_shared<PlatformThreadFactory>());
  threadManager->start();

  // This server allows "workerCount" connection at a time, and reuses threads
  TThreadPoolServer server(
    stdcxx::make_shared<CalculatorProcessorFactory>(stdcxx::make_shared<CalculatorCloneFactory>()),
    stdcxx::make_shared<TServerSocket>(9090),
    stdcxx::make_shared<TBufferedTransportFactory>(),
    stdcxx::make_shared<TBinaryProtocolFactory>(),
    threadManager);
  */

  cout << "Starting the server..." << endl;
  server.serve();
  cout << "Done." << endl;
  return 0;
}
