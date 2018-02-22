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

#include <boost/make_shared.hpp>

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "ffm.h"
#include "gen-cpp/ffm_service_types.h"
#include "gen-cpp/FFMPredictor.h"
#include <vector>
#include <iostream>
using boost::shared_ptr;

using namespace std;
using namespace ffm;

using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

class FFMPredictorHandler : virtual public FFMPredictorIf {
  private:
  ffm_model model;
  vector<ffm_node> x;
  
  public:
    FFMPredictorHandler() {
      //load the ffm model
      string model_path ="/Users/caonannan/programs/github/libffm/model";
      model = ffm_load_model(model_path);
      cout << "Model loaded !" << endl;
    }

    void ping() {
      printf("ping\n");
    }

    double predict(const std::vector<Node> & features) {
      x.clear();
      int size = features.size();
      for( int i = 0; i < size; i ++ ) {
        ffm_node N;
        N.f = features[i].field;
        N.j = features[i].feature;
        N.v = features[i].value;
        cout << N.f << "\t" << N.j << "\t" << N.v << endl;

        x.push_back(N);
      }
      printf("predict started\n");
      ffm_float y_bar = ffm_predict(x.data(), x.data()+x.size(), model);
      printf("predict finished\n");
      return y_bar;
    }
};

int main(int argc, char **argv) {
	/*
  TThreadedServer server(
    boost::make_shared<FFMPredictorProcessorFactory>(boost::make_shared<FFMPredictorCloneFactory>()),
    boost::make_shared<TServerSocket>(9090), //port
    boost::make_shared<TBufferedTransportFactory>(),
    boost::make_shared<TBinaryProtocolFactory>()); */

  // if you don't need per-connection state, do the following instead
  TThreadedServer server(
    boost::make_shared<FFMPredictorProcessor>(boost::make_shared<FFMPredictorHandler>()),
    boost::make_shared<TServerSocket>(9090), //port
    boost::make_shared<TBufferedTransportFactory>(),
    boost::make_shared<TBinaryProtocolFactory>());

  /**
   * Here are some alternate server types...

  // This server only allows one connection at a time, but spawns no threads
  TSimpleServer server(
    boost::make_shared<FFMPredictorProcessor>(boost::make_shared<FFMPredictorHandler>()),
    boost::make_shared<TServerSocket>(9090),
    boost::make_shared<TBufferedTransportFactory>(),
    boost::make_shared<TBinaryProtocolFactory>());

  const int workerCount = 4;

  boost::shared_ptr<ThreadManager> threadManager =
    ThreadManager::newSimpleThreadManager(workerCount);
  threadManager->threadFactory(
    boost::make_shared<PlatformThreadFactory>());
  threadManager->start();

  // This server allows "workerCount" connection at a time, and reuses threads
  TThreadPoolServer server(
    boost::make_shared<FFMPredictorProcessorFactory>(boost::make_shared<FFMPredictorCloneFactory>()),
    boost::make_shared<TServerSocket>(9090),
    boost::make_shared<TBufferedTransportFactory>(),
    boost::make_shared<TBinaryProtocolFactory>(),
    threadManager);
  */

  cout << "Starting the server..." << endl;
  server.serve();
  cout << "Done." << endl;
  return 0;
}
