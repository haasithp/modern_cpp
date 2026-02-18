#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cctype>

namespace ipb{
    template <typename T>
    class named_vector : public std::vector<T>{
        public:
        named_vector() = default;
        named_vector(const std::string& name) : name_(name) {}
        named_vector(const std::string& name, const std::vector<T>& v) 
            : std::vector<T>(v), name_(name) {}
        
        std::vector<T>& vector(){
            return *this;
        }

        const std::vector<T>& vector() const{
             return *this;
        }

        const std::string& name() const {
            return name_;
        }

        // Added to support modification of name for toupper
        std::string& name() {
            return name_;
        }

        size_t size() const {
            return std::vector<T>::size() + name_.size();
        }    

        // Standard vector capacity needed for tests?
        // tests use .capacity(). std::vector has it.
        // It is inherited.

        bool empty() const {
            return name_.empty() || std::vector<T>::empty();
        }
        
        // Inherit other constructors?
        // std::vector constructors might be useful but tests seem specific.
        
        private:
        std::string name_;
    };

    template <typename T>
    T accumulate(const named_vector<T>& v){
        return std::accumulate(v.begin(), v.end(), T{});
    }

    template <typename T>
    long count(const named_vector<T>& v, const T& val){
        return std::count(v.begin(), v.end(), val);
    }

    template <typename T>
    bool all_even(const named_vector<T>& v){
        return std::all_of(v.begin(), v.end(), [](const T& x){ return x % 2 == 0; });
    }

    template <typename T>
    void clamp(named_vector<T>& v, T min, T max){
        for(auto& x : v){
            x = std::clamp(x, min, max);
        }
    }

    template <typename T>
    void fill(named_vector<T>& v, const T& val){
        std::fill(v.begin(), v.end(), val);
    }

    template <typename T>
    bool find(const named_vector<T>& v, const T& val){
        return std::find(v.begin(), v.end(), val) != v.end();
    }

    template <typename T>
    void print(const named_vector<T>& v){
        std::cout << v.name() << " : ";
        for(size_t i = 0; i < v.vector().size(); ++i){
            std::cout << v.vector()[i];
            if(i != v.vector().size() - 1){
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    template <typename T>
    void toupper(named_vector<T>& v){
        std::string& n = v.name();
        std::transform(n.begin(), n.end(), n.begin(), 
            [](unsigned char c){ return std::toupper(c); });
    }

    template <typename T>
    void sort(named_vector<T>& v){
        std::sort(v.begin(), v.end());
    }

    template <typename T>
    void rotate(named_vector<T>& v, int n){
        std::rotate(v.begin(), v.begin() + n, v.end());
    }

    template <typename T>
    void reverse(named_vector<T>& v){
        std::reverse(v.begin(), v.end());
    }

}
