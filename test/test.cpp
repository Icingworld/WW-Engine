#include <w_log.h>

int main()
{
    engine::WLog log;
    log.log(engine::WLogLevel::trace, "trace");
    log.log(engine::WLogLevel::debug, "debug");
    log.log(engine::WLogLevel::info, "info");
    log.log(engine::WLogLevel::warn, "warn");
    log.log(engine::WLogLevel::error, "error");
    log.log(engine::WLogLevel::critical, "critical");

    return 0;
}
