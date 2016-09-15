#!/usr/bin/env lua

local names = {"C","CS","D","DS","E","F","FS","G","GS","A","AS","B"}
local fn = assert(io.open("ofl_synth_lut.h", "wb"))
local f = assert(io.open("ofl_synth_lut.c", "wb"))
f:write("const float ofl_synth_notes[11*12] = {\n")
local p = math.pow(2, 1/12)
for k=0,10 do
    f:write("\t")
    for n=-9,2 do
        local freq = math.pow(2, k-4) * 440 * math.pow(p, n)
        fn:write(string.format("#define OFL_SYNTH_NOTE_%s%d (%#.9gf)\n", names[n+10], k, freq))
        f:write(string.format("%#.9gf,", freq))
    end
    fn:write("\n")
    f:write("\n")
end
fn:close()
f:write("};")
f:close()
