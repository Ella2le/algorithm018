//
// Created by lewang on 12/11/20.
//

//1 当成字符串 int -> string -> int
// 2. 位运算

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

//        2.获取x的第n位值(0或者1): (x>>n)&1
//        3.获取x的第n位值的幂值: x&(1<<n)
        uint32_t res = 0;
        for(int i  = 0; i < 32; i++) {
            uint32_t t = (n >> i) & 1;//得到n的最后一位
            //注意索引从0开始
            res = (t << (31-i)) | res;
        }
        return res;
    }
};
//神奇的操作暂时还没看懂,mark!! 希望老师有机会讲解一下.
class Solution {
public:
    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
        if(cache.find(byte) != cache.end()){
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte,value);
        return value;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 24;
        map<uint32_t, uint32_t> cache;
        while(n != 0) {
            ret  += reverseByte( n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }
};