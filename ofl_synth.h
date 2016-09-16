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

#ifndef OFL_SYNTH_STATIC
OFL_SYNTH_DEF const float ofl_synth_notes[10*12]; // C0 to B9
#endif
#define OFL_SYNTH_NOTE_C0 (16.3515978f)
#define OFL_SYNTH_NOTE_CS0 (17.3239144f)
#define OFL_SYNTH_NOTE_D0 (18.3540480f)
#define OFL_SYNTH_NOTE_DS0 (19.4454365f)
#define OFL_SYNTH_NOTE_E0 (20.6017223f)
#define OFL_SYNTH_NOTE_F0 (21.8267645f)
#define OFL_SYNTH_NOTE_FS0 (23.1246514f)
#define OFL_SYNTH_NOTE_G0 (24.4997147f)
#define OFL_SYNTH_NOTE_GS0 (25.9565436f)
#define OFL_SYNTH_NOTE_A0 (27.5000000f)
#define OFL_SYNTH_NOTE_AS0 (29.1352351f)
#define OFL_SYNTH_NOTE_B0 (30.8677063f)

#define OFL_SYNTH_NOTE_C1 (32.7031957f)
#define OFL_SYNTH_NOTE_CS1 (34.6478289f)
#define OFL_SYNTH_NOTE_D1 (36.7080960f)
#define OFL_SYNTH_NOTE_DS1 (38.8908730f)
#define OFL_SYNTH_NOTE_E1 (41.2034446f)
#define OFL_SYNTH_NOTE_F1 (43.6535289f)
#define OFL_SYNTH_NOTE_FS1 (46.2493028f)
#define OFL_SYNTH_NOTE_G1 (48.9994295f)
#define OFL_SYNTH_NOTE_GS1 (51.9130872f)
#define OFL_SYNTH_NOTE_A1 (55.0000000f)
#define OFL_SYNTH_NOTE_AS1 (58.2704702f)
#define OFL_SYNTH_NOTE_B1 (61.7354127f)

#define OFL_SYNTH_NOTE_C2 (65.4063913f)
#define OFL_SYNTH_NOTE_CS2 (69.2956577f)
#define OFL_SYNTH_NOTE_D2 (73.4161920f)
#define OFL_SYNTH_NOTE_DS2 (77.7817459f)
#define OFL_SYNTH_NOTE_E2 (82.4068892f)
#define OFL_SYNTH_NOTE_F2 (87.3070579f)
#define OFL_SYNTH_NOTE_FS2 (92.4986057f)
#define OFL_SYNTH_NOTE_G2 (97.9988590f)
#define OFL_SYNTH_NOTE_GS2 (103.826174f)
#define OFL_SYNTH_NOTE_A2 (110.000000f)
#define OFL_SYNTH_NOTE_AS2 (116.540940f)
#define OFL_SYNTH_NOTE_B2 (123.470825f)

#define OFL_SYNTH_NOTE_C3 (130.812783f)
#define OFL_SYNTH_NOTE_CS3 (138.591315f)
#define OFL_SYNTH_NOTE_D3 (146.832384f)
#define OFL_SYNTH_NOTE_DS3 (155.563492f)
#define OFL_SYNTH_NOTE_E3 (164.813778f)
#define OFL_SYNTH_NOTE_F3 (174.614116f)
#define OFL_SYNTH_NOTE_FS3 (184.997211f)
#define OFL_SYNTH_NOTE_G3 (195.997718f)
#define OFL_SYNTH_NOTE_GS3 (207.652349f)
#define OFL_SYNTH_NOTE_A3 (220.000000f)
#define OFL_SYNTH_NOTE_AS3 (233.081881f)
#define OFL_SYNTH_NOTE_B3 (246.941651f)

#define OFL_SYNTH_NOTE_C4 (261.625565f)
#define OFL_SYNTH_NOTE_CS4 (277.182631f)
#define OFL_SYNTH_NOTE_D4 (293.664768f)
#define OFL_SYNTH_NOTE_DS4 (311.126984f)
#define OFL_SYNTH_NOTE_E4 (329.627557f)
#define OFL_SYNTH_NOTE_F4 (349.228231f)
#define OFL_SYNTH_NOTE_FS4 (369.994423f)
#define OFL_SYNTH_NOTE_G4 (391.995436f)
#define OFL_SYNTH_NOTE_GS4 (415.304698f)
#define OFL_SYNTH_NOTE_A4 (440.000000f)
#define OFL_SYNTH_NOTE_AS4 (466.163762f)
#define OFL_SYNTH_NOTE_B4 (493.883301f)

#define OFL_SYNTH_NOTE_C5 (523.251131f)
#define OFL_SYNTH_NOTE_CS5 (554.365262f)
#define OFL_SYNTH_NOTE_D5 (587.329536f)
#define OFL_SYNTH_NOTE_DS5 (622.253967f)
#define OFL_SYNTH_NOTE_E5 (659.255114f)
#define OFL_SYNTH_NOTE_F5 (698.456463f)
#define OFL_SYNTH_NOTE_FS5 (739.988845f)
#define OFL_SYNTH_NOTE_G5 (783.990872f)
#define OFL_SYNTH_NOTE_GS5 (830.609395f)
#define OFL_SYNTH_NOTE_A5 (880.000000f)
#define OFL_SYNTH_NOTE_AS5 (932.327523f)
#define OFL_SYNTH_NOTE_B5 (987.766603f)

#define OFL_SYNTH_NOTE_C6 (1046.50226f)
#define OFL_SYNTH_NOTE_CS6 (1108.73052f)
#define OFL_SYNTH_NOTE_D6 (1174.65907f)
#define OFL_SYNTH_NOTE_DS6 (1244.50793f)
#define OFL_SYNTH_NOTE_E6 (1318.51023f)
#define OFL_SYNTH_NOTE_F6 (1396.91293f)
#define OFL_SYNTH_NOTE_FS6 (1479.97769f)
#define OFL_SYNTH_NOTE_G6 (1567.98174f)
#define OFL_SYNTH_NOTE_GS6 (1661.21879f)
#define OFL_SYNTH_NOTE_A6 (1760.00000f)
#define OFL_SYNTH_NOTE_AS6 (1864.65505f)
#define OFL_SYNTH_NOTE_B6 (1975.53321f)

#define OFL_SYNTH_NOTE_C7 (2093.00452f)
#define OFL_SYNTH_NOTE_CS7 (2217.46105f)
#define OFL_SYNTH_NOTE_D7 (2349.31814f)
#define OFL_SYNTH_NOTE_DS7 (2489.01587f)
#define OFL_SYNTH_NOTE_E7 (2637.02046f)
#define OFL_SYNTH_NOTE_F7 (2793.82585f)
#define OFL_SYNTH_NOTE_FS7 (2959.95538f)
#define OFL_SYNTH_NOTE_G7 (3135.96349f)
#define OFL_SYNTH_NOTE_GS7 (3322.43758f)
#define OFL_SYNTH_NOTE_A7 (3520.00000f)
#define OFL_SYNTH_NOTE_AS7 (3729.31009f)
#define OFL_SYNTH_NOTE_B7 (3951.06641f)

#define OFL_SYNTH_NOTE_C8 (4186.00904f)
#define OFL_SYNTH_NOTE_CS8 (4434.92210f)
#define OFL_SYNTH_NOTE_D8 (4698.63629f)
#define OFL_SYNTH_NOTE_DS8 (4978.03174f)
#define OFL_SYNTH_NOTE_E8 (5274.04091f)
#define OFL_SYNTH_NOTE_F8 (5587.65170f)
#define OFL_SYNTH_NOTE_FS8 (5919.91076f)
#define OFL_SYNTH_NOTE_G8 (6271.92698f)
#define OFL_SYNTH_NOTE_GS8 (6644.87516f)
#define OFL_SYNTH_NOTE_A8 (7040.00000f)
#define OFL_SYNTH_NOTE_AS8 (7458.62018f)
#define OFL_SYNTH_NOTE_B8 (7902.13282f)

#define OFL_SYNTH_NOTE_C9 (8372.01809f)
#define OFL_SYNTH_NOTE_CS9 (8869.84419f)
#define OFL_SYNTH_NOTE_D9 (9397.27257f)
#define OFL_SYNTH_NOTE_DS9 (9956.06348f)
#define OFL_SYNTH_NOTE_E9 (10548.0818f)
#define OFL_SYNTH_NOTE_F9 (11175.3034f)
#define OFL_SYNTH_NOTE_FS9 (11839.8215f)
#define OFL_SYNTH_NOTE_G9 (12543.8540f)
#define OFL_SYNTH_NOTE_GS9 (13289.7503f)
#define OFL_SYNTH_NOTE_A9 (14080.0000f)
#define OFL_SYNTH_NOTE_AS9 (14917.2404f)
#define OFL_SYNTH_NOTE_B9 (15804.2656f)

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
OFL_SYNTH_DEF void ofl_synth_osc_noi(struct ofl_synth *s, float (*f_randf)(void));
OFL_SYNTH_DEF void ofl_synth_osc_sin(struct ofl_synth *s, float freq);
OFL_SYNTH_DEF void ofl_synth_osc_sqr(struct ofl_synth *s, float freq, float duty);
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
enum ofl_synth_fx_filter_type { OFL_SYNTH_FX_FILTER_TYPE_LOWPASS, OFL_SYNTH_FX_FILTER_TYPE_HIGHPASS, OFL_SYNTH_FX_FILTER_TYPE_BANDPASS, OFL_SYNTH_FX_FILTER_TYPE_NOTCH };
OFL_SYNTH_DEF void ofl_synth_fx_filter(struct ofl_synth *s, enum ofl_synth_fx_filter_type t, float cutoff, float q);

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

#ifdef OFL_SYNTH_STATIC
static
#endif
const float ofl_synth_notes[10*12] = {
	16.3515978f,17.3239144f,18.3540480f,19.4454365f,20.6017223f,21.8267645f,23.1246514f,24.4997147f,25.9565436f,27.5000000f,29.1352351f,30.8677063f,
	32.7031957f,34.6478289f,36.7080960f,38.8908730f,41.2034446f,43.6535289f,46.2493028f,48.9994295f,51.9130872f,55.0000000f,58.2704702f,61.7354127f,
	65.4063913f,69.2956577f,73.4161920f,77.7817459f,82.4068892f,87.3070579f,92.4986057f,97.9988590f,103.826174f,110.000000f,116.540940f,123.470825f,
	130.812783f,138.591315f,146.832384f,155.563492f,164.813778f,174.614116f,184.997211f,195.997718f,207.652349f,220.000000f,233.081881f,246.941651f,
	261.625565f,277.182631f,293.664768f,311.126984f,329.627557f,349.228231f,369.994423f,391.995436f,415.304698f,440.000000f,466.163762f,493.883301f,
	523.251131f,554.365262f,587.329536f,622.253967f,659.255114f,698.456463f,739.988845f,783.990872f,830.609395f,880.000000f,932.327523f,987.766603f,
	1046.50226f,1108.73052f,1174.65907f,1244.50793f,1318.51023f,1396.91293f,1479.97769f,1567.98174f,1661.21879f,1760.00000f,1864.65505f,1975.53321f,
	2093.00452f,2217.46105f,2349.31814f,2489.01587f,2637.02046f,2793.82585f,2959.95538f,3135.96349f,3322.43758f,3520.00000f,3729.31009f,3951.06641f,
	4186.00904f,4434.92210f,4698.63629f,4978.03174f,5274.04091f,5587.65170f,5919.91076f,6271.92698f,6644.87516f,7040.00000f,7458.62018f,7902.13282f,
	8372.01809f,8869.84419f,9397.27257f,9956.06348f,10548.0818f,11175.3034f,11839.8215f,12543.8540f,13289.7503f,14080.0000f,14917.2404f,15804.2656f,
};

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

OFL_SYNTH_DEF void ofl_synth_osc_noi(struct ofl_synth *s, float (*f_randf)(void))
{
    float *b = s->buf + s->buf_off;
    for (float *e = b + s->buf_len; b != e;) *b++ = f_randf();
}

OFL_SYNTH_DEF void ofl_synth_osc_sin(struct ofl_synth *s, float freq)
{
    float f = freq * s->samplingrate_i * OFL_SYNTH_2PI;
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i) *b++ = sinf(i * f);
}

OFL_SYNTH_DEF void ofl_synth_osc_sqr(struct ofl_synth *s, float freq, float duty)
{
    float f = freq * s->samplingrate_i * 2;
    float *b = s->buf + s->buf_off;
    for (int i = 0; i < s->buf_len; ++i) *b++ = fmodf(i*f, 2) < duty ? 1 : -1;
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
    for (float *e = b + s->buf_len; b != e;) *b++ *= f;
}

OFL_SYNTH_DEF void ofl_synth_fx_pow(struct ofl_synth *s, float e)
{
    float *b = s->buf + s->buf_off;
    for (float *d = b + s->buf_len; b != d; ++b) *b = *b < 0 ? -powf(-*b, e) : powf(*b, e);
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

// RBJ's cookbook
OFL_SYNTH_DEF void ofl_synth_fx_filter(struct ofl_synth *s, enum ofl_synth_fx_filter_type t, float cutoff, float q)
{
    float w = OFL_SYNTH_2PI * cutoff * s->samplingrate_i;
    float cw = cosf(w), sw = sinf(w);
    float a = sw / (2*q);
    float b0, b1, b2, a0, a1, a2;
    a0 = 1+a; a1 = -2*cw; a2 = 1-a;
    switch (t)
    {
        case OFL_SYNTH_FX_FILTER_TYPE_LOWPASS: b1 = 1-cw; b0 = b2 = 0.5f * b1; break;
        case OFL_SYNTH_FX_FILTER_TYPE_HIGHPASS: b1 = -1-cw; b0 = b2 = -0.5f * b1; break;
        case OFL_SYNTH_FX_FILTER_TYPE_BANDPASS: b1 = 0; b0 = 0.5f*sw; b2 = -b0; break;
        default: b0 = b2 = 1; b1 = -2*cw; break;
    }
    float c1 = b0/a0, c2 = b1/a0, c3 = b2/a0, c4 = -a1/a0, c5 = -a2/a0;
    float x[2] = { 0 }, y[2] = { 0 };
    float *b = s->buf + s->buf_off;
    for (float *e = b + s->buf_len; b != e; ++b)
    {
        float v = *b;
        float f = c1*v + c2*x[1] + c3*x[0] + c4*y[1] + c5*y[0];
        *b = f;
        x[0] = x[1]; x[1] = v;
        y[0] = y[1]; y[1] = f;
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

