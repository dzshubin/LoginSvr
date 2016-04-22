// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: validate_result.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "validate_result.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace IM {

namespace {

const ::google::protobuf::Descriptor* DBValidateResult_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DBValidateResult_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_validate_5fresult_2eproto() {
  protobuf_AddDesc_validate_5fresult_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "validate_result.proto");
  GOOGLE_CHECK(file != NULL);
  DBValidateResult_descriptor_ = file->message_type(0);
  static const int DBValidateResult_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DBValidateResult, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DBValidateResult, result_),
  };
  DBValidateResult_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      DBValidateResult_descriptor_,
      DBValidateResult::default_instance_,
      DBValidateResult_offsets_,
      -1,
      -1,
      -1,
      sizeof(DBValidateResult),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DBValidateResult, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DBValidateResult, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_validate_5fresult_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      DBValidateResult_descriptor_, &DBValidateResult::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_validate_5fresult_2eproto() {
  delete DBValidateResult::default_instance_;
  delete DBValidateResult_reflection_;
}

void protobuf_AddDesc_validate_5fresult_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025validate_result.proto\022\002IM\".\n\020DBValidat"
    "eResult\022\n\n\002id\030\001 \001(\003\022\016\n\006result\030\002 \001(\010b\006pro"
    "to3", 83);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "validate_result.proto", &protobuf_RegisterTypes);
  DBValidateResult::default_instance_ = new DBValidateResult();
  DBValidateResult::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_validate_5fresult_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_validate_5fresult_2eproto {
  StaticDescriptorInitializer_validate_5fresult_2eproto() {
    protobuf_AddDesc_validate_5fresult_2eproto();
  }
} static_descriptor_initializer_validate_5fresult_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int DBValidateResult::kIdFieldNumber;
const int DBValidateResult::kResultFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

DBValidateResult::DBValidateResult()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:IM.DBValidateResult)
}

void DBValidateResult::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

DBValidateResult::DBValidateResult(const DBValidateResult& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:IM.DBValidateResult)
}

void DBValidateResult::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  id_ = GOOGLE_LONGLONG(0);
  result_ = false;
}

DBValidateResult::~DBValidateResult() {
  // @@protoc_insertion_point(destructor:IM.DBValidateResult)
  SharedDtor();
}

void DBValidateResult::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DBValidateResult::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DBValidateResult::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DBValidateResult_descriptor_;
}

const DBValidateResult& DBValidateResult::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_validate_5fresult_2eproto();
  return *default_instance_;
}

DBValidateResult* DBValidateResult::default_instance_ = NULL;

DBValidateResult* DBValidateResult::New(::google::protobuf::Arena* arena) const {
  DBValidateResult* n = new DBValidateResult;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void DBValidateResult::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<DBValidateResult*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(id_, result_);

#undef ZR_HELPER_
#undef ZR_

}

bool DBValidateResult::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:IM.DBValidateResult)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_result;
        break;
      }

      // optional bool result = 2;
      case 2: {
        if (tag == 16) {
         parse_result:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &result_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:IM.DBValidateResult)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:IM.DBValidateResult)
  return false;
#undef DO_
}

void DBValidateResult::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:IM.DBValidateResult)
  // optional int64 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->id(), output);
  }

  // optional bool result = 2;
  if (this->result() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->result(), output);
  }

  // @@protoc_insertion_point(serialize_end:IM.DBValidateResult)
}

::google::protobuf::uint8* DBValidateResult::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:IM.DBValidateResult)
  // optional int64 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->id(), target);
  }

  // optional bool result = 2;
  if (this->result() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->result(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:IM.DBValidateResult)
  return target;
}

int DBValidateResult::ByteSize() const {
  int total_size = 0;

  // optional int64 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->id());
  }

  // optional bool result = 2;
  if (this->result() != 0) {
    total_size += 1 + 1;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DBValidateResult::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const DBValidateResult* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const DBValidateResult>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DBValidateResult::MergeFrom(const DBValidateResult& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.result() != 0) {
    set_result(from.result());
  }
}

void DBValidateResult::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DBValidateResult::CopyFrom(const DBValidateResult& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DBValidateResult::IsInitialized() const {

  return true;
}

void DBValidateResult::Swap(DBValidateResult* other) {
  if (other == this) return;
  InternalSwap(other);
}
void DBValidateResult::InternalSwap(DBValidateResult* other) {
  std::swap(id_, other->id_);
  std::swap(result_, other->result_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata DBValidateResult::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DBValidateResult_descriptor_;
  metadata.reflection = DBValidateResult_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// DBValidateResult

// optional int64 id = 1;
void DBValidateResult::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
 ::google::protobuf::int64 DBValidateResult::id() const {
  // @@protoc_insertion_point(field_get:IM.DBValidateResult.id)
  return id_;
}
 void DBValidateResult::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:IM.DBValidateResult.id)
}

// optional bool result = 2;
void DBValidateResult::clear_result() {
  result_ = false;
}
 bool DBValidateResult::result() const {
  // @@protoc_insertion_point(field_get:IM.DBValidateResult.result)
  return result_;
}
 void DBValidateResult::set_result(bool value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:IM.DBValidateResult.result)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace IM

// @@protoc_insertion_point(global_scope)