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
    float samplingrate, samplingrate_i;
    int buf_len;
    int buf_off;
    float *buf;
};
OFL_SYNTH_DEF void ofl_synth_init(struct ofl_synth *s, float *buf, size_t buf_sz, float samplingrate);

OFL_SYNTH_DEF void ofl_synth_osc_sin(struct ofl_synth *s, float freq);
OFL_SYNTH_DEF void ofl_synth_osc_sqr(struct ofl_synth *s, float freq);
OFL_SYNTH_DEF void ofl_synth_osc_saw(struct ofl_synth *s, float freq);
OFL_SYNTH_DEF void ofl_synth_osc_tri(struct ofl_synth *s, float freq);

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

#define OFL_SYNTH_PI (3.14159265358979323846f)
#define OFL_SYNTH_2PI (6.28318530717958647693f)

OFL_SYNTH_DEF void ofl_synth_init(struct ofl_synth *s, float *buf, size_t buf_sz, float samplingrate)
{
    s->samplingrate = samplingrate;
    s->samplingrate_i = 1.0f / s->samplingrate;
    s->buf_len = (int)(buf_sz / sizeof(*buf));
    s->buf_off = 0;
    s->buf = buf;
}

OFL_SYNTH_DEF void ofl_synth_osc_sin(struct ofl_synth *s, float freq)
{
    float f = freq * s->samplingrate_i * OFL_SYNTH_2PI;
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i) *b++ = sinf(i * f);
}

OFL_SYNTH_DEF void ofl_synth_osc_sqr(struct ofl_synth *s, float freq)
{
    float f = freq * s->samplingrate_i * 2;
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i) *b++ = fmodf(i*f, 2) < 1 ? 1 : -1;
}

OFL_SYNTH_DEF void ofl_synth_osc_saw(struct ofl_synth *s, float freq)
{
    float f = freq * s->samplingrate_i * 2;
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i) *b++ = fmodf(i*f+1, 2) - 1;
}

OFL_SYNTH_DEF void ofl_synth_osc_tri(struct ofl_synth *s, float freq)
{
    float f = freq * s->samplingrate_i * 2;
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i)
    {
        float r = fmodf(i*f, 2);
        *b++ = r < 0.5f ? 2*r : r < 1.5f ? -2*r+2 : 2*r-4;
    }
}

OFL_SYNTH_DEF void ofl_synth_fwrite_raw(struct ofl_synth *s, ofl_synth_fwrite fw, void *ctx)
{
    fw(ctx, s->buf, s->buf_len * sizeof(*s->buf));
}

OFL_SYNTH_DEF void ofl_synth_fwrite_wav(struct ofl_synth *s, ofl_synth_fwrite fw, void *ctx)
{
    short b[2048];
    struct wavfile_header
    {
        char	riff_tag[4];
        int	    riff_length;
        char	wave_tag[4];
        char	fmt_tag[4];
        int	    fmt_length;
        short	audio_format;
        short	num_channels;
        int	    sample_rate;
        int	    byte_rate;
        short	block_align;
        short	bits_per_sample;
        char	data_tag[4];
        int	    data_length;
    } h = { "RIFF", 2*s->buf_len + sizeof(struct wavfile_header) - 8, "WAVE", "fmt ", 16, 1, 1, (int)s->samplingrate, 2*(int)s->samplingrate, 2, 16, "data", 2*s->buf_len };
    fw(ctx, &h, sizeof(h));
    float *f = s->buf;
    for (int i = 0; i < s->buf_len; i += sizeof(b) / sizeof(*b))
    {
        int c = sizeof(b) / sizeof(*b);
        if (c > s->buf_len - i) c = s->buf_len - i;
        int cw = c;
        for (short *d = b; c > 0; --c) *d++ = (short)(*f++ * 32767.0f);
        fw(ctx, b, cw * sizeof(*b));
    }
}

#endif // OFL_SYNTH_IMPLEMENTATION

