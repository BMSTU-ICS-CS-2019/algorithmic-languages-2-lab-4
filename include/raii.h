#ifndef INCLUDE_RAII_H_
#define INCLUDE_RAII_H_

namespace raii {

    class RaiiUnfriendly final {

        int * const unsafePointer_ = new int;

    public:
        // this should happen to (badly) deallocate memory
        int const * unsafePointer() const;

        [[nodiscard]] int value();
    };

    class RaiiFriendly final {

        int * safePointer_;

    public:

        RaiiFriendly();

        RaiiFriendly(RaiiFriendly const &);

        RaiiFriendly(RaiiFriendly &&) noexcept;

        RaiiFriendly & operator=(RaiiFriendly const &);

        RaiiFriendly & operator=(RaiiFriendly &&) noexcept;

        ~RaiiFriendly() noexcept;

        [[nodiscard]] int value();
    };
} // namespace raii

#endif // INCLUDE_RAII_H_
