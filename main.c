#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define OFL_SYNTH_IMPLEMENTATION
#include "ofl_synth.h"

static size_t s_fwrite(void* ctx, const void* ptr, size_t size)
{ return fwrite(ptr, size, 1, ctx); }

static float f_randf(void)
{ return (float)((double)rand() / (double)RAND_MAX * 2 - 1); }

int main(int argc, char** argv)
{
    srand(time(0));

    float samplingrate = 44100.0f;
    float duration = 1;
    size_t buf_len = (size_t)(samplingrate * duration);

    struct ofl_synth synth[3], *s[3];
    void* buf[3];
    for (int i = 0; i < 3; ++i)
    {
        buf[i] = calloc(buf_len, sizeof(float));
        s[i] = &synth[i];
        ofl_synth_init(s[i], buf[i], buf_len * sizeof(float), samplingrate);
    }

#if 0
    ofl_synth_osc_noi(s[2], f_randf);
#endif

    ofl_synth_osc_sqr(s[2], OFL_SYNTH_NOTE_C4, .25f);

#if 0
    ofl_synth_osc_saw(s[0], OFL_SYNTH_NOTE_C4);
    //ofl_synth_fx_amp(s[0], -3);

    //ofl_synth_osc_saw(s[1], OFL_SYNTH_NOTE_E4);// + 2.0f);
    //ofl_synth_fx_mul(s[1], -.9f);
    int o = 64;
    s[1]->buf_off = o;
    s[1]->buf_len -= o;
    ofl_synth_osc_saw(s[1], OFL_SYNTH_NOTE_C4);
    s[1]->buf_off = 0;
    s[1]->buf_len += o;

    ofl_synth_mix_sub(s[2], s[0], s[1]);
    ofl_synth_fx_amp(s[2], -3);
    ofl_synth_fx_ssat(s[2], 1);
#endif

#if 0
    ofl_synth_fx_amp(s[2], -6);
    ofl_synth_fx_adsr(s[2], 0.1f, 0.2f, 0.4f, 0.3f, -8);
    ofl_synth_fx_delay(s[2], 0.048f, 0.65f, 1, 0.5f);
    ofl_synth_fx_filter(s[2], OFL_SYNTH_FX_FILTER_TYPE_LOWPASS, 2000, 1);
    ofl_synth_fx_ssat(s[2], 0.5f);
#endif

    FILE* f = fopen("test.wav", "wb");
    ofl_synth_fwrite_wav(s[2], s_fwrite, f);
    fclose(f);

    return 0;
}

