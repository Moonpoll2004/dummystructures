#include <vector>

template<typename K, typename V>
struct kv
{
    K key;
    V value;
};

template<typename A,typename E>
struct mp
{
    std::vector<kv<A,E>> m_data;

    bool Exist(const A& key)
    {
        bool res;
        for(kv<A,E> en: m_data) {
            res = en.key==key;
            if(res == true) {
                break;
            };
        }
        
       return res;
    }

    void Set(const A& key, E value)
    {
        if(Exist(key) != true){
            kv<A,E> k_v;
            k_v.key = key;
            k_v.value = value;
            m_data.push_back(k_v);
        }
    }
    ;
    kv<A,E>* Get(const A& key)
    {
        kv<A,E> kv_val;
        kv<A,E>* kv_ptr = &kv_val;
        for(kv<A,E> en: m_data)
            if(en.key == key){
                kv_val.key = en.key;
                kv_val.value = en.value;
            }

        return kv_ptr;   
    };

    void Clear()
    {
        m_data.clear();
    };

    size_t GetSize() {
        return m_data.size();
    }
};