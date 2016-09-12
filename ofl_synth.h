/***************************************************************************
 * HEADER
 **************************************************************************/

#ifndef INCLUDE_OFL_SYNTH_H
#define INCLUDE_OFL_SYNTH_H

#ifdef OFL_SYNTH_STATIC
#define OFL_SYNTH_DEF static
#else
#define OFL_SYNTH_DEF extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct ofl_synth
{
    float samplingfreq, samplingfreq_i;
    int buf_len;
    int buf_off;
    float *buf;
};

OFL_SYNTH_DEF void ofl_synth_osc_sin(struct ofl_synth *s, int count, float phase);

typedef size_t (*ofl_synth_fwrite)(void *ctx, const void *ptr, size_t size);
OFL_SYNTH_DEF void ofl_synth_fwrite_raw(struct ofl_synth *s, ofl_synth_fwrite fw, void *ctx);
OFL_SYNTH_DEF void ofl_synth_fwrite_wav(struct ofl_synth *s, ofl_synth_fwrite fw, void *ctx);

#ifdef __cplusplus
}
#endif

#endif // INCLUDE_OFL_SYNTH_H

/***************************************************************************
 * IMPLEMENTATION
 **************************************************************************/

#ifdef OFL_SYNTH_IMPLEMENTATION

#include <math.h>

#define OFL_SYNTH_PI 3.14159265358979323846f

OFL_SYNTH_DEF void ofl_synth_osc_sin(struct ofl_synth *s, int count, float phase)
{
    float f = s->samplingfreq_i * OFL_SYNTH_PI * phase;
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < count; ++i) *b++ = sinf(i * f);
    s->buf_off += count;
}

OFL_SYNTH_DEF void ofl_synth_fwrite_raw(struct ofl_synth *s, ofl_synth_fwrite fw, void *ctx)
{
    fw(ctx, s->buf, s->buf_len);
}

OFL_SYNTH_DEF void ofl_synth_fwrite_wav(struct ofl_synth *s, ofl_synth_fwrite fw, void *ctx)
{
}

#endif // OFL_SYNTH_IMPLEMENTATION

