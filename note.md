### event base

>   event_base_new()
    event_base loop can only be run in a single thread.

    event_base_free()
    does not deallocate the events that are currently associated with the event base, or close any of their sockets, or free any of theirpointers.


>   event_config_new()
    event_config_free()

    event_base_new_with_config()

    event_config_avoid_method()
    select、poll、epoll、kqueue、devpoll、evport、win32

    event_method_feature {
        EV_FEATURE_ET,
        EV_FEATRUE_01,
        EV_FEATURE_FDS,
    }
    event_config_require_features()

    event_base_config_flag {
        EVENT_BASE_FLAG_NOBLOCK,
        EVENT_BASE_FLAG_IGNORE_ENV,
        EVENT_BASE_FLAG_STARTUP_IOCP,
        EVENT_BASE_FLAG_NO_CACHE_TIME,
        EVENT_BASE_FLAG_EPOLL_USE_CHANGELIST,
        EVENT_BASE_FLAG_PRECISE_TIMER,
    }
    event_config_set_flag()

>   event_config_set_num_cpus_hint()
    only for iocp, just a hint

>   event_config_set_max_dispatch_interval()

---

```
    struct event_config *cfg;
    struct event_base *base;
    int i;
    for (i = 0; i < 2; ++i) {
        cfg = event_config_new();
        event_config_avoid_method(cfg, "select");
        if (i == 0) {
            event_config_require_features(cfg, EV_FEATURE_ET);
        }
        base = event_base_new_with_config(cfg);
        event_config_free(cfg);
        if (base) {
            break;
        }
    }
```
---

```
    struct event_base *base;
    struct event_config *cfg;
    cfg = event_config_new();
    if (!cfg) {
        return;
    }
    struct timeval msec_100 {0, 100 * 1000};
    event_config_set_max_dispatch_interval(cfg, &msec_100, 5, 1);
    base = event_base_new_with_config(cfg);
    event_config_free(cfg);
    if (!base) {
        return;
    }
    event_base_priority_init(base, 2);
```

>   event_get_supported_methods()
    event_get_version()

    event_base_get_method()
    event_base_get_features()

>   event_base_priority_init()
    0:most important

    event_base_getnpriorities()

>   event_base_reinit()

>   event_init()


### event loop

>   event_base_loop()
    EVLOOP_ONCE、EVLOOP_NONBLOCK、EVLOOP_NO_EXIT_ON_EMPTY

    event_base_dispatch()

    event_base_loopbreak()
    event_base_loopexit()

    event_base_got_exit()
    event_base_got_break()

    event_base_loopcontinue()

    event_base_gettimeofday_cached()
    event_base_update_cache_time()

    event_base_dump_events()

    ```
    typedef int (*event_base_foreach_event_cb) (const struct event_base*, const struct event*, void*);
    ```
    event_base_foreach_event()

### event
  
```
typedef void (*event_callback_fn) (evutil_socket_t, short, void*)  
struct event* event_new(struct event_base*, evutil_socket_t, short, event_callback_fn*, void*);  
void event_free(struct event*);
```
  
```
#define EV_TIMEOUT      0x01  
#define EV_READ         0x02  
#define EV_WRITE        0x04  
#define EV_SIGNAL       0x08  
#define EV_PERSIST      0x10  
#define EV_ET           0x20  
```
  
```
void* event_self_cbarg();
```
  

