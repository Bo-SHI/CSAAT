#include <iostream>
#include <vector>

struct item {
    int uuid;
    int itemid;
    int num;
    bool bind;
};

typedef std::vector<item> items;

items cost(items bind, items un_bind, int n) {
    static const int uuid = 1;
    static const int cfg_item_num = 7;

    items del;
    int total = cfg_item_num * n;
    int bind_num = 0;
    int extra = 0;
    for (auto it = bind.begin(); it != bind.end(); ++it) {
        auto v = *it;
        int t = extra + v.num;
        if (t < cfg_item_num) {
            extra += v.num;
            del.push_back(item{v.uuid, v.itemid, v.num, true});
        } else {
            int div = 0;
            if (t > total) {
                div = total / cfg_item_num;
            } else {
                div = t / cfg_item_num;
            }
            bind_num += div;

            int cost = div * cfg_item_num - extra;
            int remain = v.num - div * cfg_item_num + extra;

            del.push_back(item{v.uuid, v.itemid, cost, true});
            total -= div * cfg_item_num;
            extra = remain;

            if (total > 0) {
                if (extra != 0) {
                    del.push_back(item{v.uuid, v.itemid, extra, true});
                }
            } else {
                break;
            }
        }
    }

    if (total > 0) {
        if (extra != 0) {
            bind_num += 1;
        }

        for (auto it = un_bind.begin(); it != un_bind.end(); ++it) {
            auto v = *it;
            int t = extra + v.num;
            if (t < cfg_item_num) {
                extra += v.num;
                del.push_back(item{v.uuid, v.itemid, v.num, false});
            } else {
                int div = 0;
                if (t > total) {
                    div = total / cfg_item_num;
                } else {
                    div = t / cfg_item_num;
                }
                int cost = div * cfg_item_num - extra;
                int remain = v.num - div * cfg_item_num + extra;

                del.push_back(item{v.uuid, v.itemid, cost, false});
                total -= div * cfg_item_num;
                extra = remain;

                if (total > 0) {
                    if (extra != 0) {
                        del.push_back(item{v.uuid, v.itemid, extra, false});
                    }
                } else {
                    break;
                }
            }
        }
    }

    std::cout << "bind num: " << bind_num << std::endl;
    return del;
}

int main(int argc, char *argv[]) {
    items bind;
    bind.push_back(item{1, 1001, 11, true});
    //bind.push_back(item{2, 1002, 4, true});
    bind.push_back(item{2, 1001, 17, true});
    //bind.push_back(item{4, 1004, 12, true});

    items unbind;
    unbind.push_back(item{3, 1001, 10, false});
    //unbind.push_back(item{2, 1002, 10, false});
    //unbind.push_back(item{3, 1003, 10, false});
    //unbind.push_back(item{4, 1004, 10, false});

    int count = std::stoi(argv[1]);
    items ret = cost(bind, unbind, count);

    for (auto it = ret.begin(); it != ret.end(); ++it) {
        std::cout << "uuid : " << it->uuid << ", num : " << it->num << ", bind: " << it->bind << std::endl;
    }
    return 0;
}
