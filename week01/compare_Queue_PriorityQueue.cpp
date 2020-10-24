priority_queue 默认的Container 是vector   多了一个Compare的类
quene          默认的Container 是Deque


Synopsis
#include <compare>
#include <initializer_list>

namespace std {
    template<class T, class Container = deque<T>> class queue;

    template<class T, class Container>
    bool operator==(const queue<T, Container>& x, const queue<T, Container>& y);
    template<class T, class Container>
    bool operator!=(const queue<T, Container>& x, const queue<T, Container>& y);
    template<class T, class Container>
    bool operator< (const queue<T, Container>& x, const queue<T, Container>& y);
    template<class T, class Container>
    bool operator> (const queue<T, Container>& x, const queue<T, Container>& y);
    template<class T, class Container>
    bool operator<=(const queue<T, Container>& x, const queue<T, Container>& y);
    template<class T, class Container>
    bool operator>=(const queue<T, Container>& x, const queue<T, Container>& y);
    template<class T, three_way_comparable Container>
    compare_three_way_result_t<Container>
            operator<=>(const queue<T, Container>& x, const queue<T, Container>& y);

    template<class T, class Container>
    void swap(queue<T, Container>& x, queue<T, Container>& y)
    noexcept(noexcept(x.swap(y)));
    template<class T, class Container, class Alloc>
    struct uses_allocator<queue<T, Container>, Alloc>;

    template<class T, class Container = vector<T>,
            class Compare = less<typename Container::value_type>>
    class priority_queue;

    template<class T, class Container, class Compare>
    void swap(priority_queue<T, Container, Compare>& x,
              priority_queue<T, Container, Compare>& y) noexcept(noexcept(x.swap(y)));
    template<class T, class Container, class Compare, class Alloc>
    struct uses_allocator<priority_queue<T, Container, Compare>, Alloc>;
}
Class template std::queue
namespace std {
    template<class T, class Container = deque<T>>
    class queue {
    public:
        using value_type      = typename Container::value_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using size_type       = typename Container::size_type;
        using container_type  =          Container;

    protected:
        Container c;

    public:
        queue() : queue(Container()) {}
        explicit queue(const Container&);
        explicit queue(Container&&);
        template<class Alloc> explicit queue(const Alloc&);
        template<class Alloc> queue(const Container&, const Alloc&);
        template<class Alloc> queue(Container&&, const Alloc&);
        template<class Alloc> queue(const queue&, const Alloc&);
        template<class Alloc> queue(queue&&, const Alloc&);

        [[nodiscard]] bool empty() const    { return c.empty(); }
        size_type         size()  const     { return c.size(); }
        reference         front()           { return c.front(); }
        const_reference   front() const     { return c.front(); }
        reference         back()            { return c.back(); }
        const_reference   back() const      { return c.back(); }
        void push(const value_type& x)      { c.push_back(x); }
        void push(value_type&& x)           { c.push_back(std::move(x)); }
        template<class... Args>
        decltype(auto) emplace(Args&&... args)
        { return c.emplace_back(std::forward<Args>(args)...); }
        void pop()                          { c.pop_front(); }
        void swap(queue& q) noexcept(is_nothrow_swappable_v<Container>)
        { using std::swap; swap(c, q.c); }
    };

    template<class Container>
    queue(Container) -> queue<typename Container::value_type, Container>;

    template<class Container, class Allocator>
    queue(Container, Allocator) -> queue<typename Container::value_type, Container>;

    template<class T, class Container>
    void swap(queue<T, Container>& x, queue<T, Container>& y)
    noexcept(noexcept(x.swap(y)));

    template<class T, class Container, class Alloc>
    struct uses_allocator<queue<T, Container>, Alloc>
            : uses_allocator<Container, Alloc>::type { };
}
Class template std::priority_queue
namespace std {
    template<class T, class Container = vector<T>,
            class Compare = less<typename Container::value_type>>
    class priority_queue {
    public:
        using value_type      = typename Container::value_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using size_type       = typename Container::size_type;
        using container_type  = Container;
        using value_compare   = Compare;

    protected:
        Container c;
        Compare comp;

    public:
        priority_queue() : priority_queue(Compare()) {}
        explicit priority_queue(const Compare& x) : priority_queue(x, Container()) {}
        priority_queue(const Compare& x, const Container&);
        priority_queue(const Compare& x, Container&&);
        template<class InputIt>
        priority_queue(InputIt first, InputIt last, const Compare& x,
                       const Container&);
        template<class InputIt>
        priority_queue(InputIt first, InputIt last,
                       const Compare& x = Compare(), Container&& = Container());
        template<class Alloc> explicit priority_queue(const Alloc&);
        template<class Alloc> priority_queue(const Compare&, const Alloc&);
        template<class Alloc> priority_queue(const Compare&, const Container&, const Alloc&);
        template<class Alloc> priority_queue(const Compare&, Container&&, const Alloc&);
        template<class Alloc> priority_queue(const priority_queue&, const Alloc&);
        template<class Alloc> priority_queue(priority_queue&&, const Alloc&);

        [[nodiscard]] bool empty() const { return c.empty(); }
        size_type size()  const          { return c.size(); }
        const_reference   top() const    { return c.front(); }
        void push(const value_type& x);
        void push(value_type&& x);
        template<class... Args> void emplace(Args&&... args);
        void pop();
        void swap(priority_queue& q) noexcept(is_nothrow_swappable_v<Container> &&
                                              is_nothrow_swappable_v<Compare>)
        { using std::swap; swap(c, q.c); swap(comp, q.comp); }
    };

    template<class Compare, class Container>
    priority_queue(Compare, Container)
    -> priority_queue<typename Container::value_type, Container, Compare>;

    template<class InputIt,
            class Compare = less<typename iterator_traits<InputIt>::value_type>,
            class Container = vector<typename iterator_traits<InputIt>::value_type>>
    priority_queue(InputIt, InputIt, Compare = Compare(), Container = Container())
    -> priority_queue<typename iterator_traits<InputIt>::value_type, Container, Compare>;

    template<class Compare, class Container, class Allocator>
    priority_queue(Compare, Container, Allocator)
    -> priority_queue<typename Container::value_type, Container, Compare>;

    // no equality is provided

    template<class T, class Container, class Compare>
    void swap(priority_queue<T, Container, Compare>& x,
              priority_queue<T, Container, Compare>& y) noexcept(noexcept(x.swap(y)));

    template<class T, class Container, class Compare, class Alloc>
    struct uses_allocator<priority_queue<T, Container, Compare>, Alloc>
            : uses_allocator<Container, Alloc>::type { };
}