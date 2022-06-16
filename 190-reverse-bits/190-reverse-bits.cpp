class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
          auto x = bitset<32>(n);
          auto str = x.to_string();
          reverse(str.begin(), str.end());
          return (uint32_t)bitset<32>(str).to_ulong();
    }
};