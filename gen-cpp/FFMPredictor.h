/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef FFMPredictor_H
#define FFMPredictor_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "ffm_service_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class FFMPredictorIf {
 public:
  virtual ~FFMPredictorIf() {}
  virtual void ping() = 0;
  virtual double predict(const std::vector<Node> & features) = 0;
};

class FFMPredictorIfFactory {
 public:
  typedef FFMPredictorIf Handler;

  virtual ~FFMPredictorIfFactory() {}

  virtual FFMPredictorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(FFMPredictorIf* /* handler */) = 0;
};

class FFMPredictorIfSingletonFactory : virtual public FFMPredictorIfFactory {
 public:
  FFMPredictorIfSingletonFactory(const boost::shared_ptr<FFMPredictorIf>& iface) : iface_(iface) {}
  virtual ~FFMPredictorIfSingletonFactory() {}

  virtual FFMPredictorIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(FFMPredictorIf* /* handler */) {}

 protected:
  boost::shared_ptr<FFMPredictorIf> iface_;
};

class FFMPredictorNull : virtual public FFMPredictorIf {
 public:
  virtual ~FFMPredictorNull() {}
  void ping() {
    return;
  }
  double predict(const std::vector<Node> & /* features */) {
    double _return = (double)0;
    return _return;
  }
};


class FFMPredictor_ping_args {
 public:

  FFMPredictor_ping_args(const FFMPredictor_ping_args&);
  FFMPredictor_ping_args& operator=(const FFMPredictor_ping_args&);
  FFMPredictor_ping_args() {
  }

  virtual ~FFMPredictor_ping_args() throw();

  bool operator == (const FFMPredictor_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const FFMPredictor_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FFMPredictor_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FFMPredictor_ping_pargs {
 public:


  virtual ~FFMPredictor_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FFMPredictor_ping_result {
 public:

  FFMPredictor_ping_result(const FFMPredictor_ping_result&);
  FFMPredictor_ping_result& operator=(const FFMPredictor_ping_result&);
  FFMPredictor_ping_result() {
  }

  virtual ~FFMPredictor_ping_result() throw();

  bool operator == (const FFMPredictor_ping_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const FFMPredictor_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FFMPredictor_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FFMPredictor_ping_presult {
 public:


  virtual ~FFMPredictor_ping_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FFMPredictor_predict_args__isset {
  _FFMPredictor_predict_args__isset() : features(false) {}
  bool features :1;
} _FFMPredictor_predict_args__isset;

class FFMPredictor_predict_args {
 public:

  FFMPredictor_predict_args(const FFMPredictor_predict_args&);
  FFMPredictor_predict_args& operator=(const FFMPredictor_predict_args&);
  FFMPredictor_predict_args() {
  }

  virtual ~FFMPredictor_predict_args() throw();
  std::vector<Node>  features;

  _FFMPredictor_predict_args__isset __isset;

  void __set_features(const std::vector<Node> & val);

  bool operator == (const FFMPredictor_predict_args & rhs) const
  {
    if (!(features == rhs.features))
      return false;
    return true;
  }
  bool operator != (const FFMPredictor_predict_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FFMPredictor_predict_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FFMPredictor_predict_pargs {
 public:


  virtual ~FFMPredictor_predict_pargs() throw();
  const std::vector<Node> * features;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FFMPredictor_predict_result__isset {
  _FFMPredictor_predict_result__isset() : success(false) {}
  bool success :1;
} _FFMPredictor_predict_result__isset;

class FFMPredictor_predict_result {
 public:

  FFMPredictor_predict_result(const FFMPredictor_predict_result&);
  FFMPredictor_predict_result& operator=(const FFMPredictor_predict_result&);
  FFMPredictor_predict_result() : success(0) {
  }

  virtual ~FFMPredictor_predict_result() throw();
  double success;

  _FFMPredictor_predict_result__isset __isset;

  void __set_success(const double val);

  bool operator == (const FFMPredictor_predict_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FFMPredictor_predict_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FFMPredictor_predict_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FFMPredictor_predict_presult__isset {
  _FFMPredictor_predict_presult__isset() : success(false) {}
  bool success :1;
} _FFMPredictor_predict_presult__isset;

class FFMPredictor_predict_presult {
 public:


  virtual ~FFMPredictor_predict_presult() throw();
  double* success;

  _FFMPredictor_predict_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class FFMPredictorClient : virtual public FFMPredictorIf {
 public:
  FFMPredictorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  FFMPredictorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  void send_ping();
  void recv_ping();
  double predict(const std::vector<Node> & features);
  void send_predict(const std::vector<Node> & features);
  double recv_predict();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class FFMPredictorProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<FFMPredictorIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (FFMPredictorProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_predict(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  FFMPredictorProcessor(boost::shared_ptr<FFMPredictorIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &FFMPredictorProcessor::process_ping;
    processMap_["predict"] = &FFMPredictorProcessor::process_predict;
  }

  virtual ~FFMPredictorProcessor() {}
};

class FFMPredictorProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  FFMPredictorProcessorFactory(const ::boost::shared_ptr< FFMPredictorIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< FFMPredictorIfFactory > handlerFactory_;
};

class FFMPredictorMultiface : virtual public FFMPredictorIf {
 public:
  FFMPredictorMultiface(std::vector<boost::shared_ptr<FFMPredictorIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~FFMPredictorMultiface() {}
 protected:
  std::vector<boost::shared_ptr<FFMPredictorIf> > ifaces_;
  FFMPredictorMultiface() {}
  void add(boost::shared_ptr<FFMPredictorIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping();
    }
    ifaces_[i]->ping();
  }

  double predict(const std::vector<Node> & features) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->predict(features);
    }
    return ifaces_[i]->predict(features);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class FFMPredictorConcurrentClient : virtual public FFMPredictorIf {
 public:
  FFMPredictorConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  FFMPredictorConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  int32_t send_ping();
  void recv_ping(const int32_t seqid);
  double predict(const std::vector<Node> & features);
  int32_t send_predict(const std::vector<Node> & features);
  double recv_predict(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif
