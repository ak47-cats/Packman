#ifndef POOL_HPP
#define POOL_HPP

#include <vector>
#include <stddef.h>

template<typename T>
class ObjectPool
{
    private:
        struct PoolRecord
        {
            T* instance;
            bool in_use;
        };
        std::vector<PoolRecord> m_pool;

        bool search_object(T& a, T& b){
            return a.id == b.id;
        }

    public:
        T* get_object()
        {
            for (size_t i = 0; i < m_pool.size(); ++i)
            {
                if (!m_pool[i].in_use)
                {
                    m_pool[i].in_use = true;
                    return m_pool[i].instance;
                }
            }
            PoolRecord record;
            record.instance = new T;
            record.in_use   = true;

            m_pool.push_back(record);

            return record.instance;
        }


        void delete_object(T* object)
        {
            for (size_t i = 0; i < m_pool.size(); ++i)
            {
                if (m_pool[i].instance == object)
                {
                    m_pool[i].in_use = false;
                    break;
                }
            }
        }

        virtual ~ObjectPool()
        {
            for (size_t i = 0; i < m_pool.size(); ++i)
                delete m_pool[i].instance;
        }
};


#endif
