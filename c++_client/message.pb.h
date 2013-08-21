// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef PROTOBUF_message_2eproto__INCLUDED
#define PROTOBUF_message_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace example {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_message_2eproto();
void protobuf_AssignDesc_message_2eproto();
void protobuf_ShutdownFile_message_2eproto();

class DataPacket;
class DataPacket_Payload;

// ===================================================================

class DataPacket_Payload : public ::google::protobuf::Message {
 public:
  DataPacket_Payload();
  virtual ~DataPacket_Payload();

  DataPacket_Payload(const DataPacket_Payload& from);

  inline DataPacket_Payload& operator=(const DataPacket_Payload& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DataPacket_Payload& default_instance();

  void Swap(DataPacket_Payload* other);

  // implements Message ----------------------------------------------

  DataPacket_Payload* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DataPacket_Payload& from);
  void MergeFrom(const DataPacket_Payload& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string timestamp = 1;
  inline bool has_timestamp() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  inline const ::std::string& timestamp() const;
  inline void set_timestamp(const ::std::string& value);
  inline void set_timestamp(const char* value);
  inline void set_timestamp(const char* value, size_t size);
  inline ::std::string* mutable_timestamp();
  inline ::std::string* release_timestamp();
  inline void set_allocated_timestamp(::std::string* timestamp);

  // @@protoc_insertion_point(class_scope:example.DataPacket.Payload)
 private:
  inline void set_has_timestamp();
  inline void clear_has_timestamp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* timestamp_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_message_2eproto();
  friend void protobuf_AssignDesc_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

  void InitAsDefaultInstance();
  static DataPacket_Payload* default_instance_;
};
// -------------------------------------------------------------------

class DataPacket : public ::google::protobuf::Message {
 public:
  DataPacket();
  virtual ~DataPacket();

  DataPacket(const DataPacket& from);

  inline DataPacket& operator=(const DataPacket& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DataPacket& default_instance();

  void Swap(DataPacket* other);

  // implements Message ----------------------------------------------

  DataPacket* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DataPacket& from);
  void MergeFrom(const DataPacket& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef DataPacket_Payload Payload;

  // accessors -------------------------------------------------------

  // required int32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:example.DataPacket)
 private:
  inline void set_has_id();
  inline void clear_has_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_message_2eproto();
  friend void protobuf_AssignDesc_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

  void InitAsDefaultInstance();
  static DataPacket* default_instance_;
};
// ===================================================================


// ===================================================================

// DataPacket_Payload

// required string timestamp = 1;
inline bool DataPacket_Payload::has_timestamp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DataPacket_Payload::set_has_timestamp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DataPacket_Payload::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DataPacket_Payload::clear_timestamp() {
  if (timestamp_ != &::google::protobuf::internal::kEmptyString) {
    timestamp_->clear();
  }
  clear_has_timestamp();
}
inline const ::std::string& DataPacket_Payload::timestamp() const {
  return *timestamp_;
}
inline void DataPacket_Payload::set_timestamp(const ::std::string& value) {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  timestamp_->assign(value);
}
inline void DataPacket_Payload::set_timestamp(const char* value) {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  timestamp_->assign(value);
}
inline void DataPacket_Payload::set_timestamp(const char* value, size_t size) {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  timestamp_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* DataPacket_Payload::mutable_timestamp() {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  return timestamp_;
}
inline ::std::string* DataPacket_Payload::release_timestamp() {
  clear_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = timestamp_;
    timestamp_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void DataPacket_Payload::set_allocated_timestamp(::std::string* timestamp) {
  if (timestamp_ != &::google::protobuf::internal::kEmptyString) {
    delete timestamp_;
  }
  if (timestamp) {
    set_has_timestamp();
    timestamp_ = timestamp;
  } else {
    clear_has_timestamp();
    timestamp_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// DataPacket

// required int32 id = 1;
inline bool DataPacket::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DataPacket::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DataPacket::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DataPacket::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 DataPacket::id() const {
  return id_;
}
inline void DataPacket::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace example

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_2eproto__INCLUDED
