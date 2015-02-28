#include "../heap.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <iterator> 

using namespace std;

TEST(heapTest, Sort) {
    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        vector<int> v;
        
        int len = rand()%100;
        for (int i = 0; i < len; ++i ) {
            v.push_back(rand()%1000);
        }
        //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        //cout << endl;
        
        heapSort(v.begin(), v.end());
    
        for (int i = 1; i < len; ++i) {
            EXPECT_LE(v[i-1], v[i]);
        }
    }
}

TEST(heapTest, makeHeap) {
    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        vector<int> v;
        
        int len = rand()%100;
        for (int i = 0; i < len; ++i ) {
            v.push_back(rand()%1000);
        }
        //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        //cout << endl;
        
        makeHeap(v.begin(), v.end());

        EXPECT_TRUE(isheap(v.begin(), v.end())); 

        for (int i = 0; i < len; ++i ) {
            popHeap(v.begin(), v.end());
            v.pop_back();
            EXPECT_TRUE(isheap(v.begin(), v.end())); 
        }
        
        /*
        for (int i = 0; i < len; ++i ) {
            v.push_back(rand()%1000);
            pushHeap(v.begin(), v.end());
            v.pop_back();
            EXPECT_TRUE(isheap(v.begin(), v.end())); 
        }
        */
    }
}
