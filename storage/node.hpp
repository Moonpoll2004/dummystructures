#include "store.hpp"
#include <string>



struct Node{
    std::string name = "values";
    Table<std::string,int> tb = Table<std::string,int>("tamer");
    //node left and right
    Node* nodeLeft = nullptr;
    Node* nodeRight = nullptr;


    void add(const std::string& key,int val){
        tb.Insert_one(key,val);
    }

    size_t Length(){
        return tb.getSize();
    }

    void addToNode(const char direction,const std::string& key,int val){
        if(direction == 'r'){
            nodeRight->add(key,val);
        }else if(direction == 'l'){
            nodeLeft->add(key,val);
        }
    }

    auto search(const std::string& key){
        return tb.Get_one(key); 
    }

    auto searchInNode(const char direction,const std::string& key){
        if(direction == 'r'){
           return nodeRight->search(key);
        }else{
            return nodeLeft->search(key);
        }
    }
};