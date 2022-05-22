/** @file event_loop.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/21
 */

#ifndef MAC_EVENT_LOOP_H_
#define MAC_EVENT_LOOP_H_

#include <atomic>

#include "cim/base/noncopyable.h"

struct uv_timer_s;

namespace cim {
namespace base {

typedef void (*timer_cb)(uv_timer_s* handle);

/** @class EventLoop
 * @brief 单Loop，因为是客户端，所以完全够用
 */
class EventLoop : noncopyable {
public:
    /**
     * 启动Loop，将导致当前线程挂起，直到调用stop或者没有任何事件时退出
     */
    static void run();

    /**
     * 在一个独立的线程中运行Loop，当前线程可以继续往下执行
     */
    static void runInThread();

    /**
     * 停止Loop，程序退出前调用
     */
    static void stop();

    /**
     * 注册一个timer
     * @param cb: 回调
     * @param repeat: 定时器间隔，ms
     * @param timeout: 延时，ms，默认立即执行
     * @return 指针，销毁时需要
     */
    static uv_timer_s* registerTimer(const timer_cb& cb, uint64_t repeat, uint64_t timeout = 0);

    /**
     * 移除并停止timer
     * @param timer：registerTimer返回的timer对象
     */
    static void removeTimer(uv_timer_s* timer);

    /**
     * 事件循环是否运行中
     */
    static std::atomic_bool loop_is_run_;

private:
    EventLoop() = default;
    ~EventLoop() override = default;
};

} // namespace base
} // namespace cim

#endif // MAC_EVENT_LOOP_H_
