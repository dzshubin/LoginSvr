// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: look_up_result.proto

#ifndef PROTOBUF_look_5fup_5fresult_2eproto__INCLUDED
#define PROTOBUF_look_5fup_5fresult_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace IM {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_look_5fup_5fresult_2eproto();
void protobuf_AssignDesc_look_5fup_5fresult_2eproto();
void protobuf_ShutdownFile_look_5fup_5fresult_2eproto();

class LookUpRes;

// ===================================================================

class LookUpRes : public ::google::protobuf::Message {
 public:
  LookUpRes();
  virtual ~LookUpRes();

  LookUpRes(const LookUpRes& from);

  inline LookUpRes& operator=(const LookUpRes& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LookUpRes& default_instance();

  void Swap(LookUpRes* other);

  // implements Message ----------------------------------------------

  inline LookUpRes* New() const { return New(NULL); }

  LookUpRes* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LookUpRes& from);
  void MergeFrom(const LookUpRes& from);
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
  void InternalSwap(LookUpRes* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // optional int32 is_logined = 2;
  void clear_is_logined();
  static const int kIsLoginedFieldNumber = 2;
  ::google::protobuf::int32 is_logined() const;
  void set_is_logined(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:IM.LookUpRes)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int64 id_;
  ::google::protobuf::int32 is_logined_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_look_5fup_5fresult_2eproto();
  friend void protobuf_AssignDesc_look_5fup_5fresult_2eproto();
  friend void protobuf_ShutdownFile_look_5fup_5fresult_2eproto();

  void InitAsDefaultInstance();
  static LookUpRes* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// LookUpRes

// optional int64 id = 1;
inline void LookUpRes::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 LookUpRes::id() const {
  // @@protoc_insertion_point(field_get:IM.LookUpRes.id)
  return id_;
}
inline void LookUpRes::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:IM.LookUpRes.id)
}

// optional int32 is_logined = 2;
inline void LookUpRes::clear_is_logined() {
  is_logined_ = 0;
}
inline ::google::protobuf::int32 LookUpRes::is_logined() const {
  // @@protoc_insertion_point(field_get:IM.LookUpRes.is_logined)
  return is_logined_;
}
inline void LookUpRes::set_is_logined(::google::protobuf::int32 value) {
  
  is_logined_ = value;
  // @@protoc_insertion_point(field_set:IM.LookUpRes.is_logined)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace IM

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_look_5fup_5fresult_2eproto__INCLUDED
