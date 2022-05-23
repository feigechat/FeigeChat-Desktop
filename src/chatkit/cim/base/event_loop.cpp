/** @file event_loop.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/21
 */

#include "event_loop.h"

#include <thread>

#include "cim/base/log.h"
#include "uv.h"

namespace cim {
namespace base {

// 10s timer空转一次
static uv_timer_s *g_default_timer_ = nullptr;
const int kIdleTick = 1 * 1000;

std::atomic_bool EventLoop::loop_is_run_(false);

// empty timer
static void onTimer(uv_timer_s *timer) {}

void EventLoop::run() {
    auto loop = uv_default_loop();

    loop_is_run_ = true;
    // 因为用户可能先调用run，然后再启动tcp connect，这时候没有任何事件
    // 故uv_run可能会直接退出，所以我们搞1个空timer，占位
    g_default_timer_ = (uv_timer_s *)malloc(sizeof(uv_timer_s));
    uv_timer_init(uv_default_loop(), g_default_timer_);
    uv_timer_start(g_default_timer_, onTimer, 0, kIdleTick);

    uv_run(loop, UV_RUN_DEFAULT); // wait loop exit
    LogDebug("uv loop is success stop");
    loop_is_run_ = false;
}

void EventLoop::stop() {
    if (g_default_timer_) {
        uv_timer_stop(g_default_timer_);
        free(g_default_timer_);
    }
    uv_stop(uv_default_loop());
}

void EventLoop::runInThread() {
    std::thread t(run);
    t.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

uv_timer_s *EventLoop::registerTimer(const timer_cb &cb, uint64_t repeat, uint64_t timeout) {
    auto timer = (uv_timer_s *)malloc(sizeof(uv_timer_s));

    uv_timer_init(uv_default_loop(), timer);
    uv_timer_start(timer, cb, timeout, repeat);

    return timer;
}

void EventLoop::removeTimer(uv_timer_s *timer) {
    if (timer) {
        uv_timer_stop(timer);
        free(timer);
    }
}

} // namespace base
} // namespace cim
