// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: look_up_result.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "look_up_result.pb.h"

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

const ::google::protobuf::Descriptor* LookUpRes_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LookUpRes_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_look_5fup_5fresult_2eproto() {
  protobuf_AddDesc_look_5fup_5fresult_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "look_up_result.proto");
  GOOGLE_CHECK(file != NULL);
  LookUpRes_descriptor_ = file->message_type(0);
  static const int LookUpRes_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LookUpRes, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LookUpRes, is_logined_),
  };
  LookUpRes_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      LookUpRes_descriptor_,
      LookUpRes::default_instance_,
      LookUpRes_offsets_,
      -1,
      -1,
      -1,
      sizeof(LookUpRes),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LookUpRes, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LookUpRes, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_look_5fup_5fresult_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      LookUpRes_descriptor_, &LookUpRes::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_look_5fup_5fresult_2eproto() {
  delete LookUpRes::default_instance_;
  delete LookUpRes_reflection_;
}

void protobuf_AddDesc_look_5fup_5fresult_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024look_up_result.proto\022\002IM\"+\n\tLookUpRes\022"
    "\n\n\002id\030\001 \001(\003\022\022\n\nis_logined\030\002 \001(\005b\006proto3", 79);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "look_up_result.proto", &protobuf_RegisterTypes);
  LookUpRes::default_instance_ = new LookUpRes();
  LookUpRes::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_look_5fup_5fresult_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_look_5fup_5fresult_2eproto {
  StaticDescriptorInitializer_look_5fup_5fresult_2eproto() {
    protobuf_AddDesc_look_5fup_5fresult_2eproto();
  }
} static_descriptor_initializer_look_5fup_5fresult_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int LookUpRes::kIdFieldNumber;
const int LookUpRes::kIsLoginedFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

LookUpRes::LookUpRes()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:IM.LookUpRes)
}

void LookUpRes::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

LookUpRes::LookUpRes(const LookUpRes& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:IM.LookUpRes)
}

void LookUpRes::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  id_ = GOOGLE_LONGLONG(0);
  is_logined_ = 0;
}

LookUpRes::~LookUpRes() {
  // @@protoc_insertion_point(destructor:IM.LookUpRes)
  SharedDtor();
}

void LookUpRes::SharedDtor() {
  if (this != default_instance_) {
  }
}

void LookUpRes::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LookUpRes::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LookUpRes_descriptor_;
}

const LookUpRes& LookUpRes::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_look_5fup_5fresult_2eproto();
  return *default_instance_;
}

LookUpRes* LookUpRes::default_instance_ = NULL;

LookUpRes* LookUpRes::New(::google::protobuf::Arena* arena) const {
  LookUpRes* n = new LookUpRes;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void LookUpRes::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<LookUpRes*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(id_, is_logined_);

#undef ZR_HELPER_
#undef ZR_

}

bool LookUpRes::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:IM.LookUpRes)
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
        if (input->ExpectTag(16)) goto parse_is_logined;
        break;
      }

      // optional int32 is_logined = 2;
      case 2: {
        if (tag == 16) {
         parse_is_logined:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &is_logined_)));

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
  // @@protoc_insertion_point(parse_success:IM.LookUpRes)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:IM.LookUpRes)
  return false;
#undef DO_
}

void LookUpRes::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:IM.LookUpRes)
  // optional int64 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->id(), output);
  }

  // optional int32 is_logined = 2;
  if (this->is_logined() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->is_logined(), output);
  }

  // @@protoc_insertion_point(serialize_end:IM.LookUpRes)
}

::google::protobuf::uint8* LookUpRes::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:IM.LookUpRes)
  // optional int64 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->id(), target);
  }

  // optional int32 is_logined = 2;
  if (this->is_logined() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->is_logined(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:IM.LookUpRes)
  return target;
}

int LookUpRes::ByteSize() const {
  int total_size = 0;

  // optional int64 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->id());
  }

  // optional int32 is_logined = 2;
  if (this->is_logined() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->is_logined());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LookUpRes::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const LookUpRes* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const LookUpRes>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LookUpRes::MergeFrom(const LookUpRes& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.is_logined() != 0) {
    set_is_logined(from.is_logined());
  }
}

void LookUpRes::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LookUpRes::CopyFrom(const LookUpRes& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LookUpRes::IsInitialized() const {

  return true;
}

void LookUpRes::Swap(LookUpRes* other) {
  if (other == this) return;
  InternalSwap(other);
}
void LookUpRes::InternalSwap(LookUpRes* other) {
  std::swap(id_, other->id_);
  std::swap(is_logined_, other->is_logined_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata LookUpRes::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LookUpRes_descriptor_;
  metadata.reflection = LookUpRes_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// LookUpRes

// optional int64 id = 1;
void LookUpRes::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
 ::google::protobuf::int64 LookUpRes::id() const {
  // @@protoc_insertion_point(field_get:IM.LookUpRes.id)
  return id_;
}
 void LookUpRes::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:IM.LookUpRes.id)
}

// optional int32 is_logined = 2;
void LookUpRes::clear_is_logined() {
  is_logined_ = 0;
}
 ::google::protobuf::int32 LookUpRes::is_logined() const {
  // @@protoc_insertion_point(field_get:IM.LookUpRes.is_logined)
  return is_logined_;
}
 void LookUpRes::set_is_logined(::google::protobuf::int32 value) {
  
  is_logined_ = value;
  // @@protoc_insertion_point(field_set:IM.LookUpRes.is_logined)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace IM

// @@protoc_insertion_point(global_scope)
