CXX = g++
CXXFLAGS = -Wall -O3 -std=c++0x -march=native

# comment the following flags if you do not want to SSE instructions
#DFLAG += -DUSESSE
#THRIFT_DIR = /usr/local/Cellar/thrift/0.9.3/
THRIFT_DIR = /usr/local/Cellar/thrift\@0.9/0.9.3
LIBS = -L${THRIFT_DIR}/lib

# comment the following flags if you do not want to use OpenMP
GEN_CPP = gen-cpp
#DFLAG += -DUSEOMP
#CXXFLAGS += -fopenmp
CXXFLAGS += -I${GEN_CPP} -I${THRIFT_DIR}/include

all: ffm-train ffm-predict ffm-server ffm-client

ffm-train: ffm-train.cpp ffm.o timer.o
	$(CXX) $(CXXFLAGS) $(DFLAG) -o $@ $^

ffm-predict: ffm-predict.cpp ffm.o timer.o
	$(CXX) $(CXXFLAGS) $(DFLAG)  -o $@ $^

ffm-server: ffm-server.cpp ffm.o timer.o FFMPredictor.o  ffm_service_constants.o ffm_service_types.o
	$(CXX) $(CXXFLAGS) $(DFLAG) ${LIBS} -o $@ $^ -lthrift

ffm-client: ffm-client.cpp ffm.o timer.o FFMPredictor.o  ffm_service_constants.o ffm_service_types.o
	$(CXX) $(CXXFLAGS) $(DFLAG) ${LIBS} -o $@ $^ -lthrift

ffm.o: ffm.cpp ffm.h timer.o
	$(CXX) $(CXXFLAGS) $(DFLAG) -c -o $@ $<

timer.o: timer.cpp timer.h
	$(CXX) $(CXXFLAGS) $(DFLAG) -c -o $@ $<

FFMPredictor.o: ${GEN_CPP}/FFMPredictor.cpp ${GEN_CPP}/FFMPredictor.h
	$(CXX) $(CXXFLAGS) $(DFLAG) -c -o $@ $<

ffm_service_constants.o: ${GEN_CPP}/ffm_service_constants.cpp ${GEN_CPP}/ffm_service_constants.h
	$(CXX) $(CXXFLAGS) $(DFLAG) -c -o $@ $<

ffm_service_types.o: ${GEN_CPP}/ffm_service_types.cpp ${GEN_CPP}/ffm_service_types.h
	$(CXX) $(CXXFLAGS) $(DFLAG) -c -o $@ $<

clean:
	rm -f ffm-train ffm-predict ffm-server ffm-client *.o
