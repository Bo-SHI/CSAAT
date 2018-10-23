#ifndef __ENABLE_SHARED_FROM_THIS_EXAMPLE_H__
#define __ENABLE_SHARED_FROM_THIS_EXAMPLE_H__

#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

namespace Example {

class Y : public boost::enable_shared_from_this<Y> {
public:
    boost::shared_ptr<Y> f() {
        return shared_from_this();
    }
};

void enable_shared_from_this_eg();

}

#endif
