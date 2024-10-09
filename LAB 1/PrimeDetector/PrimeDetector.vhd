library ieee; 
use ieee.std_logic_1164.all;

entity primedetector is
    port ( sw: in bit_vector (3 downto 0);         -- array of bits
        prime : out bit);                          -- 0 or 1
end primedetector; 

architecture primearch of primedetector is

    -- let n3 = sw(3), cn3 = not sw(3); n2 = sw(2), cn2 = not sw(2)...
    signal cn3_n2_n0, cn3_cn2_n1, cn2_n1_n0, n2_cn1_n0: bit;    -- bit containers
    begin
        cn3_n2_n0  <= not sw(3)    and     sw(2)                   and sw(0);
        cn3_cn2_n1 <= not sw(3)    and not sw(2)   and     sw(1)            ;
        cn2_n1_n0  <=                  not sw(2)   and     sw(1)   and sw(0);
        n2_cn1_n0  <=                      sw(2)   and not sw(1)   and sw(0);

        prime <= cn3_n2_n0 or cn3_cn2_n1 or cn2_n1_n0 or n2_cn1_n0;
end primearch;