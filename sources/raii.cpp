//#include <raii.h">

#include <algorithm>
#include <raii.h>
#include <utility>

int const * raii::RaiiUnfriendly::unsafePointer() const {
    return nullptr;
}

int raii::RaiiUnfriendly::value() {
    return *unsafePointer_;
}

raii::RaiiFriendly::RaiiFriendly() : safePointer_(new int) {}

raii::RaiiFriendly::RaiiFriendly(raii::RaiiFriendly const & original) : RaiiFriendly() {
    *safePointer_ = *original.safePointer_;
}

raii::RaiiFriendly::RaiiFriendly(raii::RaiiFriendly && original) noexcept
    : safePointer_(std::exchange(original.safePointer_, nullptr)) {}

raii::RaiiFriendly & raii::RaiiFriendly::operator=(raii::RaiiFriendly const & original) {
    if (this != &original) *safePointer_ = *original.safePointer_;

    return *this;
}

raii::RaiiFriendly & raii::RaiiFriendly::operator=(raii::RaiiFriendly && original) noexcept {
    std::swap(safePointer_, this->safePointer_);

    return *this;
}

raii::RaiiFriendly::~RaiiFriendly() noexcept { delete safePointer_; }

int raii::RaiiFriendly::value() {
    return *safePointer_;
}
