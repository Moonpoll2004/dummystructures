#include <map>
#include <string>



template<typename T,typename K>
class Table
{
private:
    std::map<T,K> m_table;
public:
   std::string t_name;

   Table(const std::string& name){
       t_name = name;
   }
   ~Table(){}
    size_t getSize(){
        return m_table.size();
    }

    void Insert_one(const T &key,K val){
        m_table[key] = val;
    }

    auto Get_one(const T &key){
        auto val = m_table.find(key);
        return val;
    }
};

