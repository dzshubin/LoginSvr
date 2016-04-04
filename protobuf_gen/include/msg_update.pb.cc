// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_update.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "msg_update.pb.h"

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

const ::google::protobuf::Descriptor* Update_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Update_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_msg_5fupdate_2eproto() {
  protobuf_AddDesc_msg_5fupdate_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "msg_update.proto");
  GOOGLE_CHECK(file != NULL);
  Update_descriptor_ = file->message_type(0);
  static const int Update_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Update, count_),
  };
  Update_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Update_descriptor_,
      Update::default_instance_,
      Update_offsets_,
      -1,
      -1,
      -1,
      sizeof(Update),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Update, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Update, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_msg_5fupdate_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Update_descriptor_, &Update::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_msg_5fupdate_2eproto() {
  delete Update::default_instance_;
  delete Update_reflection_;
}

void protobuf_AddDesc_msg_5fupdate_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020msg_update.proto\022\002IM\"\027\n\006Update\022\r\n\005coun"
    "t\030\001 \001(\005b\006proto3", 55);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "msg_update.proto", &protobuf_RegisterTypes);
  Update::default_instance_ = new Update();
  Update::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_msg_5fupdate_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_msg_5fupdate_2eproto {
  StaticDescriptorInitializer_msg_5fupdate_2eproto() {
    protobuf_AddDesc_msg_5fupdate_2eproto();
  }
} static_descriptor_initializer_msg_5fupdate_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Update::kCountFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Update::Update()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:IM.Update)
}

void Update::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Update::Update(const Update& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:IM.Update)
}

void Update::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  count_ = 0;
}

Update::~Update() {
  // @@protoc_insertion_point(destructor:IM.Update)
  SharedDtor();
}

void Update::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Update::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Update::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Update_descriptor_;
}

const Update& Update::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_msg_5fupdate_2eproto();
  return *default_instance_;
}

Update* Update::default_instance_ = NULL;

Update* Update::New(::google::protobuf::Arena* arena) const {
  Update* n = new Update;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Update::Clear() {
  count_ = 0;
}

bool Update::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:IM.Update)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 count = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &count_)));

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
  // @@protoc_insertion_point(parse_success:IM.Update)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:IM.Update)
  return false;
#undef DO_
}

void Update::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:IM.Update)
  // optional int32 count = 1;
  if (this->count() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->count(), output);
  }

  // @@protoc_insertion_point(serialize_end:IM.Update)
}

::google::protobuf::uint8* Update::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:IM.Update)
  // optional int32 count = 1;
  if (this->count() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->count(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:IM.Update)
  return target;
}

int Update::ByteSize() const {
  int total_size = 0;

  // optional int32 count = 1;
  if (this->count() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->count());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Update::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Update* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Update>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Update::MergeFrom(const Update& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.count() != 0) {
    set_count(from.count());
  }
}

void Update::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Update::CopyFrom(const Update& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Update::IsInitialized() const {

  return true;
}

void Update::Swap(Update* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Update::InternalSwap(Update* other) {
  std::swap(count_, other->count_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Update::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Update_descriptor_;
  metadata.reflection = Update_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Update

// optional int32 count = 1;
void Update::clear_count() {
  count_ = 0;
}
 ::google::protobuf::int32 Update::count() const {
  // @@protoc_insertion_point(field_get:IM.Update.count)
  return count_;
}
 void Update::set_count(::google::protobuf::int32 value) {
  
  count_ = value;
  // @@protoc_insertion_point(field_set:IM.Update.count)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace IM

// @@protoc_insertion_point(global_scope)
