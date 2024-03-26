#include <vector>
#include "bfilter.h"

// (a)

class SillyHashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        // Here's my silly hash function that always returns 0.
        // You should make some good hash functions and not use this one.
        // This is just an example of how to inherit the HashFun class.
        return 0;
    }
};

class GoodHashFun_0 : public HashFun {
    unsigned int operator()(const std::string& key) {
        // You've seen my silly hash function above.
        // Your good hash function should go here!

        return 0; // You'll need to change this
    }
};

// ...
// You can make as many hash functions as you want!
// ...

void BloomFilter::add_hash_funs() {
    // You will need to implement this function, it is responsible
    // for adding your custom hash functions to your bloom filter.

    // Here's an example where I add two hash functions.
    // You will need to add at least one hash function.
    SillyHashFun *h1 = new SillyHashFun();
    GoodHashFun_0 *h2 = new GoodHashFun_0();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string& key) {
    // You will need to implement this function, it is responsible
    // for inserting key into the bloom filter.

    // Here's how you can call your hash functions that you added in add_hash_funs()
    unsigned int first_hash_result = this->call_hash(0, key);
    // std::cout << "Hash of '" << key << "' is '" << first_hash_result << "' using the first hash function." << std::endl;
    unsigned int second_hash_result = this->call_hash(1, key);
    // std::cout << "Hash of '" << key << "' is '" << second_hash_result << "' using the second hash function." << std::endl;

    // You'll need to use the results of the hash function to update this->filter
    // Here's an example
    (this->filter)[first_hash_result % 330] = 1;
}

bool BloomFilter::member(const std::string& key) {
    // This function should report true if key is potentially in the bloom filter.
    // It should only return false if you know for sure that key is not in the bloom filter.

    //
    // your code here ...
    //
    return false; // you will need to change this.
}
