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

#define OFL_SYNTH_DB_TO_VOLTAGERATIO(db) (powf(10, db * (1.0f/20)))

struct ofl_synth
{
    float samplingrate, samplingrate_i;
    int buf_len;
    int buf_off;
    float *buf;
};
OFL_SYNTH_DEF void ofl_synth_init(struct ofl_synth *s, float *buf, size_t buf_sz, float samplingrate);

OFL_SYNTH_DEF void ofl_synth_mix_cpy(struct ofl_synth *s, struct ofl_synth *o);
OFL_SYNTH_DEF void ofl_synth_mix_add(struct ofl_synth *s, struct ofl_synth *s1, struct ofl_synth *s2);
OFL_SYNTH_DEF void ofl_synth_mix_sub(struct ofl_synth *s, struct ofl_synth *s1, struct ofl_synth *s2);

OFL_SYNTH_DEF void ofl_synth_osc_set(struct ofl_synth *s, float v);
OFL_SYNTH_DEF void ofl_synth_osc_sin(struct ofl_synth *s, float freq);
OFL_SYNTH_DEF void ofl_synth_osc_sqr(struct ofl_synth *s, float freq);
OFL_SYNTH_DEF void ofl_synth_osc_saw(struct ofl_synth *s, float freq);
OFL_SYNTH_DEF void ofl_synth_osc_tri(struct ofl_synth *s, float freq);

OFL_SYNTH_DEF void ofl_synth_fx_clip(struct ofl_synth *s, float v);
// v: [0,1], soft saturate waveshaper: http://musicdsp.org/showArchiveComment.php?ArchiveID=42
OFL_SYNTH_DEF void ofl_synth_fx_ssat(struct ofl_synth *s, float v);
OFL_SYNTH_DEF void ofl_synth_fx_adsr(struct ofl_synth *s, float attack_s, float decay_s, float sustain_s, float release_s, float sustain_db);
#define ofl_synth_fx_amp(s, db) ofl_synth_fx_mul(s, OFL_SYNTH_DB_TO_VOLTAGERATIO(db))
OFL_SYNTH_DEF void ofl_synth_fx_mul(struct ofl_synth *s, float f);
OFL_SYNTH_DEF void ofl_synth_fx_pow(struct ofl_synth *s, float e);
OFL_SYNTH_DEF void ofl_synth_fx_delay(struct ofl_synth *s, float delay_s, float feedback, float dry, float wet);

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

#if !defined(OFL_SYNTH_MEMSET) || !defined(OFL_SYNTH_MEMCPY)
#include <string.h>
#ifndef OFL_SYNTH_MEMSET
#define OFL_SYNTH_MEMSET memset
#endif
#ifndef OFL_SYNTH_MEMCPY
#define OFL_SYNTH_MEMCPY memcpy
#endif
#endif

#ifndef OFL_SYNTH_ALLOCA
#include <alloca.h>
#define OFL_SYNTH_ALLOCA alloca
#define OFL_SYNTH_FREEA(p)
#endif

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

OFL_SYNTH_DEF void ofl_synth_mix_cpy(struct ofl_synth *s, struct ofl_synth *o)
{
    float *b = s->buf + s->buf_off, *d = o->buf + o->buf_off;
    int c = s->buf_len; if (c > o->buf_len) c = o->buf_len;
    OFL_SYNTH_MEMCPY(b, d, c * sizeof(*b));
}

OFL_SYNTH_DEF void ofl_synth_mix_add(struct ofl_synth *s, struct ofl_synth *s1, struct ofl_synth *s2)
{
    float *b = s->buf + s->buf_off, *b1 = s1->buf + s1->buf_off, *b2 = s2->buf + s2->buf_off;
    int c = s->buf_len; if (c > s1->buf_len) c = s1->buf_len; if (c > s2->buf_len) c = s2->buf_len;
    for (int i = 0; i < c; ++i) *b++ = *b1++ + *b2++;
}

OFL_SYNTH_DEF void ofl_synth_mix_sub(struct ofl_synth *s, struct ofl_synth *s1, struct ofl_synth *s2)
{
    float *b = s->buf + s->buf_off, *b1 = s1->buf + s1->buf_off, *b2 = s2->buf + s2->buf_off;
    int c = s->buf_len; if (c > s1->buf_len) c = s1->buf_len; if (c > s2->buf_len) c = s2->buf_len;
    for (int i = 0; i < c; ++i) *b++ = *b1++ - *b2++;
}

OFL_SYNTH_DEF void ofl_synth_osc_set(struct ofl_synth *s, float v)
{
    float *b = s->buf + s->buf_off;
    for (float* e = b + s->buf_len; b != e; ++b) *b = v;
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

OFL_SYNTH_DEF void ofl_synth_fx_clip(struct ofl_synth *s, float v)
{
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i, ++b) *b = *b > v ? v : *b < -v ? -v : *b;
}

OFL_SYNTH_DEF void ofl_synth_fx_ssat(struct ofl_synth *s, float v)
{
    float *b = s->buf + s->buf_off;
    float v_ir = 1.0f / (1-v);
    for (int i = 0; i < s->buf_len; ++i, ++b)
    {
        float x = *b;
        int neg = x < 0;
        if (x < 0) x = -x;
        if (x > v) { float t = (x-v)*v_ir; t*=t; x = v + (x-v) / (1+t); }
        *b = neg ? -x : x;
    }
}

OFL_SYNTH_DEF void ofl_synth_fx_adsr(struct ofl_synth *s, float attack_s, float decay_s, float sustain_s, float release_s, float sustain_db)
{
    int attack_sc = (int)(attack_s * s->samplingrate);
    int decay_sc = (int)(decay_s * s->samplingrate);
    int sustain_sc = (int)(sustain_s * s->samplingrate);
    int release_sc = (int)(release_s * s->samplingrate);

    if (attack_sc > s->buf_len) attack_sc = s->buf_len, decay_sc = sustain_sc = release_sc = 0;
    else if (attack_sc + decay_sc > s->buf_len) decay_sc = s->buf_len - attack_sc, sustain_sc = release_sc = 0;
    else if (attack_sc + decay_sc + sustain_sc > s->buf_len) sustain_sc = s->buf_len - attack_sc - decay_sc, release_sc = 0;
    else if (attack_sc + decay_sc + sustain_sc + release_sc > s->buf_len) release_sc = s->buf_len - attack_sc - decay_sc - sustain_sc;

    float sustain_v = OFL_SYNTH_DB_TO_VOLTAGERATIO(sustain_db);
    float *b = s->buf + s->buf_off;
    for (float *e = b + attack_sc, f = 0, inc = 1.0f / attack_sc; b != e; ++b, f += inc)
        *b *= f;
    for (float *e = b + decay_sc, f = 0, inc = 1.0f / decay_sc * (1 - sustain_v); b != e; ++b, f += inc)
        *b *= 1 - f;
    for (float *e = b + sustain_sc; b != e; ++b)
        *b *= sustain_v;
    for (float *e = b + release_sc, f = 0, inc = 1.0f / release_sc; b != e; ++b, f += inc)
        *b *= sustain_v * (1 - f);
}

OFL_SYNTH_DEF void ofl_synth_fx_mul(struct ofl_synth *s, float f)
{
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i) *b++ *= f;
}

OFL_SYNTH_DEF void ofl_synth_fx_pow(struct ofl_synth *s, float e)
{
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i, ++b) *b = *b < 0 ? -powf(-*b, e) : pow(*b, e);
}

OFL_SYNTH_DEF void ofl_synth_fx_delay(struct ofl_synth *s, float delay_s, float feedback, float dry, float wet)
{
    int sc = (int)(delay_s * s->samplingrate);
    if (sc > s->buf_len) sc = s->buf_len;
    float *h = OFL_SYNTH_ALLOCA(sc * sizeof(*h));
    OFL_SYNTH_MEMSET(h, 0, sc * sizeof(*h));
    float *b = s->buf + s->buf_off;
    for (int i = 0, hi = 1, hj = 0; i < s->buf_len; ++i)
    {
        h[hj] = b[i] + feedback * h[hi];
        b[i] = dry * b[i] + wet * h[hi];
        if (++hi >= sc) hi = 0;
        if (++hj >= sc) hj = 0;
    }
    OFL_SYNTH_FREEA(h);
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

