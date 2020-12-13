//
// Created by lewang on 12/11/20.
//

#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int a = 8,b=5;
    cout << "Decimal: a = " << a << ", b = " << b << endl;
    cout << "Binary: a = "<< bitset<8>(a) << ", b = " <<bitset<8>(b) << endl;

//位运算:
//- 与  &
    cout << "a & b =" << bitset<8>(a & b)<<endl;
//- 或  |
    cout << "a | b =" << bitset<8>(a | b) << endl;
//- 非  ~
    cout << "~a =  " << bitset<8>(~a) << endl;
//- 异或 ^
    cout << "a ^ b = " << bitset<8>(a | b) << endl;
//- 左移 <<
    cout << "a << b = " << bitset<16>(a << b) << endl;
//- 右移 >>
    cout << "a >> b = " << bitset<16>(a >> b) << endl;

//    异或的一些操作
//    x ^ 0 =x
    cout << "a ^ 0 =" << bitset<8>(a ^ 0) << endl;
//    x ^ 1s = ~x //注意 1s = ~0
    cout << "a ^ ~0 =" << bitset<8>(a ^ ~0) << endl;
//    x ^ (~x) = 1s
    cout << "a ^ ~a =" << bitset<8>(a ^ (~a)) << endl;
//    x ^ x = 0
    cout << "a ^ a =" << bitset<8>(a ^ a) << endl;
//    c = a ^ b => a ^ c = b, b ^ c = a //异或操作来 交换两个数
//    a ^b ^ c = a ^ (b ^ c) = (a ^ b) ^c //满足结合律
//
    cout<<"-----------指定位置的位运算-------------------"<<endl;
    int x = 156, n =3;
    cout << "Decimal: x = " << x << ", n = " << n << endl;
    cout << "Binary: x = "<< bitset<8>(x) << ", n = " <<bitset<8>(n) << endl;
    cout<<"-----------------------------"<<endl;
//    指定位置的位运算:
    cout <<"1.将x最右边的n位清零:x&(~0<<n)"<<endl;
    cout<< ~0 << "|" <<bitset<64>(~0) <<endl;
    cout<< ~0 << "|" <<bitset<128>(~0) <<endl;
    cout << 1 << "|" << bitset<64>(1) <<endl;
    cout<< (~0 << n) << "|"<< bitset<64>(~0<<n)<<endl;
    cout<< (1 << n) << "|" << bitset<64>(1<<n)<<endl;
    //注意~0 和 1 不一样!!!! 十进制差了一个符号,二进制差了64-1 = 63 个1!!!
    cout << bitset<8>(x&(~0<<n)) << endl;
    cout << bitset<8>(x&(1<<n)) << endl;//只保留第n+1位上的数,其余都为0

    cout << "2.获取x的第n位值(0或者1): (x>>n)&1 " << endl;
    cout << bitset<8>((x>>n)&1) << endl;
    cout << ((x>>n)&1) << endl;

    cout <<"3.获取x的第n位值的幂值: x&(1<<n)" <<endl;
    cout << bitset<8>(x&(1<<n)) << endl;
    cout << (x&(1<<n)) << endl;

    cout<<"4.仅将第n位设为1: x|(1<<n)"<<endl;
    cout << bitset<8>(x|(1<<n)) << endl;


    cout<<"5.仅将第n为设为0: x & (~(1<<n))" <<endl;
    cout << bitset<8>(x & (~(1<<n))) << endl;


    cout<<"6.将x最高位到第n位(含)清零:x & ((1 << n) - 1)"<<endl;
    cout << bitset<8>(x & ((1 << n) - 1)) << endl;

    int xx = 153;
    cout << bitset<8>(xx)<<endl;
    // -xx 为xx的补码, 将 -xx  = ~xx + 1
    cout << (xx & -xx) << endl;
    cout<< bitset<8>(xx & (xx-1))<< endl;
    cout<<(xx&~xx)<<endl;

    //uint32_t
    int nn = 133;
    cout<<bitset<32>(nn)<<endl;
    cout<<bitset<32>(nn&(nn-1))<<endl;
    cout<< " --------------------------- "<<endl;


    int sum = 0;
    while(nn > 0) {
        cout<<bitset<32>(nn-1)<<endl;
        sum ++;
        nn &=(nn-1);
        cout<<bitset<32>(nn)<<endl;
    }
    cout<<sum<<endl;
    cout<<"---------------------------"<<endl;
    uint32_t nx = 4589762134;
    cout<<bitset<32>(nx)<<endl;
    uint32_t res = 0;
    for(int i  = 0; i < 32; i++) {
        uint32_t t = (nx >> i) & 1;//得到n的最后一位
        //nx >>= i;
        cout<<t<<endl;
        res = (t << (32-i)) | res;
    }
    return res;


    return 0;
}