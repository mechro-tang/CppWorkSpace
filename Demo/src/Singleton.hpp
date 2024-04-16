/*
* 单例模板
*/

template<typename T>
class Singleton
{
public:
    Singleton() = default;
    virtual ~Singleton() = default;
    static T* getInstance()
    {
        if (m_pInstance == nullptr)
        {
            m_pInstance = new T();  
        }
        return m_pInstance;
    }
    static void releaseInstance()
    {
        if (m_pInstance != nullptr)
        {
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }

    // 删除默认的移动、拷贝、赋值
    Singleton(Singleton&&) = delete;
    Singleton(const Singleton&) = delete;
    void operator=(Singleton const&) = delete;

private:
    static T* m_pInstance;
};

