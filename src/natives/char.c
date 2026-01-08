
# include "include/natives/char.h"

# include <malloc.h>
# include <math.h>

jsl_char_workspace_t * jsl_construct_char_workspace(const char * vector, size_t length)
{
    jsl_char_workspace_t * new_space = (jsl_char_workspace_t *)malloc(sizeof(jsl_char_workspace_t));
    new_space->vector = vector;
    new_space->length = length;
    jsl_calculate_char_workspace_stats(new_space);
    return new_space;
}


void jsl_calculate_char_workspace_stats(jsl_char_workspace_t * W)
{
    W->mean = jsl_char_stats_mean(W->vector, W->length, 1);
    W->variance = jsl_char_stats_variance_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->stddev = jsl_char_stats_stddev_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->tss = jsl_char_stats_tss_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->absdev = jsl_char_stats_absdev_fixed(W->vector, W->length, 1, (const double)W->mean);
    W->skew = jsl_char_stats_skew_fixed(W->vector, W->length, 1, (const double)W->mean, (const double)W->stddev);
    W->kurtosis = jsl_char_stats_kurtosis_fixed(W->vector, W->length, 1, (const double)W->mean, (const double)W->stddev);
    W->lag1_auto = jsl_char_stats_lag1_auto_fixed(W->vector, W->length, 1, (const double)W->mean);
}


void jsl_destruct_char_workspace(jsl_char_workspace_t * W) { free(W); }

double jsl_char_stats_mean(const char vector[], size_t length, size_t step)
{
    double mu = 0;
    for (size_t i = 0; i < length; i++)
        mu += (vector[i * step] - mu) / (i + 1);
    return mu;       
}

double jsl_char_stats_variance(const char vector[], size_t length, size_t step)
{
    double mu = jsl_char_stats_mean(vector, length, step);
    double var = 0;

    for (size_t i = 0; i < length; i++)
        var += pow(vector[i * step] - mu, 2);

    var /= (length - 1);
    return var;
}


double jsl_char_stats_stddev(const char vector[], size_t length, size_t step)
{
    double var = jsl_char_stats_variance(vector, length, step);
    return sqrt(var);
}


double jsl_char_stats_tss(const char vector[], size_t length, size_t step)
{
    double mu = jsl_char_stats_mean(vector, length, step);
    double tss = 0;

    for (size_t i = 0; i < length; i++)
        tss += pow(vector[step * i] - mu, 2);
    
    return tss;
}

double jsl_char_stats_absdev(const char vector[], size_t length, size_t step)
{
    double mu = jsl_char_stats_mean(vector, length, step);
    double absdev = 0;

    double term;
    for (size_t i = 0; i < length; i++)
    {
        term = vector[i * step] - mu;
        if (term < 0)
            term *= -1;
        absdev += term;
    }

    absdev /= length;
    return absdev;
}


double jsl_char_stats_skew(const char vector[], size_t length, size_t step)
{
    double mu = jsl_char_stats_skew(vector, length, step);
    double std = jsl_char_stats_stddev_fixed(vector, length, step, mu);
    double skew = 0;
    
    for (size_t i = 0; i < length; i++)
        skew += pow((vector[i * step] - mu) / std, 3);
    skew /= length;

    return skew;
}


double jsl_char_stats_kurtosis(const char vector[], size_t length, size_t step)
{
    double mu = jsl_char_stats_mean(vector, length, step);
    double std = jsl_char_stats_stddev_fixed(vector, length, step, mu);
    double kurt = 0;

    for (size_t i = 0; i < length; i++)
        kurt += pow((vector[i * step] - mu) / std, 4);
    kurt = (kurt / length) - 3;

    return kurt;
}


double jsl_char_stats_lag1_auto(const char vector[], size_t length, size_t step)
{
    double mu = jsl_char_stats_mean(vector, length, step);
    
    double numer = 0;
    double denom = 0;

    for (size_t i = 0; i < length; i++)
    {
        denom += pow(vector[i * step] - mu, 2);
        if (i >= 1)
            numer += (vector[i * step] - mu) * (vector[(i - 1) * step] - mu);
    }

    return (numer / denom);
}