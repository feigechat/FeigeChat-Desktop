// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CIM.Friend.proto

#include "CIM.Friend.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace CIM {
namespace Friend {
constexpr CIMFriendQueryUserListReq::CIMFriendQueryUserListReq(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : user_id_(PROTOBUF_ULONGLONG(0)){}
struct CIMFriendQueryUserListReqDefaultTypeInternal {
  constexpr CIMFriendQueryUserListReqDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CIMFriendQueryUserListReqDefaultTypeInternal() {}
  union {
    CIMFriendQueryUserListReq _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CIMFriendQueryUserListReqDefaultTypeInternal _CIMFriendQueryUserListReq_default_instance_;
constexpr CIMFriendQueryUserListRsp::CIMFriendQueryUserListRsp(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : user_info_list_()
  , user_id_(PROTOBUF_ULONGLONG(0)){}
struct CIMFriendQueryUserListRspDefaultTypeInternal {
  constexpr CIMFriendQueryUserListRspDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CIMFriendQueryUserListRspDefaultTypeInternal() {}
  union {
    CIMFriendQueryUserListRsp _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CIMFriendQueryUserListRspDefaultTypeInternal _CIMFriendQueryUserListRsp_default_instance_;
}  // namespace Friend
}  // namespace CIM
namespace CIM {
namespace Friend {

// ===================================================================

class CIMFriendQueryUserListReq::_Internal {
 public:
};

CIMFriendQueryUserListReq::CIMFriendQueryUserListReq(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:CIM.Friend.CIMFriendQueryUserListReq)
}
CIMFriendQueryUserListReq::CIMFriendQueryUserListReq(const CIMFriendQueryUserListReq& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  user_id_ = from.user_id_;
  // @@protoc_insertion_point(copy_constructor:CIM.Friend.CIMFriendQueryUserListReq)
}

void CIMFriendQueryUserListReq::SharedCtor() {
user_id_ = PROTOBUF_ULONGLONG(0);
}

CIMFriendQueryUserListReq::~CIMFriendQueryUserListReq() {
  // @@protoc_insertion_point(destructor:CIM.Friend.CIMFriendQueryUserListReq)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void CIMFriendQueryUserListReq::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void CIMFriendQueryUserListReq::ArenaDtor(void* object) {
  CIMFriendQueryUserListReq* _this = reinterpret_cast< CIMFriendQueryUserListReq* >(object);
  (void)_this;
}
void CIMFriendQueryUserListReq::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CIMFriendQueryUserListReq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CIMFriendQueryUserListReq::Clear() {
// @@protoc_insertion_point(message_clear_start:CIM.Friend.CIMFriendQueryUserListReq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  user_id_ = PROTOBUF_ULONGLONG(0);
  _internal_metadata_.Clear<std::string>();
}

const char* CIMFriendQueryUserListReq::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint64 user_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CIMFriendQueryUserListReq::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CIM.Friend.CIMFriendQueryUserListReq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 user_id = 1;
  if (this->user_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_user_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CIM.Friend.CIMFriendQueryUserListReq)
  return target;
}

size_t CIMFriendQueryUserListReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CIM.Friend.CIMFriendQueryUserListReq)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint64 user_id = 1;
  if (this->user_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_user_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CIMFriendQueryUserListReq::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const CIMFriendQueryUserListReq*>(
      &from));
}

void CIMFriendQueryUserListReq::MergeFrom(const CIMFriendQueryUserListReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CIM.Friend.CIMFriendQueryUserListReq)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.user_id() != 0) {
    _internal_set_user_id(from._internal_user_id());
  }
}

void CIMFriendQueryUserListReq::CopyFrom(const CIMFriendQueryUserListReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CIM.Friend.CIMFriendQueryUserListReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CIMFriendQueryUserListReq::IsInitialized() const {
  return true;
}

void CIMFriendQueryUserListReq::InternalSwap(CIMFriendQueryUserListReq* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(user_id_, other->user_id_);
}

std::string CIMFriendQueryUserListReq::GetTypeName() const {
  return "CIM.Friend.CIMFriendQueryUserListReq";
}


// ===================================================================

class CIMFriendQueryUserListRsp::_Internal {
 public:
};

void CIMFriendQueryUserListRsp::clear_user_info_list() {
  user_info_list_.Clear();
}
CIMFriendQueryUserListRsp::CIMFriendQueryUserListRsp(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena),
  user_info_list_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:CIM.Friend.CIMFriendQueryUserListRsp)
}
CIMFriendQueryUserListRsp::CIMFriendQueryUserListRsp(const CIMFriendQueryUserListRsp& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      user_info_list_(from.user_info_list_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  user_id_ = from.user_id_;
  // @@protoc_insertion_point(copy_constructor:CIM.Friend.CIMFriendQueryUserListRsp)
}

void CIMFriendQueryUserListRsp::SharedCtor() {
user_id_ = PROTOBUF_ULONGLONG(0);
}

CIMFriendQueryUserListRsp::~CIMFriendQueryUserListRsp() {
  // @@protoc_insertion_point(destructor:CIM.Friend.CIMFriendQueryUserListRsp)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void CIMFriendQueryUserListRsp::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void CIMFriendQueryUserListRsp::ArenaDtor(void* object) {
  CIMFriendQueryUserListRsp* _this = reinterpret_cast< CIMFriendQueryUserListRsp* >(object);
  (void)_this;
}
void CIMFriendQueryUserListRsp::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CIMFriendQueryUserListRsp::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CIMFriendQueryUserListRsp::Clear() {
// @@protoc_insertion_point(message_clear_start:CIM.Friend.CIMFriendQueryUserListRsp)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  user_info_list_.Clear();
  user_id_ = PROTOBUF_ULONGLONG(0);
  _internal_metadata_.Clear<std::string>();
}

const char* CIMFriendQueryUserListRsp::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint64 user_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .CIM.Def.CIMUserInfo user_info_list = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_user_info_list(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CIMFriendQueryUserListRsp::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CIM.Friend.CIMFriendQueryUserListRsp)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 user_id = 1;
  if (this->user_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_user_id(), target);
  }

  // repeated .CIM.Def.CIMUserInfo user_info_list = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_user_info_list_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_user_info_list(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CIM.Friend.CIMFriendQueryUserListRsp)
  return target;
}

size_t CIMFriendQueryUserListRsp::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CIM.Friend.CIMFriendQueryUserListRsp)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .CIM.Def.CIMUserInfo user_info_list = 2;
  total_size += 1UL * this->_internal_user_info_list_size();
  for (const auto& msg : this->user_info_list_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // uint64 user_id = 1;
  if (this->user_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_user_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CIMFriendQueryUserListRsp::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const CIMFriendQueryUserListRsp*>(
      &from));
}

void CIMFriendQueryUserListRsp::MergeFrom(const CIMFriendQueryUserListRsp& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CIM.Friend.CIMFriendQueryUserListRsp)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  user_info_list_.MergeFrom(from.user_info_list_);
  if (from.user_id() != 0) {
    _internal_set_user_id(from._internal_user_id());
  }
}

void CIMFriendQueryUserListRsp::CopyFrom(const CIMFriendQueryUserListRsp& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CIM.Friend.CIMFriendQueryUserListRsp)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CIMFriendQueryUserListRsp::IsInitialized() const {
  return true;
}

void CIMFriendQueryUserListRsp::InternalSwap(CIMFriendQueryUserListRsp* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  user_info_list_.InternalSwap(&other->user_info_list_);
  swap(user_id_, other->user_id_);
}

std::string CIMFriendQueryUserListRsp::GetTypeName() const {
  return "CIM.Friend.CIMFriendQueryUserListRsp";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Friend
}  // namespace CIM
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::CIM::Friend::CIMFriendQueryUserListReq* Arena::CreateMaybeMessage< ::CIM::Friend::CIMFriendQueryUserListReq >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CIM::Friend::CIMFriendQueryUserListReq >(arena);
}
template<> PROTOBUF_NOINLINE ::CIM::Friend::CIMFriendQueryUserListRsp* Arena::CreateMaybeMessage< ::CIM::Friend::CIMFriendQueryUserListRsp >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CIM::Friend::CIMFriendQueryUserListRsp >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>