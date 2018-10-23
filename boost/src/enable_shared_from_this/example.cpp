#include "example.h"

#include <cassert>

namespace Example {

void enable_shared_from_this_eg() {
    boost::shared_ptr<Y> p(new Y);
    boost::shared_ptr<Y> q = p->f();
    assert(!(p < q || q < p));
}

}
