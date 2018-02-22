#include <fstream>
#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "gen-cpp/FFMPredictor.h"
#include "ffm.h"


using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace ffm;

int main()
{
    boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    FFMPredictorClient client(protocol);
    string val_file_name = "libffm_toy/criteo.va.r100.gbdt0.ffm";

    try
    {
        transport->open();
        client.ping();
        cout << "ping()" << endl;

        int const kMaxLineSize = 1000000;

        FILE *f_in = fopen(val_file_name.c_str(), "r");
        char line[kMaxLineSize];

        vector<Node> x;

        for (int i = 0; fgets(line, kMaxLineSize, f_in) != nullptr && i < 10; i++)
        {
            x.clear();
            char *y_char = strtok(line, " \t");
            ffm_float y = (atoi(y_char) > 0) ? 1.0f : -1.0f;

            cout << "here1" << endl;
            while (true)
            {
                char *field_char = strtok(nullptr, ":");
                char *idx_char = strtok(nullptr, ":");
                char *value_char = strtok(nullptr, " \t");
                if (field_char == nullptr || *field_char == '\n')
                    break;

                Node N;
                N.field = atoi(field_char);
                N.feature = atoi(idx_char);
                N.value = atof(value_char);
                cout << N.field << "\t" << N.feature << "\t" << N.value << endl;

                x.push_back(N);
            }

            cout << "here2" << endl;
            double res = client.predict(x);
            cout << "predict value is : " << res << "true value is :" << y << endl;
        }
        transport->close();
    }
    catch (TException &tx)
    {
        cout << "ERROR: " << tx.what() << endl;
    }
}