/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ffm-service_TYPES_H
#define ffm-service_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




class Node;

typedef struct _Node__isset {
  _Node__isset() : field(true), feature(true), value(true) {}
  bool field :1;
  bool feature :1;
  bool value :1;
} _Node__isset;

class Node {
 public:

  Node(const Node&);
  Node& operator=(const Node&);
  Node() : field(0), feature(1), value(2) {
  }

  virtual ~Node() throw();
  int32_t field;
  int32_t feature;
  double value;

  _Node__isset __isset;

  void __set_field(const int32_t val);

  void __set_feature(const int32_t val);

  void __set_value(const double val);

  bool operator == (const Node & rhs) const
  {
    if (!(field == rhs.field))
      return false;
    if (!(feature == rhs.feature))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Node &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Node & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Node &a, Node &b);

inline std::ostream& operator<<(std::ostream& out, const Node& obj)
{
  obj.printTo(out);
  return out;
}



#endif