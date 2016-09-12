#include <stdlib.h>
#include <stdio.h>

#define OFL_SYNTH_IMPLEMENTATION
#include "ofl_synth.h"

static size_t s_fwrite(void* ctx, const void* ptr, size_t size)
{ return fwrite(ptr, size, 1, ctx); }

int main(int argc, char** argv)
{
    struct ofl_synth synth, *s = &synth;
    s->samplingfreq = 44100.0f;
    s->samplingfreq_i = 1.0f / s->samplingfreq;
    s->buf_len = (int)s->samplingfreq * sizeof(*s->buf);
    s->buf_off = 0;
    s->buf = malloc(s->buf_len);

    ofl_synth_osc_sin(s, s->buf_len / sizeof(*s->buf), 440.0f);

    FILE* f = fopen("test_mono_f32.raw", "wb");
    ofl_synth_fwrite_raw(s, s_fwrite, f);
    fclose(f);

    return 0;
}

