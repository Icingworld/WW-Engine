#include <w_log.h>
#include <w_uuid.h>
#include <w_reflection.h>

class ReflectionTest
{
public:
    int a;
    float b;

public:
    void func()
    {
        printf("func\n");
    }

    auto add() -> decltype(a + b)
    {
        return a + b;
    }
};

int main()
{
    engine::WLog log;
    engine::WUUID uuid;

    // log.log(engine::WLogLevel::trace, uuid.toString());
    // uuid.generate();
    // log.log(engine::WLogLevel::debug, uuid.toString());
    // uuid.generate();
    // log.log(engine::WLogLevel::info, uuid.toString());
    // uuid.generate();
    // log.log(engine::WLogLevel::warn, uuid.toString());
    // uuid.generate();
    // log.log(engine::WLogLevel::error, uuid.toString());
    // log.log(engine::WLogLevel::critical, "critical");

    // 注册
    engine::WReflection::registClass<ReflectionTest>("ReflectionTest")
                        .ctor<>()
                        .data<&ReflectionTest::a>(engine::WReflection::toHashedString("a"))
                        .data<&ReflectionTest::b>(engine::WReflection::toHashedString("b"))
                        .func<&ReflectionTest::func>(engine::WReflection::toHashedString("func"))
                        .func<&ReflectionTest::add>(engine::WReflection::toHashedString("add"));
    
    // 解析
    auto test = engine::WReflection::resolveClass("ReflectionTest");
    auto instance = test.construct();
    auto ref = instance.cast<ReflectionTest>();
    ref.a = 0;
    ref.b = 1.0f;
    ref.func();
    printf("add=%f\n", ref.add());

    return 0;
}
