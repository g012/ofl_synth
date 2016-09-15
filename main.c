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
    size_t buf_len = (size_t)samplingrate;
    void* buf = calloc(buf_len, sizeof(float));
    ofl_synth_init(s, buf, buf_len * sizeof(float), samplingrate);

    ofl_synth_osc_saw(s, 440.0f);
    ofl_synth_fx_amp(s, -6);
    ofl_synth_fx_adsr(s, 0.1f, 0.2f, 0.4f, 0.3f, -8);
    ofl_synth_fx_delay(s, 0.048f, 0.65f, 1, 0.5f);

    FILE* f = fopen("test.wav", "wb");
    ofl_synth_fwrite_wav(s, s_fwrite, f);
    fclose(f);

    return 0;
}

