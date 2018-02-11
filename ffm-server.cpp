#include "gen-cpp/FFMPredictor.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include "ffm.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace std;
using namespace ffm;

class FFMPredictorHandler : virtual public FFMPredictorIf {
  private:
  ffm_model model;
  public:
    FFMPredictorHandler(string & model_path) {
      //load the ffm model
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
  int port = 9090;
  std::string model_path = "/Users/caonannan/programs/github/libffm/model";
  shared_ptr<FFMPredictorHandler> handler(new FFMPredictorHandler(model_path));
  shared_ptr<TProcessor> processor(new FFMPredictorProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  cout << "server starting ..." << endl;
  return 0;
}