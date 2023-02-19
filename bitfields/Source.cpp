#include <bitset>
#include <cstddef>
#include <cassert>
#include <iostream>

int main()
{
    typedef std::size_t length_t, position_t; // the hints

    // constructors:
   // constexpr std::bitset<4> b1;
   // constexpr std::bitset<4> b2{ 0xA }; // == 0B1010
   // std::bitset<4> b3{ "0011" }; // can also be constexpr since C++23
   // std::bitset<16> b4{ "ABBA", length_t(4), /*0:*/'A', /*1:*/'B' }; // == 0B0000'0110
    //    b4 <<= 8;
    // bitsets can be printed out to a stream:
    std::bitset<9> mask{};
    std::bitset<9> present_val{ "000000000" };
    
    std::cout << "mask:" << mask << "; present value :" << present_val  << '\n';
    present_val |= mask;
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    mask.set(1);
    present_val |= mask;
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    mask &= 0;
    mask |= 0b000010000;
    present_val |= mask;
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    mask.reset();
    mask[7] = 1;
    present_val |= mask;
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    present_val >>= 1;
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    std::cout << "present value all " << present_val.all() << '\n';
    std::cout << "present value any " << present_val.any() << '\n';
    std::cout << "present value none " << present_val.none() << '\n';
    std::cout << "present value count " << present_val.count() << '\n';
    std::cout << "present value size " << present_val.size() << '\n';
    mask.reset();       // cleans anything from past
    mask[0] = '1';
    present_val |= mask;        // problem as remain on positions from previous ops
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    present_val.flip();
    std::cout << "after flip all flip()  present value :" << present_val << '\n';
    present_val.flip(1);    // toggles the value at position
    std::cout << "after flip 1 flip(1)  present value :" << present_val << '\n';
    mask = 0b000111000;
    present_val ^= mask; 
    std::cout << "after xor mask over p v \n";
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    std::cout << "if twice backs to previous st (xor mask over p v) \n";
    present_val ^= mask;
    std::cout << "mask:" << mask << "; present value :" << present_val << '\n';
    present_val = ~present_val;
    std::cout << "after NOT ~ present value :" << present_val << '\n';
    std::cout << "check if same pos is on present value.test(pos) :" << present_val.test(8) << " in " << 8 << " position" << '\n';
    std::cout << "check if same pos is on present value.test(pos) :" << present_val.test(3) << " in " << 3 << " position" << '\n';
    int k = present_val.test(0);
    if (k)
        present_val <<= 2;
    std::cout << "after << 2 because test(0) present value :" << present_val << '\n';
    std::cout << "now if make again as test(0) false doesn't change \n";
    k = present_val.test(0);
    if (k)
        present_val <<= 2;
    std::cout << "after << 2 because test(0) present value :" << present_val << '\n';
    //// bitset supports bitwise operations:
    //b3 |= 0b0100; assert(b3 == 0b0111);
    //std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << " 0b0111   ; b4:" << b4 << '\n';
    //b3 &= 0b0011; assert(b3 == 0b0011);
    //std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << " 0b0011   ; b4:" << b4 << '\n'; 
    //b3 ^= std::bitset<4>{0b1100}; assert(b3 == 0b1111);
    //std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << " 0b1111   ; b4:" << b4 << '\n';

    //// operations on the whole set:
    //b3.reset(); assert(b3 == 0);
    //std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << " 0b0000   ; b4:" << b4 << '\n';
    //b3.set(); assert(b3 == 0b1111);
    //std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << " 0b1111   ; b4:" << b4 << '\n';
    //assert(b3.all() && b3.any() && !b3.none());
    //b3.flip(); assert(b3 == 0);

    //// operations on individual bits:
    //b3.set(position_t(1), true); assert(b3 == 0b0010);
    //b3.set(position_t(1), false); assert(b3 == 0);
    //b3.flip(position_t(2)); assert(b3 == 0b0100);
    //b3.reset(position_t(2)); assert(b3 == 0);

    //// subscript operator[] is supported:
    //b3[2] = true; assert(true == b3[2]);

    //// other operations:
    //assert(b3.count() == 1);
    //assert(b3.size() == 4);
    //assert(b3.to_ullong() == 0b0100ULL);
    //assert(b3.to_string() == "0100");
}


/**/