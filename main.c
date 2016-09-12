#include <stdlib.h>
#include <stdio.h>

#define OFL_SYNTH_IMPLEMENTATION
#include "ofl_synth.h"

static size_t s_fwrite(void* ctx, const void* ptr, size_t size)
{ return fwrite(ptr, size, 1, ctx); }

int main(int argc, char** argv)
{
    struct ofl_synth synth, *s = &synth;
    float samplingrate = 44100.0f;
    size_t buf_sz = (size_t)samplingrate * sizeof(float);
    void* buf = malloc(buf_sz);
    ofl_synth_init(s, buf, buf_sz, samplingrate);

    ofl_synth_osc_saw(s, 440.0f);

    FILE* f = fopen("test.wav", "wb");
    ofl_synth_fwrite_wav(s, s_fwrite, f);
    fclose(f);

    return 0;
}

